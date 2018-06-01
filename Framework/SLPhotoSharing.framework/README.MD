---
title: Solocator Data Share

language_tabs:
- objective_c: Objective – C
- swift: Swift


toc_footers:
- <a href='http://solocator.com/'>Solocator web page</a>
- <a href='https://github.com/lord/slate'>Documentation Powered by Slate</a>

search: true
---

# Quickstart

So what you must do to integrate communications with Solocator?

## **1. Framework installation**

In order to add the SLPhotoSharing framework please follow next steps:

1. Select your project in the Project Navigator.
2. Select your target.
3. Select the "General" tab.
4. Open "Embedded Binaries" expander.
5. Click the + button.
6. Select the SLPhotoSharing framework.

![ ](/images/Screen_Shot_1.png)

<aside class="warning">
If you are facing the problem of using the library in a Swift project, you need to do the following:
</aside>

Create a Swift Bridging Header file in that project. The best way is to create the .h file Manually.

First, add a header file to your project with the name: MyProjectName-Bridging-Header.h. This will be the single header file where you import any Objective C code you need your Swift code to have access.

> Bridging-Header for swift project:

<!--```objective_c-->
<!---->
<!--```-->

```swift
#ifndef MyProjectName_Bridging_Header_h
#define MyProjectName_Bridging_Header_h

#import <SLPhotoSharing/SLPhotoSharing.h>

#endif /* MyProjectName_Bridging_Header_h */
```

Find `Swift Compiler - General` section in your project build settings. Add the path to your bridging header file next to `Objective-C Bridging Header` from the project root folder. It should be MyProjectName/MyProjectName-Bridging-Header.h

![ ](/images/Screen_Shot_2.png)

<aside class="notice">
You must use your own project name instead of <code>"MyProjectName"</code> .
Or don't use prefix with your project name. This is just a recommendation.
</aside>

Finally. Clean and build the project.

## **2. Configure Your info.plist**

Configure the information property list file (info.plist) with an XML snippet that contains data about your app.
1. Right-click info.plist, and choose Open As Source Code.
2. Copy and paste the following XML snippet into the body of your file ( `<dict>...</dict>`).

> Folowing code must be in Your project's info.plist:

```xml
<key>CFBundleURLTypes</key>
<array>
<dict>
<key>CFBundleTypeRole</key>
<string>Editor</string>
<key>CFBundleURLSchemes</key>
<array>
<string> "URL Scheme of your application" </string>
</array>
</dict>
</array>
```

> Make sure to replace `"URL Scheme of your application"` with Your application url scheme.

<aside class="notice">
*Note that Solocator can open any URL Scheme only in iOS 10 and above. If you are building with an older version of the iOS SDK, you need to tell your URLScheme to the developers of the Solocator application.* 
</aside>

<aside class="warning">
You must replace <code>"URL Scheme of your application"</code> with Your application url scheme.
</aside>

3. To use file sharing dialog your application's info.plist also needs to include:

> Folowing code must be in Your project's info.plist:

```xml
<key>LSApplicationQueriesSchemes</key>
<array>
<string>Solocator-2.0</string>
</array>
```

> It's optional if you use iOS 10 and above


## **3. Connect Your App Delegate**

To add the following code, first import SLPhotoReceiver class into your project class:

> Import SLPhotoReceiver class into your app delegate:

```swift 
Nothing needs to be done. Everything is connected in the Bridging_Header file.
```

```objective_c
#import <SLPhotoSharing/SLPhotoReceiver.h>
```

> Add the following to your *AppDelegate* class:

```objective_c
- (BOOL)application:(UIApplication *)application 
openURL:(NSURL *)url 
options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
BOOL handled = [[SLPhotoReceiver sharedObject] solocatorDataReceivedInURL:url];
// Add any custom logic here.
return handled;
}
```

```swift 
func application(_ app: UIApplication, open url: URL, options: [UIApplicationOpenURLOptionsKey : Any] = [:]) -> Bool {
let handled = SLPhotoReceiver.sharedObject().solocatorDataRecived(in: url)
// do whatever you want
return handled
}
```

<aside class="notice">
Note that <code> application:openURL:options:</code> is only available in iOS 10 and above. If you are building with an older version of the iOS SDK, you can use:
</aside>

> Add the following to your *AppDelegate* class:

```objective_c
- (BOOL)application:(UIApplication *)application 
openURL:(NSURL *)url 
sourceApplication:(NSString *)sourceApplication
annotation:(id)annotation {
BOOL handled = [[SLPhotoReceiver sharedObject] solocatorDataReceivedInURL:url];
// Add any custom logic here.
return handled;
}
```

```swift 
func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any) -> Bool {
let handled = SLPhotoReceiver.sharedObject().solocatorDataRecived(in: url)
// do whatever you want
return handled
}
```

## **4. Add SL photo sharing to your code**

To add following code, firstly import SLPhotoReceiver class in to Your project class:

> Import SLPhotoReceiver class in to your application class: 

```swift 
Nothing needs to be done. Everything is connected in the Bridging_Header file.
```

```objective_c
#import <SLPhotoSharing/SLPhotoReceiver.h>
```


To open the application, you need to write the following code.

> Example

```objective_c
@interface ViewController () <SLPhotoReceiverDelegate>

...

[[SLPhotoReceiver sharedObject] setDelegate:self];

...

SLRequestModel *model = [SLRequestModel new];
[model setSourceURLShceme:@"<Your Application's URL Scheme>"];
[[SLPhotoReceiver sharedObject] openSolocatorWith:model completionHandler:^(BOOL sent, NSError *error) {

}];
```

```swift
class ViewController: UIViewController, SLPhotoReceiverDelegate {

...

SLPhotoReceiver.sharedObject().delegate = self

...

let model = SLRequestModel()
model.sourceURLShceme = "<Your Application's URL Scheme>"
SLPhotoReceiver.sharedObject().openSolocator(with: model) { (sent, error) in

}

...

}
```

In order to receive the incoming information immediately after the response, you can use the SLPhotoReceiverDelegate method.
SLPhotoReceiverDelegate includes one method that returns a response model.

> Delegate method: 

```swift
func solocatorDataReceiverDidReceive(_ responseModel: SLResponseModel!)
```

```objective_c
- (void)SolocatorDataReceiverDidReceiveResponseModel:(SLResponseModel *)responseModel;
```

>  The SLResponseModel is described below.


<aside class="success">
Description of the classes is in the next section.
</aside>

# SL Photo Sharing Classes 

For those who want more information.

## SLPhotoReceiver

SLPhotoReceiver it is a singleton class that is responsible for communication between your application and the Solosator application. Namely for receiving the data sent by the Solocator.

Сlass contains the delegate "SLPhotoReceiverDelegate" which was described above.

Method `- (BOOL)solocatorDataReceivedInURL:(NSURL *)url;` determines that the application is open from the Solocator application, and the scheme contains the response information. 


## SLRequestModel

The model that will be sent to the Solosator applications in response to what the Solocator can transmit information.
A simple model that contains the address of the recipient.

**It is important to set the sourceScheme!**

## SLResponseModel

A simple response model that contains many information:

Property | Type | Description
--------- | ----------- | -----------
image | UIImage | Received photo.
date | NSDate | Date of photo taken
exifData | NSData | Exchangeable Image File Format data
projectName | NSString | Name of project on photo 
watermark | NSString | User watermark
descriptions | NSString | User descriptions 
headingElevation | NSString | 
locality| NSString |
pos | NSString |
altitude | CGFloat |
bearing | CGFloat |
latitude | CGFloat |
longitude | CGFloat |
accuracy | CGFloat |
distance | CGFloat |
metricUnits | BOOL | Yes if user uses metric units 
trueNorth | BOOL | 
canceled | BOOL | Yes if the user has canceled the shipment. When property canceled equals to YES then all properties contains nil.

