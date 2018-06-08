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
@interface SLResponseModel : SLCoding

/// Key for response key
extern NSString * const SLResponseKey;
/// Key for image
extern NSString * const SLImage;
/// Key for date
extern NSString * const SLDate;
/// Key for exif data
extern NSString * const SLExifData;
/// Key for project name
extern NSString * const SLProjectName;
/// Key for watermark
extern NSString * const SLWatermark;
/// Key for descriptions
extern NSString * const SLDescriptions;
/// Key for heading elevation
extern NSString * const SLHeadingElevation;
/// Key for locality
extern NSString * const SLLocality;
/// Key for pos
extern NSString * const SLPos;
/// Key for altitude
extern NSString * const SLAltitude;
/// Key for bearing
extern NSString * const SLBearing;
/// Key for latitude
extern NSString * const SLLatitude;
/// Key for longitude
extern NSString * const SLLongitude;
/// Key for accuracy
extern NSString * const SLAccuracy;
/// Key for distance
extern NSString * const SLDistance;
/// Key for metric units
extern NSString * const SLMetricUnits;
/// Key for true north
extern NSString * const SLTrueNorth;
/// Key for canceled
extern NSString * const SLCanceled;

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
- (instancetype)initWith:(NSDictionary *)dict;

/**
 Initialize model from all photo components
 */
- (instancetype)initWithImage:(UIImage *)image
                         date:(NSDate *)date
                     exifData:(NSData *)exifData
                  projectName:(NSString *)projectName
                    watermark:(NSString *)watermark
                 descriptions:(NSString *)descriptions
             headingElevation:(NSString *)headingElevation
                     locality:(NSString *)locality
                          pos:(NSString *)pos
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
