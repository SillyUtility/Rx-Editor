//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/_NSScrollingConcurrentVBLPreprocessFilter.h>

@class _NSScrollingConcurrentEventMonitor, _NSScrollingRubberbandFilter;

__attribute__((visibility("hidden")))
@interface _NSScrollingConcurrentEventVBLPreprocessFilter : _NSScrollingConcurrentVBLPreprocessFilter
{
    _NSScrollingConcurrentEventMonitor *_eventMonitor;
    _NSScrollingRubberbandFilter *_rubberbandFilter;
    BOOL _isStretched;
}

@property(retain, nonatomic) _NSScrollingConcurrentEventMonitor *eventMonitor; // @synthesize eventMonitor=_eventMonitor;
- (void)scrollingVBLMonitor:(id)arg1 synchronizeForTimestamp:(double)arg2;
- (void)dealloc;
- (id)initWithConstantData:(id)arg1;

@end

