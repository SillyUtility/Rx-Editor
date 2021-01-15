//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSColor.h>

@class NSGradient;

__attribute__((visibility("hidden")))
@interface NSGradientColor : NSColor
{
    NSGradient *_gradient;
    struct CGImage *_patternImageRef;
    struct CGRect _destRect;
    struct CGColor *_patternColor;
}

- (struct CGColor *)CGColor;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)description;
- (id)colorUsingType:(long long)arg1;
- (long long)type;
- (id)colorSpaceName;
- (id)colorUsingColorSpaceName:(id)arg1 device:(id)arg2;
- (void)setStroke;
- (void)setFill;
- (void)set;
- (void)_updatePattern;
- (void)_updatePatternImage;
- (void)dealloc;
- (id)initWithGradient:(id)arg1;

@end

