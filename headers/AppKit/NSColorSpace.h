//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSSecureCoding-Protocol.h>

@class NSColorGamut, NSData, NSString;

@interface NSColorSpace : NSObject <NSSecureCoding>
{
    id _profile;
    struct {
        unsigned int colorSpaceID:8;
        unsigned int storageType:3;
        unsigned int replacedDuringUnarchiving:1;
        unsigned int :20;
        unsigned int :32;
    } _flags;
    void *__cgColorSpace;
    void *__cgColorTransform;
    void *_reserved[4];
}

+ (id)availableColorSpacesWithModel:(long long)arg1;
+ (BOOL)supportsSecureCoding;
+ (id)colorSpaceForColorSpaceName:(id)arg1;
+ (id)colorSpaceForCGColorSpace:(struct CGColorSpace *)arg1;
+ (id)_invertedDeviceGrayColorSpace;
+ (id)_invertedGenericGrayColorSpace;
+ (id)extendedLinearSRGBColorSpace;
+ (id)linearSRGBColorSpace;
+ (id)extendedGenericGamma22GrayColorSpace;
+ (id)extendedSRGBColorSpace;
+ (id)DCIP3ColorSpace;
+ (id)displayP3ColorSpace;
+ (id)genericGamma22GrayColorSpace;
+ (id)adobeRGB1998ColorSpace;
+ (id)sRGBColorSpace;
+ (id)deviceCMYKColorSpace;
+ (id)deviceGrayColorSpace;
+ (id)deviceRGBColorSpace;
+ (id)genericCMYKColorSpace;
+ (id)genericGrayColorSpace;
+ (id)genericRGBColorSpace;
+ (id)specialColorSpaceWithID:(int)arg1;
- (struct CGColor *)_newCGColorByConvertingCGColor:(struct CGColor *)arg1;
- (id)awakeAfterUsingCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)colorSpaceName;
@property(readonly, copy) NSString *localizedName;
- (id)description;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (BOOL)isWideGamut;
- (BOOL)allowsExtendedRange;
- (BOOL)_isDeviceColorSpace;
@property(readonly) long long colorSpaceModel;
@property(readonly) long long numberOfColorComponents;
- (id)colorProfile;
- (int)_colorSpaceID;
@property(readonly) void *colorSyncProfile;
@property(readonly) struct CGColorSpace *CGColorSpace;
- (void)_createProfileFor:(struct __CFString *)arg1;
@property(readonly) NSData *ICCProfileData;
- (void)dealloc;
- (id)initWithColorSyncProfile:(void *)arg1;
- (id)initWithICCProfileData:(id)arg1;
- (id)initWithCGColorSpace:(struct CGColorSpace *)arg1;
- (id)_initWithCGColorSpaceNoCache:(struct CGColorSpace *)arg1;
- (id)initWithColorProfile:(id)arg1;
@property(readonly) NSColorGamut *colorGamut;

@end

