//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableDictionary, NSString;

@interface NSThread : NSObject
{
    id _private;
    unsigned char _bytes[44];
}

+ (void)detachNewThreadWithBlock:(CDUnknownBlockType)arg1;
+ (void)detachNewThreadSelector:(SEL)arg1 toTarget:(id)arg2 withObject:(id)arg3;
+ (BOOL)isDying;
+ (void)exit;
+ (id)currentThread;
+ (id)mainThread;
+ (id)callStackSymbols;
+ (id)callStackReturnAddresses;
+ (void)sleepForTimeInterval:(double)arg1;
+ (void)sleepUntilDate:(id)arg1;
+ (BOOL)setThreadPriority:(double)arg1;
+ (double)threadPriority;
+ (BOOL)isMultiThreaded;
+ (BOOL)isMainThread;
- (void)_nq:(id)arg1;
- (void)main;
- (void)start;
- (id)description;
- (void)cancel;
@property(readonly, getter=isCancelled) BOOL cancelled;
@property(readonly, getter=isFinished) BOOL finished;
@property(readonly, getter=isExecuting) BOOL executing;
@property(readonly) BOOL isMainThread;
- (BOOL)_setThreadPriority:(double)arg1;
@property double threadPriority;
- (void)_endQoSOverride:(struct pthread_override_s *)arg1;
- (struct pthread_override_s *)_beginQoSOverride:(unsigned int)arg1 relativePriority:(int)arg2;
@property long long qualityOfService;
@property unsigned long long stackSize;
@property(copy) NSString *name;
@property(readonly, retain) NSMutableDictionary *threadDictionary;
- (void)dealloc;
- (id)initWithTarget:(id)arg1 selector:(SEL)arg2 object:(id)arg3;
- (id)init;
- (id)initWithBlock:(CDUnknownBlockType)arg1;
- (BOOL)isDying;
- (id)runLoop;

@end

