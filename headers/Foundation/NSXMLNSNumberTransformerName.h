//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSValueTransformer.h>

@class NSNumberFormatter;

__attribute__((visibility("hidden")))
@interface NSXMLNSNumberTransformerName : NSValueTransformer
{
    NSNumberFormatter *_formatter;
}

+ (BOOL)allowsReverseTransformation;
+ (Class)transformedValueClass;
- (void)dealloc;
- (id)transformedValue:(id)arg1;
- (id)_oldTransformedValue:(id)arg1;
- (id)init;

@end

