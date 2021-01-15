//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSObject-Protocol.h>

@protocol MTLDrawable <NSObject>
@property(readonly, nonatomic) unsigned long long drawableID;
@property(readonly, nonatomic) double presentedTime;
- (void)addPresentedHandler:(void (^)(id <MTLDrawable>))arg1;
- (void)presentAfterMinimumDuration:(double)arg1;
- (void)presentAtTime:(double)arg1;
- (void)present;
@end

