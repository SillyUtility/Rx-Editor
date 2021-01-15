//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSFormatter.h>

#import <Foundation/NSSecureCoding-Protocol.h>

@class NSLocale, NSNumberFormatter;

__attribute__((visibility("hidden")))
@interface NSUnitFormatter : NSFormatter <NSSecureCoding>
{
    NSNumberFormatter *_numberFormatter;
    unsigned long long _unitOptions;
    long long _unitStyle;
    struct UAMeasureFormat *_formatter;
    struct UPluralRules *_prules;
    BOOL _modified;
    NSLocale *_locale;
}

+ (BOOL)supportsSecureCoding;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)stringFromUnit:(id)arg1;
- (id)unitStringFromValue:(double)arg1 unit:(unsigned long long)arg2;
- (id)stringForValue1:(double)arg1 unit1:(unsigned long long)arg2 value2:(double)arg3 unit2:(unsigned long long)arg4;
- (id)stringForValue:(double)arg1 unit:(unsigned long long)arg2;
- (id)stringForObjectValue:(id)arg1;
- (void)checkIfModified;
- (int)_determineUnitsToFormat:(int *)arg1 fromMeasurement:(id)arg2;
@property(copy) NSLocale *locale;
@property long long unitStyle;
@property unsigned long long unitOptions;
@property(copy) NSNumberFormatter *numberFormatter;
- (void)dealloc;
- (id)init;

@end

