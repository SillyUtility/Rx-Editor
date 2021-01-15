//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCopying-Protocol.h>

__attribute__((visibility("hidden")))
@interface NSDisplayTiming : NSObject <NSCopying>
{
}

+ (id)allocWithZone:(struct _NSZone *)arg1;
+ (id)displayTimingsForActiveScreens;
+ (id)displayTimingForScreenNumber:(long long)arg1;
+ (id)genericDisplayTiming;
+ (id)displayTimingWithAnchorTime:(unsigned long long)arg1 interval:(unsigned long long)arg2 submissionDelta:(unsigned long long)arg3 wakeUpDelta:(unsigned long long)arg4;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property(readonly) unsigned long long interval;
- (unsigned long long)presentationTimeForWakeUpTime:(unsigned long long)arg1;
- (unsigned long long)submissionDeadlineForWakeUpTime:(unsigned long long)arg1;
- (unsigned long long)wakeUpTimeAfterTime:(unsigned long long)arg1;
- (unsigned long long)submissionDeadlineAfterTime:(unsigned long long)arg1;
- (unsigned long long)presentationTimeForSubmissionDeadline:(unsigned long long)arg1;
- (unsigned long long)submissionDeadlineForPresentationTime:(unsigned long long)arg1;
- (unsigned long long)presentationTimeAfterTime:(unsigned long long)arg1;

@end

