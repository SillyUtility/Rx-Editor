//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/_NSScrollingConcurrentVBLPreprocessFilter.h>

__attribute__((visibility("hidden")))
@interface _NSScrollingConcurrentRubberbandSnapAnimation : _NSScrollingConcurrentVBLPreprocessFilter
{
    struct CGPoint _lastSetOrigin;
    struct CGPoint _initialOrigin;
    struct CGPoint _initialVelocity;
    struct CGSize _initialStretchAmount;
    double _initialTimestamp;
}

- (void)scrollingVBLMonitor:(id)arg1 synchronizeForTimestamp:(double)arg2;
- (void)dealloc;
- (id)initWithInitialOrigin:(struct CGPoint)arg1 velocity:(struct CGPoint)arg2 stretch:(struct CGSize)arg3;

@end

