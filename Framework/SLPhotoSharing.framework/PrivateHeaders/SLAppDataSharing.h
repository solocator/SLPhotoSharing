//
//  SLAppDataSharing.h
//  SLPhotoSharing
//
//  Created by Developer on 4/13/18.
//  Copyright © 2018 Evgen Litvinenko. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SLAppDataPackage;

/**
 The completion block for sending data to another application.
 
 @param sent 'YES' if the data was sent successfully, or 'NO' if an error occurred while opening the application.
 @param error The error contains a message describing the reason for the failure of sending the data.
 */
typedef void(^SLAppDataPackageSendDataHandler)(BOOL sent, NSError *error);

typedef NS_ENUM(NSUInteger, SLAppDataSharingErrorType) {
    /// `SLAppDataSharingErrorTypeNoApplicationAvailableForScheme` no application found for the defined scheme
    SLAppDataSharingErrorTypeNoApplicationAvailableForScheme = 100,
    /// `SLAppDataSharingErrorTypeNoСlipboardForName` not found the clipboard for the key sent from the application "Solicator"
    SLAppDataSharingErrorTypeNoClipboardForName = 200,
    /// `SLAppDataSharingErrorTypeNoDataFound` not found any data from URL
    SLAppDataSharingErrorTypeNoDataFound = 300,
};

/**
 A class that provides application interaction through the URL scheme.
 This class is a private class of the framework.
*/
@interface SLAppDataSharing : NSObject

/**
 This function sends data from a data packet to another application on the RLC scheme.
 
 @attention If applicatiopn use iOS 9 
 Folowing code must be in Your project's info.plist:
 <key>LSApplicationQueriesSchemes</key>
 <array>
 <string>Solocator</string>
 </array>
 @param scheme URL scheme to application
 @param dataPackage model with data on package
 @param completionHandler The completion block for sending data to another application.
 */
+ (void)sendDataToApplicationWithScheme:(NSString *)scheme
                           dataPackage:(SLAppDataPackage *)dataPackage
                     completionHandler:(SLAppDataPackageSendDataHandler)completionHandler;

/**
 
 */
+ (SLAppDataPackage *)handleSendPasteboardDataURL:(NSURL *)sendPasteboardDataURL
                                            error:(NSError **)error;

@end
