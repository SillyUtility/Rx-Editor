//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

@class NSColor;

__attribute__((visibility("hidden")))
@interface NSRoundedDashStrokeView : NSView
{
    double _cornerRadius;
    double _lineDash;
    double _strokeThickness;
    NSColor *_dashColor;
    NSColor *_innerDashColor;
}

+ (id)keyPathsForValuesInvalidatingDisplay;
@property(copy) NSColor *innerDashColor; // @synthesize innerDashColor=_innerDashColor;
@property(copy) NSColor *dashColor; // @synthesize dashColor=_dashColor;
@property double strokeThickness; // @synthesize strokeThickness=_strokeThickness;
@property double lineDash; // @synthesize lineDash=_lineDash;
@property double cornerRadius; // @synthesize cornerRadius=_cornerRadius;
- (void)drawRect:(struct CGRect)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end

