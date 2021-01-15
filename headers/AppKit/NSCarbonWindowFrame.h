//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

__attribute__((visibility("hidden")))
@interface NSCarbonWindowFrame : NSView
{
    unsigned long long _styleMask;
    BOOL resizeByIncrement;
    struct CGSize resizeParameter;
}

+ (struct CGSize)minFrameSizeForMinContentSize:(struct CGSize)arg1 styleMask:(unsigned long long)arg2;
+ (struct CGRect)contentRectForFrameRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2;
+ (struct CGRect)frameRectForContentRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2;
- (struct CGSize)aspectRatio;
- (void)setAspectRatio:(struct CGSize)arg1;
- (struct CGSize)resizeIncrements;
- (void)setResizeIncrements:(struct CGSize)arg1;
- (double)contentAlpha;
- (id)contentFill;
- (double)_sheetHeightAdjustment;
- (void)_setNonactivatingPanel:(BOOL)arg1;
- (struct CGRect)titlebarRect;
- (id)title;
- (void)setTitle:(id)arg1;
- (BOOL)isOpaque;
- (struct CGRect)dragRectForFrameRect:(struct CGRect)arg1;
- (void)setStyleMask:(unsigned long long)arg1;
- (unsigned long long)styleMask;
- (id)zoomButton;
- (id)minimizeButton;
- (id)closeButton;
- (double)_distanceFromToolbarBaseToTitlebar;
- (void)_hideToolbarWithAnimation:(BOOL)arg1;
- (void)_showToolbarWithAnimation:(BOOL)arg1;
- (BOOL)_toolbarIsManagedByExternalWindow;
- (BOOL)_toolbarIsHidden;
- (BOOL)_toolbarIsShown;
- (BOOL)_toolbarIsInTransition;
- (BOOL)_canHaveToolbar;
- (void)_windowChangedKeyState;
- (void)_updateButtonState;
- (void)_setSheet:(BOOL)arg1;
- (void)_setFrameNeedsDisplay:(BOOL)arg1;
- (id)initWithFrame:(struct CGRect)arg1 styleMask:(unsigned long long)arg2 owner:(id)arg3;
- (struct CGSize)minFrameSizeForMinContentSize:(struct CGSize)arg1 styleMask:(unsigned long long)arg2;
- (struct CGRect)contentRectForFrameRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2;
- (struct CGRect)frameRectForContentRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2;

@end

