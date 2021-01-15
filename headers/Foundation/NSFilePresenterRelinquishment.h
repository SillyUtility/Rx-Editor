//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSCountedSet, NSMutableArray;

__attribute__((visibility("hidden")))
@interface NSFilePresenterRelinquishment : NSObject
{
    struct os_unfair_lock_s _lock;
    NSCountedSet *_blockingAccessClaimIDs;
    NSMutableArray *_relinquishReplies;
    CDUnknownBlockType _reacquirer;
    NSMutableArray *_blockingPrerelinquishReplies;
    BOOL _prerelinquishInProgress;
}

- (void)didRelinquish;
- (void)_locked_addPrerelinquishReply:(CDUnknownBlockType)arg1;
- (BOOL)_locked_addRelinquishReply:(CDUnknownBlockType)arg1;
- (void)removeAllBlockingAccessClaimIDs;
- (void)removeBlockingAccessClaimID:(id)arg1;
- (void)removeBlockingAccessClaimID:(id)arg1 thenContinue:(CDUnknownBlockType)arg2;
- (void)setReacquirer:(CDUnknownBlockType)arg1;
- (void)performRelinquishmentToAccessClaimIfNecessary:(id)arg1 usingBlock:(CDUnknownBlockType)arg2 withReply:(CDUnknownBlockType)arg3;
- (void)performRemoteDeletePrerelinquishmentIfNecessaryUsingBlock:(CDUnknownBlockType)arg1 withReply:(CDUnknownBlockType)arg2;
- (void)dealloc;

@end

