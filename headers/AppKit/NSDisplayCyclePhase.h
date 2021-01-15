//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSHashTable, NSString;

__attribute__((visibility("hidden")))
@interface NSDisplayCyclePhase : NSObject
{
    NSString *_name;
    NSHashTable *_earlierPhases;
    NSHashTable *_laterPhases;
}

@property(readonly, copy) NSString *name;
- (void)dealloc;
- (id)description;
- (id)init;
- (id)initWithName:(id)arg1 beforePhases:(id)arg2 afterPhases:(id)arg3;

@end

