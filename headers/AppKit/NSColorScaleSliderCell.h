//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSSliderCell.h>

@class NSBitmapImageRep, NSColor;

@interface NSColorScaleSliderCell : NSSliderCell
{
    long long _scaleType;
    NSBitmapImageRep *_scaleBitmap;
    BOOL _scaleBitmapValid;
    NSColor *_scaleColor;
    BOOL _flippedHorizontally;
}

- (void)setColor:(id)arg1;
- (void)setDrawsTrackAsColorScaleType:(long long)arg1;
- (BOOL)isOpaque;
- (void)drawBarInside:(struct CGRect)arg1 flipped:(BOOL)arg2;
- (struct CGRect)knobRectFlipped:(BOOL)arg1;
- (void)drawTickMarks;
- (struct CGRect)rectOfTickMarkAtIndex:(long long)arg1;
- (void)_computeColorScaleIfNecessaryWithSize:(struct CGSize)arg1;
@property BOOL flippedHorizontally;

@end

