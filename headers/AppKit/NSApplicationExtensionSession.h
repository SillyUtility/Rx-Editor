//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSProgress, NSString;

@interface NSApplicationExtensionSession : NSObject
{
}

- (void)completeSessionReturningItems:(id)arg1 error:(id)arg2;
@property(readonly) NSArray *inputItems;
@property(readonly) NSString *extensionType;
@property(retain) NSProgress *progress;

@end

