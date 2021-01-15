//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSScrollingBehaviorConcurrentVBL, _NSScrollingConcurrentConstantData, _NSScrollingConcurrentSharedData;
@protocol OS_dispatch_source;

__attribute__((visibility("hidden")))
@interface _NSScrollingConcurrentMainThreadSynchronizer : NSObject
{
    NSObject<OS_dispatch_source> *_dispatchSource;
    _NSScrollingConcurrentSharedData *_sharedData;
    _NSScrollingConcurrentConstantData *_constantData;
    NSScrollingBehaviorConcurrentVBL *_scrollingBehavior;
    CDUnknownBlockType _preCommitHandler;
    CDUnknownBlockType _completionHandler;
    struct {
        unsigned int isSynchronizing:1;
        unsigned int unexpectedScrollDetected:1;
        unsigned int isSuspended:1;
        unsigned int reserved:29;
    } _flags;
    struct CGPoint _lastSetOrigin;
}

- (void).cxx_destruct;
@property(nonatomic) __weak NSScrollingBehaviorConcurrentVBL *scrollingBehavior; // @synthesize scrollingBehavior=_scrollingBehavior;
- (void)scrollView:(id)arg1 boundsChangedForClipView:(id)arg2;
- (void)_synchronize:(unsigned long long)arg1 preCommitHandler:(CDUnknownBlockType)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (BOOL)_doIdlePrefetch;
- (void)_updateSharedData;
- (void)_scrollToCanonicalOrigin;
- (void)signal:(unsigned long long)arg1 preCommitHandler:(CDUnknownBlockType)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (void)signal:(unsigned long long)arg1;
- (void)suspend;
- (void)resume;
- (void)dealloc;
- (id)initWithSharedData:(id)arg1 constantData:(id)arg2;

@end

