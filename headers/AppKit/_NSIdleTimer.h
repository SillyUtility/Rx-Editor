//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

__attribute__((visibility("hidden")))
@interface _NSIdleTimer : NSObject
{
    unsigned long long _id;
    struct os_unfair_lock_s _lock;
    unsigned long long _suspensionCount;
    CDUnknownBlockType _handler;
}

+ (void)removeIdleTimer:(id)arg1;
+ (void)addIdleTimer:(id)arg1;
+ (void)idle;
- (void)resume;
- (void)suspend;
@property(copy) CDUnknownBlockType handler;
- (void)idle;
- (void)dealloc;
- (id)init;

@end

