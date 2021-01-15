//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSObservationTransformer.h>

@interface NSReduceObservationTransformer : NSObservationTransformer
{
    CDUnknownBlockType _reducer;
    id _accumulator;
}

+ (id)reduceValue:(id)arg1 withReducer:(CDUnknownBlockType)arg2;
- (void)dealloc;
- (id)initWithBlock:(CDUnknownBlockType)arg1 initialValue:(id)arg2;
- (void)_receiveBox:(id)arg1;
- (void)finishObserving;

@end

