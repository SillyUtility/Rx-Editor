//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@interface NSHMDDisplayLink : NSObject
{
}

+ (double)currentTimestamp;
- (void)resume;
- (void)suspend;
@property(readonly, getter=isValid) BOOL valid;
- (void)invalidate;
@property BOOL executesConcurrently;

@end

