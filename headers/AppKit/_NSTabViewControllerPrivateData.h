//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableArray;
@protocol NSTabViewControllerUIProvider, NSTabViewControllerWindowTabsDelegate;

__attribute__((visibility("hidden")))
@interface _NSTabViewControllerPrivateData : NSObject
{
    long long _selectedTabViewItemIndex;
    unsigned long long _transitionOptions;
    long long _tabStyle;
    NSMutableArray *_tabViewItems;
    id <NSTabViewControllerUIProvider> _UIProvider;
    id <NSTabViewControllerWindowTabsDelegate> _windowTabsDelegate;
    struct {
        unsigned int settingTabViewItems:1;
        unsigned int canPropagateSelectedChildViewControllerTitle:1;
        unsigned int ibWillSetTabViewItems:1;
        unsigned int preventInsertAndRemoveChildViewControllersFromSendingKVO:1;
        unsigned int _reserved:28;
    } _flags;
}

@property(retain) id <NSTabViewControllerUIProvider> UIProvider; // @synthesize UIProvider=_UIProvider;
@property long long tabStyle; // @synthesize tabStyle=_tabStyle;
@property unsigned long long transitionOptions; // @synthesize transitionOptions=_transitionOptions;
@property long long selectedTabViewItemIndex; // @synthesize selectedTabViewItemIndex=_selectedTabViewItemIndex;
@property(retain) NSMutableArray *tabViewItems; // @synthesize tabViewItems=_tabViewItems;
- (void)dealloc;

@end

