//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableDictionary, NSString, NSURL;

@interface NSFileCoordinator : NSObject
{
    id _accessArbiter;
    id _fileReactor;
    id _purposeID;
    NSURL *_recentFilePresenterURL;
    id _accessClaimIDOrIDs;
    BOOL _isCancelled;
    NSMutableDictionary *_movedItems;
}

+ (id)_canonicalURLForURL:(id)arg1;
+ (id)filePresenters;
+ (void)removeFilePresenter:(id)arg1;
+ (void)addFilePresenter:(id)arg1;
+ (void)_getDebugInfoWithCompletionHandler:(CDUnknownBlockType)arg1;
+ (void)_printDebugInfo;
+ (id)_currentClaimPurposeIdentifier;
+ (id)_currentFileCoordinator;
+ (BOOL)_itemHasPresentersAtURL:(id)arg1;
+ (void)_setAutomaticFileProviderReregistrationDisabled:(BOOL)arg1;
+ (id)_fileProviders;
+ (void)_removeFileProvider:(id)arg1;
+ (void)_addFileProvider:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
+ (void)_addFileProvider:(id)arg1;
+ (void)__itemAtURL:(id)arg1 didResolveConflictVersionWithClientID:(id)arg2 name:(id)arg3 purposeID:(id)arg4;
+ (void)__itemAtURL:(id)arg1 didLoseVersionWithClientID:(id)arg2 name:(id)arg3 purposeID:(id)arg4;
+ (void)__itemAtURL:(id)arg1 didGainVersionWithClientID:(id)arg2 name:(id)arg3 purposeID:(id)arg4;
+ (void)__itemAtURL:(id)arg1 didChangeWithPurposeID:(id)arg2;
+ (void)__itemAtURL:(id)arg1 didDisappearWithPurposeID:(id)arg2;
+ (void)__itemAtURL:(id)arg1 didChangeUbiquityWithPurposeID:(id)arg2;
+ (void)__itemAtURL:(id)arg1 didReconnectWithPurposeID:(id)arg2;
+ (void)__itemAtURL:(id)arg1 didDisconnectWithPurposeID:(id)arg2;
+ (void)__itemAtURL:(id)arg1 didMoveToURL:(id)arg2 purposeID:(id)arg3;
+ (void)_setNextClaimIdentifier:(id)arg1;
+ (id)_nextClaimIdentifier;
+ (BOOL)_skipCoordinationWork;
+ (void)_performBarrierAsync:(CDUnknownBlockType)arg1;
+ (void)_performBarrier;
+ (id)_endpointForInProcessFileCoordinationServer;
+ (void)_adoptFCDEndpointForTest:(id)arg1;
+ (id)_createConnectionToProgressRegistrar;
+ (id)_createConnectionToFileAccessArbiterForQueue:(id)arg1;
+ (void)_stopInProcessFileCoordinationAndProgressServers;
+ (id)_inProcessFileAccessArbiter;
+ (void)_startInProcessFileCoordinationAndProgressServers;
+ (id)_fileAccessArbiterInterface;
+ (id)_fileProviderInterface;
+ (id)_filePresenterInterface;
+ (id)_createIdentifierForNewClaim;
+ (void)_setCurrentClaimPurposeIdentifier:(id)arg1;
+ (void)_setKernelMaterializationOperation:(unsigned int)arg1;
+ (void)_setReadingOptions:(unsigned long long)arg1;
+ (void)_removeInfoForID:(id)arg1;
+ (void)_addProcessIdentifier:(int)arg1 observedUbiquityAttributes:(id)arg2 forID:(id)arg3;
+ (void)_accessPresenterInfoUsingBlock:(CDUnknownBlockType)arg1;
+ (unsigned int)_kernelMaterializationOperation;
+ (unsigned long long)_readingOptions;
+ (BOOL)_provideRecursively;
+ (id)_observedUbiquityAttributesForPresenterWithID:(id)arg1;
+ (int)_processIdentifierForID:(id)arg1;
+ (unsigned long long)_responsesForPresenter:(id)arg1;
- (void)cancel;
- (void)itemAtURL:(id)arg1 didChangeUbiquityAttributes:(id)arg2;
- (BOOL)_isValidUbiquityAttribute:(id)arg1;
- (void)itemAtURL:(id)arg1 didMoveToURL:(id)arg2;
- (void)itemAtURL:(id)arg1 willMoveToURL:(id)arg2;
- (void)prepareForReadingItemsAtURLs:(id)arg1 options:(unsigned long long)arg2 writingItemsAtURLs:(id)arg3 options:(unsigned long long)arg4 error:(id *)arg5 byAccessor:(CDUnknownBlockType)arg6;
- (void)coordinateAccessWithIntents:(id)arg1 queue:(id)arg2 byAccessor:(CDUnknownBlockType)arg3;
- (void)coordinateWritingItemAtURL:(id)arg1 options:(unsigned long long)arg2 writingItemAtURL:(id)arg3 options:(unsigned long long)arg4 error:(id *)arg5 byAccessor:(CDUnknownBlockType)arg6;
- (void)coordinateReadingItemAtURL:(id)arg1 options:(unsigned long long)arg2 writingItemAtURL:(id)arg3 options:(unsigned long long)arg4 error:(id *)arg5 byAccessor:(CDUnknownBlockType)arg6;
- (void)coordinateWritingItemAtURL:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3 byAccessor:(CDUnknownBlockType)arg4;
- (void)coordinateReadingItemAtURL:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3 byAccessor:(CDUnknownBlockType)arg4;
- (void)_invokeAccessor:(CDUnknownBlockType)arg1 thenCompletionHandler:(CDUnknownBlockType)arg2;
@property(copy) NSString *purposeIdentifier;
- (void)dealloc;
- (id)initWithFilePresenter:(id)arg1;
- (id)init;
- (void)releaseAccess:(id)arg1;
- (id)retainAccess;
- (void)_setPurposeIdentifier:(id)arg1;
- (BOOL)_purposeIdentifierLockedDown;
- (void)_lockdownPurposeIdentifier;
- (void)_setFileProvider:(id)arg1;
- (void)__prepareForReadingItemsAtURLs:(id)arg1 options:(unsigned long long)arg2 writingItemsAtURLs:(id)arg3 options:(unsigned long long)arg4 byAccessor:(CDUnknownBlockType)arg5;
- (void)__coordinateWritingItemAtURL:(id)arg1 options:(unsigned long long)arg2 writingItemAtURL:(id)arg3 options:(unsigned long long)arg4 purposeID:(id)arg5 byAccessor:(CDUnknownBlockType)arg6;
- (void)__coordinateReadingItemAtURL:(id)arg1 options:(unsigned long long)arg2 writingItemAtURL:(id)arg3 options:(unsigned long long)arg4 purposeID:(id)arg5 byAccessor:(CDUnknownBlockType)arg6;
- (void)__coordinateWritingItemAtURL:(id)arg1 options:(unsigned long long)arg2 purposeID:(id)arg3 byAccessor:(CDUnknownBlockType)arg4;
- (void)__coordinateReadingItemAtURL:(id)arg1 options:(unsigned long long)arg2 purposeID:(id)arg3 byAccessor:(CDUnknownBlockType)arg4;
- (void)_itemDidChangeAtURL:(id)arg1;
- (void)_itemDidDisappearAtURL:(id)arg1;
- (void)sharingDidChangeForItemAtURL:(id)arg1;
- (void)_ubiquityDidChangeForItemAtURL:(id)arg1;
- (void)_itemAtURL:(id)arg1 didMoveToURL:(id)arg2;
- (void)_itemAtURL:(id)arg1 willMoveToURL:(id)arg2;
- (void)_coordinateAccessWithIntents:(id)arg1 queue:(id)arg2 byAccessor:(CDUnknownBlockType)arg3;
- (void)_coordinateWritingItemAtURL:(id)arg1 options:(unsigned long long)arg2 writingItemAtURL:(id)arg3 options:(unsigned long long)arg4 error:(id *)arg5 byAccessor:(CDUnknownBlockType)arg6;
- (void)_coordinateReadingItemAtURL:(id)arg1 options:(unsigned long long)arg2 writingItemAtURL:(id)arg3 options:(unsigned long long)arg4 error:(id *)arg5 byAccessor:(CDUnknownBlockType)arg6;
- (void)_coordinateWritingItemAtURL:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3 byAccessor:(CDUnknownBlockType)arg4;
- (void)_coordinateReadingItemAtURL:(id)arg1 options:(unsigned long long)arg2 error:(id *)arg3 byAccessor:(CDUnknownBlockType)arg4;
- (void)_withAccessArbiter:(id)arg1 invokeAccessor:(CDUnknownBlockType)arg2 orDont:(BOOL)arg3 andRelinquishAccessClaim:(id)arg4;
- (void)_didEndWrite:(id)arg1;
- (id)_willStartWriteWithIntents:(id)arg1 async:(BOOL)arg2;
- (void)_blockOnAccessClaim:(id)arg1 withAccessArbiter:(id)arg2;
- (void)_forgetAccessClaimForID:(id)arg1;
- (void)_requestAccessClaim:(id)arg1 withProcedure:(CDUnknownBlockType)arg2;
- (void)_cancelClaimWithIdentifier:(id)arg1;

@end

