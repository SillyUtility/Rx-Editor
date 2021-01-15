//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class _NSScrollingPredominantAxisFilter;
@protocol _NSScrollStateEventListener;

__attribute__((visibility("hidden")))
@interface _NSScrollingConcurrentEventMonitor : NSObject
{
    struct {
        unsigned int shouldUseUnacceleratedDelta:1;
        unsigned int shouldCoalesceDeltas:1;
        unsigned int shouldIgnoreConsumption:1;
        unsigned int wantsGestureEvents:1;
        unsigned int shouldStopMonitoringOnMomentumEnd:1;
        unsigned int didProcessMomentumEnd:1;
        unsigned int didPostPhysicalBegan:1;
        unsigned int didPostMomentumBegan:1;
        unsigned int deltaIsAccelerated:1;
        unsigned int reserved:23;
    } _flags;
    id _monitorID;
    char *_isCancelledPtr;
    unsigned long long _originalGestureMask;
    CDUnknownBlockType _eventProcessingHandler;
    id <_NSScrollStateEventListener> _scrollStateDelegate;
    _NSScrollingPredominantAxisFilter *_predominantAxisFilter;
    _NSScrollingPredominantAxisFilter *_backupPredominantAxisFilter;
    struct CGPoint _delta;
    struct CGPoint _velocity;
    struct CGPoint _backupVelocity;
    int _deviceType;
}

+ (void)initialize;
@property(readonly, nonatomic) int deviceType; // @synthesize deviceType=_deviceType;
@property(nonatomic) id <_NSScrollStateEventListener> scrollStateDelegate; // @synthesize scrollStateDelegate=_scrollStateDelegate;
@property(copy, nonatomic) CDUnknownBlockType eventProcessingHandler; // @synthesize eventProcessingHandler=_eventProcessingHandler;
- (void)_monitorEvent:(id)arg1;
- (void)consumePropertiesWithBlock:(CDUnknownBlockType)arg1;
- (void)threadSafeMultiPropertyAccess:(CDUnknownBlockType)arg1;
- (void)stopMonitoring;
- (void)startMonitoring;
@property(nonatomic) long long predominantAxisMode;
@property(readonly, nonatomic) BOOL deltaIsAccelerated;
@property(nonatomic) BOOL shouldStopMonitoringOnMomentumEnd;
@property(nonatomic) BOOL wantsGestureEvents;
@property(nonatomic) BOOL shouldIgnoreConsumption;
@property(nonatomic) BOOL shouldCoalesceDeltas;
@property(nonatomic) BOOL shouldUseUnacceleratedDelta;
@property(readonly, nonatomic) struct CGPoint velocity;
@property(readonly, nonatomic) struct CGPoint delta;
- (void)dealloc;
- (id)initWithEvent:(id)arg1 predominantAxisMode:(long long)arg2;

@end

