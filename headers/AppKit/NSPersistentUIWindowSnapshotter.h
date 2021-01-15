//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSData, NSMutableDictionary, NSURL;
@protocol OS_dispatch_queue;

__attribute__((visibility("hidden")))
@interface NSPersistentUIWindowSnapshotter : NSObject
{
    NSURL *_persistentStateDirectoryURL;
    NSObject<OS_dispatch_queue> *_workQueue;
    NSMutableDictionary *windowsPendingSnapshotting;
    NSMutableDictionary *windowIDsToSnapshotInfo;
    BOOL hasDisabledSuddenTermination;
    NSObject<OS_dispatch_queue> *_IOQueue;
    BOOL volumeIsLocal;
    NSData *_cryptoKey;
    NSData *_cryptoUUID;
    unsigned int _cryptoKeyGeneration;
}

@property(copy) NSData *cryptoKey; // @synthesize cryptoKey=_cryptoKey;
@property(copy) NSData *cryptoUUID; // @synthesize cryptoUUID=_cryptoUUID;
- (BOOL)writeWindowSnapshot:(const void *)arg1 length:(unsigned long long)arg2 width:(unsigned long long)arg3 height:(unsigned long long)arg4 bytesPerRow:(unsigned long long)arg5 toFile:(id)arg6 inDirectory:(id)arg7 encryptingWithKey:(id)arg8 uuid:(id)arg9 checksum:(unsigned int *)arg10 fd:(int *)arg11;
- (void)captureAndWriteSnapshotForWindowNumber:(long long)arg1 forWindowID:(unsigned int)arg2 waitUntilDone:(BOOL)arg3;
- (void)deleteSnapshotForWindowID:(unsigned int)arg1;
- (void)enqueueWindowForSnapshotting:(unsigned int)arg1 forWindowNumber:(long long)arg2;
- (void)finishPendingSnapshotsImmediatelyWithCompletionHandler:(CDUnknownBlockType)arg1;
- (void)asynchronouslySnapshotPendingWindows;
- (void)synchronouslySnapshotPendingWindows;
- (BOOL)snapshotOnePendingWindowWaitUntilDone:(BOOL)arg1;
- (BOOL)dequeueOneWindowToSnapshot:(unsigned int *)arg1 windowNumber:(long long *)arg2;
- (void)accessWindowBits:(long long)arg1 handler:(CDUnknownBlockType)arg2;
- (BOOL)windowHasBeenSnapshotted:(unsigned int)arg1;
- (void)discardAllSnapshotData;
- (void)updateSuddenTermination;
- (BOOL)setCryptoKey:(id)arg1 uuid:(id)arg2;
- (void)dealloc;
- (id)initWithPersistentStateDirectoryURL:(id)arg1 IOQueue:(id)arg2;
- (id)initWithFileManager:(id)arg1;

@end

