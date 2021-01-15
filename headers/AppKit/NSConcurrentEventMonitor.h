//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface NSConcurrentEventMonitor : NSObject
{
    BOOL isValid;
    BOOL isProcessing;
    unsigned long long eventMask;
    NSString *identifier;
    CDUnknownBlockType callback;
}

@property(copy) CDUnknownBlockType callback; // @synthesize callback;
@property unsigned long long eventMask; // @synthesize eventMask;
@property(copy) NSString *identifier; // @synthesize identifier;
@property BOOL isProcessing; // @synthesize isProcessing;
@property BOOL isValid; // @synthesize isValid;
- (void)dealloc;

@end

