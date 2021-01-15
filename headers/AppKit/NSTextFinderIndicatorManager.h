//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMapTable, NSMutableArray, NSView, NSWindow, _NSFindIndicatorOverlayView, _NSTextFinderImpl;

__attribute__((visibility("hidden")))
@interface NSTextFinderIndicatorManager : NSObject
{
    NSMapTable *_findIndicators;
    _NSTextFinderImpl *_textFinderImpl;
    BOOL _isVisible;
    BOOL _updating;
    NSView *_contentView;
    NSWindow *_overlayWindow;
    _NSFindIndicatorOverlayView *_overlayView;
    unsigned long long _disabledScreenUpdatesToken;
    BOOL _needsUpdate;
    char *_updateCancel;
    char *_pulseCancel;
    NSMutableArray *_indicatorsToPulse;
}

+ (id)_textRects:(id)arg1 inWebViewCoordinateSpace:(id)arg2;
- (BOOL)isVisible;
- (void)setIsVisible:(BOOL)arg1 animate:(BOOL)arg2;
- (void)_hideAnimate:(BOOL)arg1;
- (void)_showAnimate:(BOOL)arg1;
- (void)pulse;
- (void)cancel;
- (BOOL)needsUpdate;
- (void)setNeedsUpdate:(BOOL)arg1;
- (void)_flushUpdate;
- (void)_scheduleDelayedUpdate;
- (void)_delayedUpdate;
- (void)_enumerateViewsAndRectsForRange:(struct _NSRange)arg1 withBlock:(CDUnknownBlockType)arg2;
- (id)_parentWindow;
- (void)_containerDidChange;
- (id)_contentView;
- (id)_textFinderImpl;
- (void)dealloc;
- (id)initWithTextFinderImpl:(id)arg1;

@end

