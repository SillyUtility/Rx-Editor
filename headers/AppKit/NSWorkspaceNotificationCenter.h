//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSNotificationCenter.h>

@class NSHashTable, NSLock, NSWorkspace;

__attribute__((visibility("hidden")))
@interface NSWorkspaceNotificationCenter : NSNotificationCenter
{
    NSWorkspace *_workspace;
    NSLock *_workspaceLock;
    struct NSWorkspaceNotificationCenterSubsystemContext_t _subsystemContexts[20];
    NSHashTable *_notificationObservers[25];
}

- (void)_menuBarDidChangeAppearance:(id)arg1;
- (void)_switchControlStatusDidChange:(id)arg1;
- (void)_voiceOverStatusDidChange:(id)arg1;
- (void)_accessibilityDisplaySettingsDidChange:(id)arg1;
- (void)_workspaceDidResignActive:(id)arg1;
- (void)_workspaceDidBecomeActive:(id)arg1;
- (void)_workspaceDidResignOrBecomeActive:(id)arg1;
- (unsigned int)connectionID;
- (BOOL)_checkForObserversOfSubsystem:(int)arg1;
- (id)addObserverForName:(id)arg1 object:(id)arg2 queue:(id)arg3 usingBlock:(CDUnknownBlockType)arg4;
- (void)removeObserver:(id)arg1 name:(id)arg2 object:(id)arg3;
- (void)addObserver:(id)arg1 selector:(SEL)arg2 name:(id)arg3 object:(id)arg4;
- (void)_addOrRemoveObserver:(id)arg1 forName:(id)arg2 isAdding:(BOOL)arg3;
- (void)_addOrRemoveObserverForAllNotifications:(id)arg1 isAdding:(BOOL)arg2;
- (BOOL)hasObserversForNotificationName:(id)arg1;
- (void)_destroyAllUnobservedSubsystems;
- (BOOL)_destroySubsystemIfUnobserved:(int)arg1;
- (void)_createSubsystemIfNecessary:(int)arg1;
- (id)workspace;
- (void)dealloc;
- (id)initWithWorkspace:(id)arg1;

@end

