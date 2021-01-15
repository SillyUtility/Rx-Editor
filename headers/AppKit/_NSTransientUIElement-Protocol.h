//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSObject-Protocol.h>

@class NSEvent, NSWindow;

@protocol _NSTransientUIElement <NSObject>
@property(readonly) long long _transientBehavior;
@property(setter=_setRegisteredTransientBehavior:) long long _registeredTransientBehavior;
- (void)_closeForToolbarPresentingOnWindow:(NSWindow *)arg1;
- (void)_closeForSheetPresentingOnWindow:(NSWindow *)arg1;
- (void)_closeForKeyDownEvent:(NSEvent *)arg1;
- (void)_closeForNonDragOrResizeClickWithEvent:(NSEvent *)arg1;
- (BOOL)_isAffectedByEventsInWindow:(NSWindow *)arg1;

@optional
@property(readonly, getter=isDetached) BOOL detached;
@end

