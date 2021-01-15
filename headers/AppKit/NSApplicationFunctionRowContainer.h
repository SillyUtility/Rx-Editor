//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSTouchBarProviderContainer-Protocol.h>

@class NSString, NSTouchBar;

__attribute__((visibility("hidden")))
@interface NSApplicationFunctionRowContainer : NSObject <NSTouchBarProviderContainer>
{
}

- (id)NS_touchBarProvidersKeyPaths;
- (id)NS_touchBarProviders;
@property(readonly) NSTouchBar *touchBar;
- (BOOL)_lockoutEngaged;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

