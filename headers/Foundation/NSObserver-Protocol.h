//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSObject-Protocol.h>

@class NSError;

@protocol NSObserver <NSObject>

@optional
- (void)finishObserving;
- (void)receiveObservedError:(NSError *)arg1;
- (void)receiveObservedValue:(id)arg1;
@end

