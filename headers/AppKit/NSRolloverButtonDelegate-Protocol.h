//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSObject-Protocol.h>

@class NSRolloverButton;

@protocol NSRolloverButtonDelegate <NSObject>

@optional
- (void)setShowingCloseButton:(BOOL)arg1;
- (void)rolloverButtonDidResignFirstResponder:(NSRolloverButton *)arg1;
- (void)rolloverButtonDidBecomeFirstResponder:(NSRolloverButton *)arg1;
@end

