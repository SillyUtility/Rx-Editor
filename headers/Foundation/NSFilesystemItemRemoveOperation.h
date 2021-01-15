//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSOperation.h>

@class NSError, NSString;

__attribute__((visibility("hidden")))
@interface NSFilesystemItemRemoveOperation : NSOperation
{
    id _delegate;
    NSString *_removePath;
    NSError *_error;
    void *_state;
    BOOL _filterUnderbars;
}

+ (id)filesystemItemRemoveOperationWithPath:(id)arg1;
+ (id)_errorWithErrno:(int)arg1 atPath:(id)arg2;
- (void)dealloc;
- (void)main;
- (id)initWithPath:(id)arg1;
- (BOOL)_filtersUnderbars;
- (void)_setFilterUnderbars:(BOOL)arg1;
- (void)_setError:(id)arg1;
- (id)error;
- (void)setDelegate:(id)arg1;
- (id)delegate;

@end

