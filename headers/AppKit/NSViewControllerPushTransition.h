//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSViewControllerPresentationAnimatorObject.h>

@class NSBox, NSView;

@interface NSViewControllerPushTransition : NSViewControllerPresentationAnimatorObject
{
    NSView *_dimmingView;
    NSBox *_boxView;
}

- (void)animateDismissalOfViewController:(id)arg1 fromViewController:(id)arg2;
- (void)animatePresentationOfViewController:(id)arg1 fromViewController:(id)arg2;

@end

