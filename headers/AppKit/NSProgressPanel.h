//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSPanel.h>

@class NSButton, NSProgressIndicator, NSTextField;

@interface NSProgressPanel : NSPanel
{
    NSButton *_cancelButton;
    NSTextField *_captionTextField;
    NSProgressIndicator *_progressIndicator;
    id _cancellationDelegate;
    SEL _cancellationSelector;
    void *_cancellationContextInfo;
    BOOL _wasCancelled;
}

+ (id)progressPanelWithNibName:(id)arg1;
@property NSButton *cancelButton; // @synthesize cancelButton=_cancelButton;
@property NSProgressIndicator *progressIndicator; // @synthesize progressIndicator=_progressIndicator;
@property NSTextField *captionTextField; // @synthesize captionTextField=_captionTextField;
- (void)cancelButtonPressed:(id)arg1;
- (void)setCancellationDelegate:(id)arg1 wasCancelledSelector:(SEL)arg2 contextInfo:(void *)arg3;

@end

