//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@protocol OS_xpc_object;

__attribute__((visibility("hidden")))
@interface _NSTouchBarLogger : NSObject
{
    NSObject<OS_xpc_object> *_connection;
}

+ (void)addLogInfo:(id)arg1 type:(id)arg2;
+ (void)addLogMessage:(id)arg1;
+ (id)sharedTouchBarLogger;
+ (void)listenForHotKey;
- (void)addLogInfo:(id)arg1 type:(id)arg2;
- (id)connection;
- (void)dealloc;
- (id)init;

@end

