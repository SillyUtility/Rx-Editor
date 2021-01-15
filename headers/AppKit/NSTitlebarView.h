//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSVisualEffectView.h>

@class NSThemeFrame, NSTitlebarContainerView, NSTrackingArea;

__attribute__((visibility("hidden")))
@interface NSTitlebarView : NSVisualEffectView
{
    BOOL _transparent;
    NSTrackingArea *_buttonGroupTrackingArea;
    NSThemeFrame *_associatedThemeFrame;
    NSTitlebarContainerView *_containerView;
}

@property NSThemeFrame *associatedThemeFrame; // @synthesize associatedThemeFrame=_associatedThemeFrame;
- (void)layout;
- (id)_titleTextFieldView;
- (id)menuForEvent:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (void)rightMouseDown:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)mouseDown:(id)arg1;
- (BOOL)acceptsFirstMouse:(id)arg1;
- (BOOL)_shouldBeTreatedAsInkEventInInactiveWindow:(id)arg1;
- (void)mouseExited:(id)arg1;
- (void)mouseEntered:(id)arg1;
- (void)updateTrackingAreas;
- (void)_removeTrackingAreaIfNeeded;
@property BOOL transparent;
- (void)viewDidMoveToWindow;
- (id)_preferredAppearance;
- (BOOL)_isHUDWindow;
- (void)dealloc;
- (void)setFrameSize:(struct CGSize)arg1;
- (void)resizeWithOldSuperviewSize:(struct CGSize)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)titleFont;
- (id)accessibilityChildrenAttribute;
- (BOOL)accessibilityIsIgnored;

@end

