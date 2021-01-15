//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

@class NSBannerView, NSButton, NSLayoutConstraint, NSMenu, NSMenuItem, NSSearchField, NSSegmentedControl, NSStackView, NSTextField;
@protocol NSFindPatternField;

__attribute__((visibility("hidden")))
@interface NSTextFinderBarView : NSView
{
    id _finder;
    id _container;
    NSBannerView *_bannerView;
    NSSearchField<NSFindPatternField> *_searchField;
    NSTextField<NSFindPatternField> *_replaceField;
    NSButton *_doneButton;
    NSButton *_replaceCheckbox;
    NSSegmentedControl *_forwardBackButtons;
    NSSegmentedControl *_replaceAllButtons;
    NSMenu *_replaceAllMenu;
    NSMenuItem *_ignoreCaseItem;
    NSMenuItem *_wrapAroundItem;
    NSMenuItem *_containsItem;
    NSMenuItem *_startsWithItem;
    NSMenuItem *_fullWordItem;
    NSMenuItem *_patternItem;
    NSMenuItem *_patternItemSeparator;
    NSLayoutConstraint *_collapseConstraint;
    NSStackView *_findRowStackView;
    NSStackView *_replaceRowStackView;
    BOOL _replaceMode;
    BOOL _useRegularControls;
    BOOL _drawsBackground;
}

- (void)_insertFindPattern:(id)arg1;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)performTextFinderAction:(id)arg1;
- (void)_setEnabledForward:(BOOL)arg1 back:(BOOL)arg2;
- (long long)_substringMatchType;
- (void)_setSubstringMatchType:(long long)arg1;
- (unsigned long long)_searchOptions;
- (void)_setSearchOptions:(unsigned long long)arg1;
- (id)_container;
- (void)_setTextFinder:(id)arg1;
- (id)_textFinder;
- (void)_doneButton:(id)arg1;
- (void)_toggleFindReplace:(id)arg1;
- (void)viewDidMoveToSuperview;
- (void)viewDidMoveToWindow;
- (void)viewWillMoveToWindow:(id)arg1;
- (id)_replaceField;
- (id)_searchField;
- (BOOL)_contiguousWithTitlebar;
- (unsigned long long)_dividerPosition;
- (void)_setReplaceMode:(BOOL)arg1;
- (id)_contentView;
- (void)_updateSubviews;
- (void)_updateReplaceUIVisibility;
- (void)_layoutBarSubviews;
- (void)_resizeIfNecessary;
- (double)_requiredHeight;
- (id)_nextKeyView;
- (id)_actionResponderFromView:(id)arg1;
- (void)_updateNextKeyViews;
- (void)_finishedMakingConnections;
- (void)dealloc;

@end

