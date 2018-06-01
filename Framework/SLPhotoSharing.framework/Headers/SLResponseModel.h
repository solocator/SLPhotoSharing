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

extern NSString * const SLResponseKey;
extern NSString * const SLImage;
extern NSString * const SLDate;
extern NSString * const SLExifData;
extern NSString * const SLProjectName;
extern NSString * const SLWatermark;
extern NSString * const SLDescriptions;
extern NSString * const SLHeadingElevation;
extern NSString * const SLLocality;
extern NSString * const SLPos;
extern NSString * const SLAltitude;
extern NSString * const SLBearing;
extern NSString * const SLLatitude;
extern NSString * const SLLongitude;
extern NSString * const SLAccuracy;
extern NSString * const SLDistance;
extern NSString * const SLMetricUnits;
extern NSString * const SLTrueNorth;
extern NSString * const SLCanceled;

@property (nullable, nonatomic, strong, readonly) UIImage *image;
@property (nullable, nonatomic, strong, readonly) NSDate *date;
@property (nullable, nonatomic, strong, readonly) NSData *exifData;
@property (nullable, nonatomic, strong, readonly) NSString *projectName;
@property (nullable, nonatomic, strong, readonly) NSString *watermark;
@property (nullable, nonatomic, strong, readonly) NSString *descriptions;
@property (nullable, nonatomic, strong, readonly) NSString *headingElevation;
@property (nullable, nonatomic, strong, readonly) NSString *locality;
@property (nullable, nonatomic, strong, readonly) NSString *pos;
@property (nonatomic, assign, readonly) CGFloat altitude;
@property (nonatomic, assign, readonly) CGFloat bearing;
@property (nonatomic, assign, readonly) CGFloat latitude;
@property (nonatomic, assign, readonly) CGFloat longitude;
@property (nonatomic, assign, readonly) CGFloat accuracy;
@property (nonatomic, assign, readonly) CGFloat distance;
@property (nonatomic, assign, readonly) BOOL metricUnits;
@property (nonatomic, assign, readonly) BOOL trueNorth;
@property (nonatomic, assign, readonly) BOOL canceled;

- (instancetype)initWith:(NSDictionary *)dict;

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
