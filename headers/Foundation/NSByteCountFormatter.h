//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSFormatter.h>

#import <Foundation/NSObservable-Protocol.h>
#import <Foundation/NSObserver-Protocol.h>

@class NSString;

@interface NSByteCountFormatter : NSFormatter <NSObservable, NSObserver>
{
    unsigned int _allowedUnits;
    BOOL _countStyle;
    BOOL _allowsNonnumericFormatting;
    BOOL _includesUnit;
    BOOL _includesCount;
    BOOL _includesActualByteCount;
    BOOL _adaptive;
    BOOL _zeroPadsFractionDigits;
    int _formattingContext;
    int _reserved[5];
}

+ (id)stringFromMeasurement:(id)arg1 countStyle:(long long)arg2;
+ (id)stringFromByteCount:(long long)arg1 countStyle:(long long)arg2;
@property BOOL zeroPadsFractionDigits; // @synthesize zeroPadsFractionDigits=_zeroPadsFractionDigits;
@property(getter=isAdaptive) BOOL adaptive; // @synthesize adaptive=_adaptive;
@property BOOL includesActualByteCount; // @synthesize includesActualByteCount=_includesActualByteCount;
@property BOOL includesCount; // @synthesize includesCount=_includesCount;
@property BOOL includesUnit; // @synthesize includesUnit=_includesUnit;
@property BOOL allowsNonnumericFormatting; // @synthesize allowsNonnumericFormatting=_allowsNonnumericFormatting;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property long long formattingContext;
- (id)init;
- (BOOL)isPartialStringValid:(id *)arg1 proposedSelectedRange:(struct _NSRange *)arg2 originalString:(id)arg3 originalSelectedRange:(struct _NSRange)arg4 errorDescription:(id *)arg5;
- (BOOL)getObjectValue:(out id *)arg1 forString:(id)arg2 errorDescription:(out id *)arg3;
- (id)stringForObjectValue:(id)arg1;
- (BOOL)_mayDecorateAttributedStringForObjectValue:(id)arg1;
- (id)stringFromMeasurement:(id)arg1;
- (id)stringFromByteCount:(long long)arg1;
- (unsigned long long)_options;
@property long long countStyle;
@property unsigned long long allowedUnits;
- (void)receiveObservedValue:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

