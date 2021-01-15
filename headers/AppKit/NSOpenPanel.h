//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSSavePanel.h>

@class NSArray;

@interface NSOpenPanel : NSSavePanel
{
}

+ (id)openPanel;
- (void)delegateShouldCreateNewDocumentAtURL:(id)arg1;
- (void)delegateRequestNewDocumentNameWithReply:(CDUnknownBlockType)arg1;
@property(getter=isAccessoryViewDisclosed) BOOL accessoryViewDisclosed;
- (BOOL)isMovable;
- (BOOL)canBecomeMainWindow;
- (BOOL)preventsApplicationTerminationWhenModal;
- (void)beginForDirectory:(id)arg1 file:(id)arg2 types:(id)arg3 modelessDelegate:(id)arg4 didEndSelector:(SEL)arg5 contextInfo:(void *)arg6;
@property BOOL canDownloadUbiquitousContents;
@property BOOL canResolveUbiquitousConflicts;
@property BOOL canChooseFiles;
@property BOOL allowsMultipleSelection;
@property BOOL canChooseDirectories;
@property BOOL resolvesAliases;
@property(readonly, copy) NSArray *URLs;
- (id)filenames;
- (BOOL)_isTitleHidden;
- (struct CGRect)frameRectForContentRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2;
- (BOOL)_canAddUnderTitlebarViews;
- (struct CGRect)contentRectForFrameRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2;
- (struct CGRect)startRectForSheet:(id)arg1;
- (id)initWithContentRect:(struct CGRect)arg1 styleMask:(unsigned long long)arg2 backing:(unsigned long long)arg3 defer:(BOOL)arg4;
- (unsigned long long)styleMaskForHostWindow;
- (void)commonPrep:(CDUnknownBlockType)arg1 runningAsASheet:(BOOL)arg2 hostWindow_runningAsASheet:(BOOL)arg3;
- (void)_setDefaultBridgeValues;
- (void)configureContentView:(id)arg1;

@end

