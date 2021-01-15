//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMenu, NSMutableArray;

__attribute__((visibility("hidden")))
@interface NSDebugMenu : NSObject
{
    NSMutableArray *_menuItemProviders;
    NSMenu *_debugMenu;
}

+ (void)unregisterMenuItemProvider:(Class)arg1;
+ (void)registerMenuItemProvider:(Class)arg1;
+ (id)_menuItemProviderClasses;
+ (id)appKitDebugMenuItemProviders;
+ (id)createDebugMenuItem;
+ (id)debugMenuInMenu:(id)arg1;
- (void)dealloc;
@property(readonly) NSMenu *debugMenu;
- (id)init;

@end

