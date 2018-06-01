//
//  SLCoding.h
//  SLPhotoSharing
//
//  Created by Civi Corp Pty Ltd on 4/25/18.
//  Copyright © 2018 Civi Corp Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import <CoreGraphics/CGBase.h>

/**
 The parent class of all data packet models.
 
 Used to encrypt outgoing data and decrypt incoming data.
*/
@interface SLCoding : NSObject

/**
 Initializes the receiver for decoding an archive previously encoded by SLCoding.
 
 Decodes and returns an Objective-C object.
 
 Subclasses must override this method if they perform SLCoding.
 
 @attention Use only if the data is encoded using encodeObject: forKey:.
 
 @param data The data archive is encoded with encodeObject: forKey:
 @param key The key with which the data was encoded.
 @return An Objective-C object
 */
- (instancetype)initWithData:(NSData *)data andKey:(NSString *)key;

/**
 Initializes the receiver for decoding an archive previously encoded by SLCoding.
 
 Decodes and returns an Objective-C object.
 
 Subclasses must override this method if they perform SLCoding.

 @attention Use only if the data is encoded using dataRepresentation.
 
 @param data The data archive is encoded with dataRepresentation
 @return An Objective-C object
 */
- (instancetype)modelWithData:(NSData *)data;

/**
 Encodes the object and associates it with the string key.

 Encodes and returns key archived data.
 
 Subclasses must override this method if they perform SLCoding.
 
 @attention Use only if the data is encoded using dataRepresentation.
 
 @return data The data archive is encoded with dataRepresentation
 */
- (NSData *)dataRepresentation;

/**
 Encodes the object and associates it with the string key.
 
 Subclasses must override this method to identify multiple encodings of objv and encode a reference to objv instead.

 @param object An Objective-C object
 @param key the key with which the data was encoded
 @return the data key archive.
 */
- (NSData *)encodeObject:(id)object forKey:(NSString *)key;

/**
 Create SLAppDataPackage model with an encoded SLCoding class
 
 @param payload the data archive is encoded with SLCoding
 
 @return SLAppDataPackage model
 */

- (instancetype)dataPackageForCurrentApplicationWithPayload:(NSData *)payload;

@end
