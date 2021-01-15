//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/_NSScrollingMomentumCalculator.h>

__attribute__((visibility("hidden")))
@interface _NSScrollingMomentumCalculatorBase : _NSScrollingMomentumCalculator
{
    struct CGPoint _initialOrigin;
    struct CGPoint _initialVelocity;
    struct CGPoint _destinationOrigin;
    struct CGRect _docFrame;
    struct CGPoint _constrainedClippingOrigin;
    struct CGSize _clippingSize;
    struct CGSize _tolerance;
    double _decelerationRate;
}

- (void)setDecelerationRate:(double)arg1;
- (double)decelerationRate;
- (void)setTolerance:(struct CGSize)arg1;
- (struct CGSize)tolerance;
- (void)setClippingSize:(struct CGSize)arg1;
- (struct CGSize)clippingSize;
- (void)setConstrainedClippingOrigin:(struct CGPoint)arg1;
- (struct CGPoint)constrainedClippingOrigin;
- (void)setInitialVelocity:(struct CGPoint)arg1;
- (struct CGPoint)initialVelocity;
- (void)setDocumentFrame:(struct CGRect)arg1;
- (struct CGRect)documentFrame;
- (void)setDestinationOrigin:(struct CGPoint)arg1;
- (struct CGPoint)destinationOrigin;
- (void)setInitialOrigin:(struct CGPoint)arg1;
- (struct CGPoint)initialOrigin;
- (void)calculateToReachDestination;
- (void)calculateDestination;
- (void)setVerticalScrollDecelerationFactor:(double)arg1;
- (double)verticalScrollDecelerationFactor;
- (void)setHorizontalScrollDecelerationFactor:(double)arg1;
- (double)horizontalScrollDecelerationFactor;
- (void)dealloc;

@end

