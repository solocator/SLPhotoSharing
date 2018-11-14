//
//  SLPhotoReceiver.h
//  SLPhotoSharing
//
//  Created by Civi Corp Pty Ltd on 3/30/18.
//  Copyright © 2018 Civi Corp Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SLPhotoSharing/SLRequestModel.h>
#import <SLPhotoSharing/SLResponseModel.h>

typedef NS_ENUM(NSUInteger, SolocatorApp) {
    SolocatorAppAS = 0,
    SolocatorAppVPP
};

/**
 The delegate of a SLPhotoReceiver object must adopt the SLPhotoReceiverDelegate protocol.
 */
@protocol SLPhotoReceiverDelegate <NSObject>

/**
 The method is called when the receiver got the response model.
 @param responseModel the model with respons objects
 */
- (void)solocatorDataReceiverDidReceiveResponseModel:(SLResponseModel *)responseModel;

@end

/**
 The completion block for sending data to another application.
 
 @param sent 'YES' if the data was sent successfully, or 'NO' if an error occurred while opening the application.
 @param error The error contains a message describing the reason for the failure of sending the data.
 */
typedef void(^SLPhotoReceiverCompletionHandler)(BOOL sent, NSError *error);


/**
 SLPhotoReceiver it is a class that is responsible for communicating with the Solosator application.
 Namely for receiving the data sent by the Solocator.
 
 Сlass contains the delegate "SLPhotoReceiverDelegate" which was described above.
 
 Method - (BOOL)solocatorDataReceivedInURL:(NSURL *)url; determines that the application is open from the Solocator application, and the scheme contains the response information.
 */
@interface SLPhotoReceiver : NSObject
/**
 The object that acts as the delegate of the SLPhotoReceiver.
 The delegate must adopt the SLPhotoReceiverDelegate protocol.
 **/
@property (nonatomic, strong) id <SLPhotoReceiverDelegate> delegate;

/**
 responseModel the model with response objects
 */
@property (nonatomic, strong) SLResponseModel *responseModel;

/**
 Singleton object of SLPhotoReceiver.
 */
+ (SLPhotoReceiver *)sharedObject;

/**
 *  Initialize the data packet when the link opens the application contains the data of the solotator
 *  @param url The URL resource to open. This resource can be a network resource or a file. For information about the Apple-registered URL schemes, see Apple URL Scheme Reference.
 *  @result YES if the SLPhotoReceiver successfully handled the request or NO if the attempt to open the URL resource failed.
 */
- (BOOL)solocatorDataReceivedInURL:(NSURL *)url;

/**
 *  This function opens Solocator application with incoming parameters.
 *  @param requestModel The model contains the parameters required for opening a "Solocator" application.
 *  @param completionHandler is returned upon success or an error in opening the "Solocator" application.
 */
- (void)openSolocatorApp:(SolocatorApp)appType with:(SLRequestModel *)requestModel completionHandler:(void(^)(BOOL sent, NSError *error))completionHandler;

@end

