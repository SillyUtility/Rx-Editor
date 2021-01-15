//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableArray, NSMutableDictionary, NSNumber, NSString;

__attribute__((visibility("hidden")))
@interface NSApplicationSubTest : NSObject
{
    NSNumber *_startTime;
    NSNumber *_startFrame;
    NSMutableArray *_time;
    NSMutableArray *_fps;
    NSString *_testName;
    BOOL _showTime;
    BOOL _showFps;
    NSMutableDictionary *_data;
    NSNumber *startTime;
}

- (void).cxx_destruct;
@property(readonly) NSNumber *startTime; // @synthesize startTime;
- (id)getObjectForKey:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (id)outputData;
- (void)stopWithFrameCount:(id)arg1;
- (void)startWithFrameCount:(id)arg1;
- (id)initWithName:(id)arg1 metrics:(id)arg2;

@end

