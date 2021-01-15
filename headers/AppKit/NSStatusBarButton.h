//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSButton.h>

@interface NSStatusBarButton : NSButton
{
}

+ (void)initialize;
- (void)setImage:(id)arg1;
- (id)_statusItem;
- (void)rightMouseDown:(id)arg1;
- (void)setDoubleAction:(SEL)arg1;
- (SEL)doubleAction;
- (struct NSEdgeInsets)selectionInset;
- (void)setSelectionInset:(struct NSEdgeInsets)arg1;
- (void)setLooksDisabled:(BOOL)arg1;
- (BOOL)looksDisabled;
@property BOOL appearsDisabled;
- (void)setStatusMenu:(id)arg1;
- (id)statusMenu;
- (id)initWithFrame:(struct CGRect)arg1 inStatusBar:(id)arg2;
- (void)setBackgroundStyle:(long long)arg1;

@end

