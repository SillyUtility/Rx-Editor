//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSValue;

__attribute__((visibility("hidden")))
@interface NSLegacyFilePromiseProvider : NSObject
{
    BOOL _isPromiseValid;
    NSArray *_filePromiseProviders;
    NSValue *_weakPasteboard;
}

@property(copy) NSArray *filePromiseProviders; // @synthesize filePromiseProviders=_filePromiseProviders;
- (void)draggingCancelled:(id)arg1;
- (void)draggingEnded:(id)arg1;
- (void)pasteboardFinishedWithDataProvider:(id)arg1;
- (void)pasteboard:(id)arg1 provideDataForType:(id)arg2;
- (void)dealloc;
- (id)initWithPasteboard:(id)arg1;

@end

