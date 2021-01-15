//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSImmediateActionAnimationController-Protocol.h>

@class NSArray, NSMutableArray, NSString, NSTextFinder, NSView, NSWindow;
@protocol NSFindIndicatorDelegate;

@interface NSFindIndicator : NSObject <NSImmediateActionAnimationController>
{
    NSTextFinder *_textFinder;
    NSView *_view;
    id <NSFindIndicatorDelegate> _delegate;
    NSWindow *_parentWindow;
    CDUnknownBlockType _contentDrawer;
    CDUnknownBlockType _completionHandler;
    CDUnknownBlockType _imageProvider;
    NSArray *_rects;
    struct CGRect _bounds;
    double _animationInProgress;
    id _invoker;
    BOOL _usesThreadedAnimation;
    double _startTime;
    NSMutableArray *_windows;
    BOOL _shouldFade;
    BOOL _visible;
}

+ (void)endDrawing;
+ (void)beginDrawing;
+ (BOOL)isDrawing;
@property(copy) CDUnknownBlockType imageProvider; // @synthesize imageProvider=_imageProvider;
@property(copy) CDUnknownBlockType completionHandler; // @synthesize completionHandler=_completionHandler;
@property(copy) CDUnknownBlockType contentDrawer; // @synthesize contentDrawer=_contentDrawer;
@property(retain) NSView *view; // @synthesize view=_view;
@property(retain) NSTextFinder *textFinder; // @synthesize textFinder=_textFinder;
@property BOOL usesThreadedAnimation; // @synthesize usesThreadedAnimation=_usesThreadedAnimation;
@property id <NSFindIndicatorDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain) NSWindow *parentWindow; // @synthesize parentWindow=_parentWindow;
- (void)recognizerDidDismissAnimation:(id)arg1;
- (void)recognizerDidCancelAnimation:(id)arg1;
- (void)recognizerDidCompleteAnimation:(id)arg1;
- (void)recognizerDidUpdateAnimation:(id)arg1;
- (void)recognizerWillBeginAnimation:(id)arg1;
- (void)focusUAZoom;
- (void)_cancel;
- (void)_fade:(double)arg1;
- (void)_dissolve:(double)arg1 animate:(BOOL)arg2;
- (void)_pulse:(double)arg1;
- (void)dissolve;
- (void)pulseWithFade:(BOOL)arg1 andDissolve:(BOOL)arg2;
- (void)pulseAndFade:(BOOL)arg1;
- (void)_redrawReusingWindows;
- (id)_buildFindIndicatorWindows;
- (id)_contentImage;
- (void)_cacheDisplayInRect:(struct CGRect)arg1 ofView:(id)arg2 toBitmapImageRep:(id)arg3;
- (id)_findIndicatorPathForRects:(id)arg1;
- (id)_indicatorWindowGroupsOfRectGroupsForRects:(id)arg1;
- (id)_effectiveParentWindow;
@property(getter=isVisible) BOOL visible;
@property(copy) NSArray *rects;
- (void)updateWithRects:(id)arg1;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

