//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSProgress.h>

@class NSOperationQueue;

__attribute__((visibility("hidden")))
@interface _NSOperationQueueProgress : NSProgress
{
    NSOperationQueue *_queue;
    struct os_unfair_lock_s _queueLock;
}

- (void)setTotalUnitCount:(long long)arg1;
- (void)invalidateQueue;
- (id)initWithQueue:(id)arg1;

@end

