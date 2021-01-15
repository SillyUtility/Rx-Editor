//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSCountedSet, NSDocumentRevisionsController, NSMapTable, NSMutableOrderedSet;

__attribute__((visibility("hidden")))
@interface _NSDocumentRevisionsCache : NSObject
{
    NSDocumentRevisionsController *controller;
    NSMapTable *costs;
    NSCountedSet *pinnedRevisions;
    NSMutableOrderedSet *unpinnedRevisions;
    id vmPressureSourceID;
}

- (void)removeRevision:(id)arg1;
- (void)updateCost:(unsigned long long)arg1 forRevision:(id)arg2;
- (void)addRevision:(id)arg1 cost:(unsigned long long)arg2;
- (BOOL)containsRevision:(id)arg1;
- (void)relinquishRevision:(id)arg1;
- (BOOL)acquireRevision:(id)arg1;
- (void)_insertUnpinnedRevision:(id)arg1;
@property(getter=isEvictionEnabled) BOOL evictionEnabled;
- (void)dealloc;
- (id)init;
- (id)initWithRevisionsController:(id)arg1;

@end

