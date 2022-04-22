//
//  SLResponseModel.h
//  SLPhotoSharing
//
//  Created by Civi Corp Pty Ltd on 4/13/18.
//  Copyright © 2018 Civi Corp Pty Ltd. All rights reserved.
//

#import <SLPhotoSharing/SLCoding.h>

/**
 A data model containing all the data of the photo taken in the "Solocator" application.
*/
@interface SLResponseModel : SLCoding <NSSecureCoding>

/// Key for response key
extern NSString * _Nonnull const SLResponseKey;
/// Key for image
extern NSString * _Nonnull const SLImage;
/// Key for date
extern NSString * _Nonnull const SLDate;
/// Key for exif data
extern NSString * _Nonnull const SLExifData;
/// Key for project name
extern NSString * _Nonnull const SLProjectName;
/// Key for watermark
extern NSString * _Nonnull const SLWatermark;
/// Key for descriptions
extern NSString * _Nonnull const SLDescriptions;
/// Key for heading elevation
extern NSString * _Nonnull const SLHeadingElevation;
/// Key for locality
extern NSString * _Nonnull const SLLocality;
/// Key for pos
extern NSString * _Nonnull const SLPos;
/// Key for altitude
extern NSString * _Nonnull const SLAltitude;
/// Key for bearing
extern NSString * _Nonnull const SLBearing;
/// Key for latitude
extern NSString * _Nonnull const SLLatitude;
/// Key for longitude
extern NSString * _Nonnull const SLLongitude;
/// Key for accuracy
extern NSString * _Nonnull const SLAccuracy;
/// Key for distance
extern NSString * _Nonnull const SLDistance;
/// Key for metric units
extern NSString * _Nonnull const SLMetricUnits;
/// Key for true north
extern NSString * _Nonnull const SLTrueNorth;
/// Key for canceled
extern NSString * _Nonnull const SLCanceled;

/// Received photograph.
@property (nullable, nonatomic, strong, readonly) UIImage *image;
/// Date of photo taken
@property (nullable, nonatomic, strong, readonly) NSDate *date;
/// Exchangeable Image File Format data
@property (nullable, nonatomic, strong, readonly) NSData *exifData;
/// Photo project name
@property (nullable, nonatomic, strong, readonly) NSString *projectName;
/// photo watermark string
@property (nullable, nonatomic, strong, readonly) NSString *watermark;
/// photo descriptions string
@property (nullable, nonatomic, strong, readonly) NSString *descriptions;
/// photo heading elevation string
@property (nullable, nonatomic, strong, readonly) NSString *headingElevation;
/// photo location string
@property (nullable, nonatomic, strong, readonly) NSString *locality;
/// photo pos string
@property (nullable, nonatomic, strong, readonly) NSString *pos;
/// photo altitude
@property (nonatomic, assign, readonly) CGFloat altitude;
/// photo bearing
@property (nonatomic, assign, readonly) CGFloat bearing;
/// photo latitude
@property (nonatomic, assign, readonly) CGFloat latitude;
/// photo longitude
@property (nonatomic, assign, readonly) CGFloat longitude;
/// photo accuracy
@property (nonatomic, assign, readonly) CGFloat accuracy;
/// photo distance
@property (nonatomic, assign, readonly) CGFloat distance;
/// will be set to yes if the user uses units
@property (nonatomic, assign, readonly) BOOL metricUnits;
/// Photo created with true north option
@property (nonatomic, assign, readonly) BOOL trueNorth;
/// will be set to yes if the user has canceled the shipment. When property canceled equals to YES then all properties contains nil.
@property (nonatomic, assign, readonly) BOOL canceled;

/**
 Initialize model from dictionary.
 @attention
 Dictionary must contains defined keys such as:
 
 SLImage
 
 SLDate
 
 SLExifData
 
 SLProjectName
 
 SLWatermark
 
 SLDescriptions
 
 SLHeadingElevation
 
 SLLocality
 
 SLPos
 
 SLAltitude
 
 SLBearing
 
 SLLatitude
 
 SLLongitude
 
 SLAccuracy
 
 SLDistance
 
 SLMetricUnits
 
 SLTrueNorth
 
 SLCanceled
 */
- (instancetype _Nonnull)initWith:(NSDictionary *_Nonnull)dict;

/**
 Initialize model from all photo components
 */
- (instancetype _Nonnull)initWithImage:(UIImage *_Nullable)image
                         date:(NSDate *_Nullable)date
                     exifData:(NSData *_Nullable)exifData
                  projectName:(NSString *_Nullable)projectName
                    watermark:(NSString *_Nullable)watermark
                 descriptions:(NSString *_Nullable)descriptions
             headingElevation:(NSString *_Nullable)headingElevation
                     locality:(NSString *_Nullable)locality
                          pos:(NSString *_Nullable)pos
                     altitude:(CGFloat) altitude
                      bearing:(CGFloat) bearing
                     latitude:(CGFloat) latitude
                    longitude:(CGFloat) longitude
                     accuracy:(CGFloat) accuracy
                     distance:(CGFloat) distance
                  metricUnits:(BOOL) metricUnits
                    trueNorth:(BOOL) trueNorth
                     canceled:(BOOL) canceled;

@end
