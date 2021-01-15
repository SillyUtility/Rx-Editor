//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@interface ASKDebuggerSupport : NSObject
{
    BOOL _isDebugging;
    BOOL _isDebuggerReady;
    int _pid;
}

+ (id)sharedDebuggerSupport;
- (void)checkForDebugger;
- (void)processEvents;
- (void)notifyDebugger;
- (void)registerForContinueEvent;
- (void)handleContinueAppleEvent:(id)arg1 withReplyEvent:(id)arg2;
- (id)sendEvent:(id)arg1 sendMode:(int)arg2;
- (void)setPid:(int)arg1;
- (int)pid;
- (void)setIsDebuggerReady:(BOOL)arg1;
- (BOOL)isDebuggerReady;
- (void)setIsDebugging:(BOOL)arg1;
- (BOOL)isDebugging;
- (id)init;

@end

