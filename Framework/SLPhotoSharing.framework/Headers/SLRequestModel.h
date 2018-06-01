//
//  SLRequestModel.h
//  SLPhotoSharing
//
//  Created by Civi Corp Pty Ltd on 4/13/18.
//  Copyright © 2018 Civi Corp Pty Ltd. All rights reserved.
//

#import <SLPhotoSharing/SLCoding.h>

/**
 A model that contains data for requesting images and other data from the "Solocator" application.
 */
@interface SLRequestModel : SLCoding

/// URL Scheme of your application, link to your application that you specified in the CFBundleURLTypes
@property (nonatomic, strong) NSString *sourceURLShceme;

@end
