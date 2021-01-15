//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

@interface NSScrubberArrangedView : NSView
{
    struct os_unfair_lock_s _flagLock;
    unsigned int _selected:1;
    unsigned int _highlighted:1;
}

+ (id)keyPathsForValuesInvalidatingDisplay;
- (id)_preferredAppearance;
- (void)applyLayoutAttributes:(id)arg1;
@property(getter=isHighlighted) BOOL highlighted;
@property(getter=isSelected) BOOL selected;
- (void)_arrangedViewCommonInit;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

