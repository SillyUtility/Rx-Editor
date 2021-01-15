//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSAnimation.h>

@class NSWindow;

__attribute__((visibility("hidden")))
@interface NSWindowScaleAnimation : NSAnimation
{
    NSWindow *_window;
    double _startScale;
    double _endScale;
    long long _tag;
}

@property long long tag; // @synthesize tag=_tag;
@property double endScale; // @synthesize endScale=_endScale;
@property double startScale; // @synthesize startScale=_startScale;
@property(retain) NSWindow *window; // @synthesize window=_window;
- (void)setCurrentProgress:(float)arg1;
- (void)startAnimation;
- (void)dealloc;
- (id)_screen;

@end

