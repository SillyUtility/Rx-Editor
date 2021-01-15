//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

@interface _NSConstraintBasedLayoutHostingView : NSView
{
    NSView *_hostedView;
    BOOL _hasAddedConstraints;
}

+ (BOOL)requiresConstraintBasedLayout;
- (struct CGSize)_layoutSizeThatFits:(struct CGSize)arg1 fixedAxes:(unsigned long long)arg2;
- (void)sizeToFit;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (CDStruct_6b6ad735)_baselineOffsetsAtSize:(struct CGSize)arg1;
- (BOOL)_layoutHeightDependsOnWidth;
- (struct NSEdgeInsets)alignmentRectInsets;
- (void)_setFrameWithAlignmentRect:(struct CGRect)arg1;
- (void)_layoutMetricsInvalidatedForHostedView;
- (void)constraintsDidChangeInEngine:(id)arg1;
- (void)_informContainerThatSubviewsNeedUpdateConstraints;
- (void)_intrinsicContentSizeInvalidatedForChildView:(id)arg1;
- (void)willRemoveSubview:(id)arg1;
- (void)updateConstraints;
@property(retain) NSView *hostedView;
- (void)dealloc;
- (id)initWithHostedView:(id)arg1;

@end

