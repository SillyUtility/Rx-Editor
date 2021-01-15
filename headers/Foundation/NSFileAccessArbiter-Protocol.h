//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSObject-Protocol.h>

@class NSSet, NSString, NSURLPromisePair;

@protocol NSFileAccessArbiter <NSObject>
- (oneway void)tiePresenterForID:(id)arg1 toItemAtURL:(NSURLPromisePair *)arg2;
- (oneway void)writerWithPurposeID:(id)arg1 didVersionChangeOfKind:(NSString *)arg2 toItemAtURL:(NSURLPromisePair *)arg3 withClientID:(NSString *)arg4 name:(NSString *)arg5;
- (oneway void)writerWithPurposeID:(id)arg1 didChangeItemAtURL:(NSURLPromisePair *)arg2;
- (oneway void)writerWithPurposeID:(id)arg1 didMakeItemDisappearAtURL:(NSURLPromisePair *)arg2;
- (oneway void)writerWithPurposeID:(id)arg1 didChangeUbiquityAttributes:(NSSet *)arg2 ofItemAtURL:(NSURLPromisePair *)arg3;
- (oneway void)writerWithPurposeID:(id)arg1 didChangeSharingOfItemAtURL:(NSURLPromisePair *)arg2;
- (oneway void)writerWithPurposeID:(id)arg1 didChangeUbiquityOfItemAtURL:(NSURLPromisePair *)arg2;
- (oneway void)writerWithPurposeID:(id)arg1 didReconnectItemAtURL:(NSURLPromisePair *)arg2;
- (oneway void)writerWithPurposeID:(id)arg1 didDisconnectItemAtURL:(NSURLPromisePair *)arg2;
- (oneway void)writerWithPurposeID:(id)arg1 didMoveItemAtURL:(NSURLPromisePair *)arg2 toURL:(NSURLPromisePair *)arg3;
- (oneway void)cancelAccessClaimForID:(id)arg1;
- (oneway void)revokeSubarbitrationClaimForID:(id)arg1;
- (oneway void)revokeAccessClaimForID:(id)arg1;
@end

