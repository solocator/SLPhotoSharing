//
//  SLAppDataPackage.h
//  SLPhotoSharing
//
//  Created by Civi Corp Pty Ltd on 4/13/18.
//  Copyright © 2018 Civi Corp Pty Ltd. All rights reserved.
//

//const

#import <SLPhotoSharing/SLCoding.h>

/**
 A data package for the interaction of the client application with the "Solocator" application.
 
 Contains the application master data that sent the package.
 
 And also those that were added in this package.
 
 The data packet is transmitted via the clipboard.
 */
@interface SLAppDataPackage: SLCoding

/// The key containing the key to the data sent from the.
extern NSString * const SLAppDataPackageUTI;

/**
 The property contains the name of the application that sent the data packet.
 */
@property (copy, nonatomic, readonly) NSString *sourceApplicationName;
/**
 The property contains the application bundle identifier of the application that sent the data packet.
 */
@property (copy, nonatomic, readonly) NSString *sourceApplicationIdentifier;
/**
 The property contains the application version of the application that sent the data packet.
 */
@property (copy, nonatomic, readonly) NSString *sourceApplicationVersion;
/**
 The property contains the application build of the application that sent the data packet.
 */
@property (copy, nonatomic, readonly) NSString *sourceApplicationBuild;
/**
 This is a model with data encrypted in to the data.
 */
@property (strong, nonatomic, readonly) NSData *payload;

@end
