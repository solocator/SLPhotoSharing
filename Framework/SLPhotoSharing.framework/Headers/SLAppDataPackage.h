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

extern NSString * const SLAppDataPackageUTI;

@property (copy, nonatomic, readonly) NSString *sourceApplicationName;
@property (copy, nonatomic, readonly) NSString *sourceApplicationIdentifier;
@property (copy, nonatomic, readonly) NSString *sourceApplicationVersion;
@property (copy, nonatomic, readonly) NSString *sourceApplicationBuild;
@property (strong, nonatomic, readonly) NSData *payload;

@end
