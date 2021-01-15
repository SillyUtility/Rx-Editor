//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSViewController.h>

@class NSError, NSMenu, NSTextField;

__attribute__((visibility("hidden")))
@interface NSDocumentNonModalAlertViewController : NSViewController
{
    NSTextField *_textField;
    NSError *_errorToDisplay;
    NSMenu *_menu;
}

@property(copy) NSError *errorToDisplay;
@property(retain) NSMenu *menu;
- (void)awakeFromNib;
- (void)layout;
- (void)dealloc;
- (id)init;

@end

