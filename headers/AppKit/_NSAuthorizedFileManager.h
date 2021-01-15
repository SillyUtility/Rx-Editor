//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSFileManager.h>

@class _NSWorkspaceAuthorizationData;

__attribute__((visibility("hidden")))
@interface _NSAuthorizedFileManager : NSFileManager
{
    _NSWorkspaceAuthorizationData *_auth;
}

- (BOOL)replaceItemAtURL:(id)arg1 withItemAtURL:(id)arg2 backupItemName:(id)arg3 options:(unsigned long long)arg4 resultingItemURL:(id *)arg5 error:(id *)arg6;
- (BOOL)setAttributes:(id)arg1 ofItemAtPath:(id)arg2 error:(id *)arg3;
- (BOOL)_withPartitionedAttributesFromDictionary:(id)arg1 performBlock:(CDUnknownBlockType)arg2;
- (BOOL)createSymbolicLinkAtPath:(id)arg1 withDestinationPath:(id)arg2 error:(id *)arg3;
- (BOOL)_handleLibSecInitStatus:(int)arg1 xpcError:(id)arg2 error:(id *)arg3;
- (void)dealloc;
- (id)initWithAuthData:(id)arg1;

@end

