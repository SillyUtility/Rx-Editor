//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

@class NSAlert, NSImageView, NSTextField;

__attribute__((visibility("hidden")))
@interface NSSavePanelAlertStyleContentView : NSView
{
    NSImageView *iconView;
    NSTextField *messageTextField;
    NSTextField *informativeMessageTextField;
    NSAlert *alert;
}

@property NSTextField *informativeMessageTextField; // @synthesize informativeMessageTextField;
@property NSTextField *messageTextField; // @synthesize messageTextField;
@property NSImageView *iconView; // @synthesize iconView;
- (void)setMessage:(id)arg1;
- (void)stopTimerForSpeaking;
- (void)startTimerForSpeaking;
- (void)_windowDidOrderOnScreen;
- (void)viewDidMoveToWindow;
- (void)viewWillMoveToWindow:(id)arg1;
- (void)cancelAlertSpeaking;
- (void)dealloc;

@end

