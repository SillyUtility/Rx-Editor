//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSError;
@protocol OS_dispatch_group;

__attribute__((visibility("hidden")))
@interface _NSFilePromiseProviderPrivate : NSObject
{
    NSError *_provideItemErrorOrNil;
    NSObject<OS_dispatch_group> *_provideItemGroup;
}

@property(retain, nonatomic) NSObject<OS_dispatch_group> *provideItemGroup; // @synthesize provideItemGroup=_provideItemGroup;
@property(retain, nonatomic) NSError *provideItemErrorOrNil; // @synthesize provideItemErrorOrNil=_provideItemErrorOrNil;
- (void)dealloc;

@end

