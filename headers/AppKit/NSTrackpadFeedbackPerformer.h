//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSInputFeedbackPerformer-Protocol.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface NSTrackpadFeedbackPerformer : NSObject <NSInputFeedbackPerformer>
{
}

- (void)_performFeedbackPattern:(long long)arg1;
- (void)performFeedbackPattern:(long long)arg1 forTimestamp:(double)arg2;
- (void)_performFeedbackPattern:(long long)arg1 when:(unsigned long long)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

