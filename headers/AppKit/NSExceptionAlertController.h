//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSWindowController.h>

@class NSButton, NSLayoutConstraint, NSString, NSView;

__attribute__((visibility("hidden")))
@interface NSExceptionAlertController : NSWindowController
{
    NSView *_expandedView;
    NSButton *_showDetailsButton;
    NSLayoutConstraint *_heightCollapseConstraint;
    NSString *_exceptionMessage;
    struct CGSize _previousSize;
    BOOL _showingDetails;
}

@property(retain) NSLayoutConstraint *heightCollapseConstraint; // @synthesize heightCollapseConstraint=_heightCollapseConstraint;
@property(retain) NSButton *showDetailsButton; // @synthesize showDetailsButton=_showDetailsButton;
@property(retain) NSView *expandedView; // @synthesize expandedView=_expandedView;
@property BOOL showingDetails; // @synthesize showingDetails=_showingDetails;
@property(copy) NSString *exceptionMessage; // @synthesize exceptionMessage=_exceptionMessage;
- (void)windowWillClose:(id)arg1;
- (struct CGSize)windowWillResize:(id)arg1 toSize:(struct CGSize)arg2;
- (void)btnShowDetailsClicked:(id)arg1;
- (void)btnClicked:(id)arg1;
- (long long)runModal;
- (void)windowDidLoad;
- (void)dealloc;
- (id)init;

@end

