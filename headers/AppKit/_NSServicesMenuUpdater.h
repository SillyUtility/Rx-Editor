//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSMenuDelegate-Protocol.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface _NSServicesMenuUpdater : NSObject <NSMenuDelegate>
{
    unsigned long long _updateGeneration;
    struct OpaqueMenuRef *_pluggedMenuRef;
    int _servicesSeedChangeToken;
}

- (void)_processRequest:(id)arg1;
- (void)performServiceFromEntry:(id)arg1;
- (BOOL)isPluggedIntoMenuRef:(struct OpaqueMenuRef *)arg1;
- (void)unplugMenu:(id)arg1;
- (void)plugMenu:(id)arg1 intoMenuRef:(struct OpaqueMenuRef *)arg2;
- (void)updateForLiveServicesChangedNotification:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (BOOL)updateMenu:(id)arg1 withEvent:(id)arg2 withFlags:(unsigned long long)arg3;
- (void)insertServicesIntoMenu:(id)arg1 withKeyEvent:(id)arg2 isForDisplay:(BOOL)arg3;
- (void)populateMenu:(id)arg1 withServiceEntries:(id)arg2 forDisplay:(BOOL)arg3;
- (void)dealloc;
- (id)init;
- (void)registerCommonServicesIfNecessary;
- (BOOL)worksWhenModal;
- (void)updateVisibilityOfServicesItemsForMenu:(id)arg1 isForDisplay:(BOOL)arg2;
- (void)populateMenuForUnavailableServices:(id)arg1;
- (BOOL)contentsNeedsUpdatingForMenu:(id)arg1;
- (BOOL)menuShowsKeyEquivalents;
- (id)menus;
- (id)menuContext;
- (unsigned long long)serviceEntryKinds;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

