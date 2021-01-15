//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSWindow.h>

#import <AppKit/NSLockoutUIWindow-Protocol.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface NSLockoutUIPlaceholderWindow : NSWindow <NSLockoutUIWindow>
{
    double _animationDuration;
    BOOL _engaged;
}

- (BOOL)_wantsSnapshotProxyWindowForOrderOutAnimation;
- (id)_windowTransformAnimationForOrdering:(long long)arg1 animationType:(long long)arg2 interruptingAnimation:(id)arg3;
- (long long)_effectiveOrderOutAnimationTypeIfModal:(BOOL)arg1;
- (long long)_effectiveOrderFrontAnimationTypeIfModal:(BOOL)arg1;
- (void)disengageWithDuration:(double)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)engageWithDuration:(double)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)transitioning;
- (BOOL)engaged;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

