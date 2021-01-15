//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSControl.h>

#import <AppKit/NSUserInterfaceCompression-Protocol.h>

@class NSColor, NSUserInterfaceCompressionOptions;

@interface NSSegmentedControl : NSControl <NSUserInterfaceCompression>
{
    id _scAux;
}

+ (Class)_classToCheckForRequiresConstraintBasedLayout;
+ (void)initialize;
+ (id)segmentedControlWithSegmentImages:(id)arg1 trackingMode:(unsigned long long)arg2 target:(id)arg3 action:(SEL)arg4;
+ (id)segmentedControlWithSegmentLabels:(id)arg1 trackingMode:(unsigned long long)arg2 target:(id)arg3 action:(SEL)arg4;
+ (id)segmentedControlWithImages:(id)arg1 trackingMode:(unsigned long long)arg2 target:(id)arg3 action:(SEL)arg4;
+ (id)segmentedControlWithLabels:(id)arg1 trackingMode:(unsigned long long)arg2 target:(id)arg3 action:(SEL)arg4;
+ (id)_segmentedControlWithTrackingMode:(unsigned long long)arg1 target:(id)arg2 action:(SEL)arg3;
- (void)_setBackgroundStyleForSubtree:(long long)arg1;
- (struct NSEdgeInsets)touchBarHitTestInsets;
- (id)_insetMitigationTreatment;
@property(readonly, copy) NSUserInterfaceCompressionOptions *activeCompressionOptions;
- (struct CGSize)minimumSizeWithPrioritizedCompressionOptions:(id)arg1;
- (void)compressWithPrioritizedCompressionOptions:(id)arg1;
- (id)_supportedOptionsFromPrioritizedOptions:(id)arg1;
- (void)setHidesUnselectedLabelsWhenNecessary:(BOOL)arg1;
- (BOOL)hidesUnselectedLabelsWhenNecessary;
@property(copy) NSColor *selectedSegmentBezelColor;
@property(readonly) double doubleValueForSelectedSegment;
@property unsigned long long trackingMode;
@property(getter=isSpringLoaded) BOOL springLoaded;
- (long long)_badgeValueForSegment:(long long)arg1;
- (void)_setBadgeValue:(long long)arg1 forSegment:(long long)arg2;
- (BOOL)_showsBadgeForSegment:(long long)arg1;
- (void)_setShowsBadge:(BOOL)arg1 forSegment:(long long)arg2;
- (void)_updateLayerMasksToBoundsFromView;
- (id)_highlightColorForCell:(id)arg1;
- (CDStruct_6b6ad735)_baselineOffsetsAtSize:(struct CGSize)arg1;
- (double)baselineOffsetFromBottom;
- (BOOL)_hasExtra10_11BordersInToolbars;
- (struct NSEdgeInsets)alignmentRectInsets;
- (BOOL)_inToolbar;
- (void)moveDown:(id)arg1;
@property long long segmentStyle;
- (void)viewDidMoveToWindow;
- (void)viewDidMoveToSuperview;
- (void)_updateHeightToReflectNewWindowStyleIfNecessary;
- (BOOL)showsMenuIndicatorForSegment:(long long)arg1;
- (void)setShowsMenuIndicator:(BOOL)arg1 forSegment:(long long)arg2;
- (id)toolTipForSegment:(long long)arg1;
- (long long)tagForSegment:(long long)arg1;
- (void)setTag:(long long)arg1 forSegment:(long long)arg2;
- (void)setToolTip:(id)arg1 forSegment:(long long)arg2;
- (long long)alignmentForSegment:(long long)arg1;
- (void)setAlignment:(long long)arg1 forSegment:(long long)arg2;
- (BOOL)isEnabledForSegment:(long long)arg1;
- (void)setEnabled:(BOOL)arg1 forSegment:(long long)arg2;
- (BOOL)isSelectedForSegment:(long long)arg1;
- (void)setSelected:(BOOL)arg1 forSegment:(long long)arg2;
- (id)menuForSegment:(long long)arg1;
- (void)setMenu:(id)arg1 forSegment:(long long)arg2;
- (id)labelForSegment:(long long)arg1;
- (void)setLabel:(id)arg1 forSegment:(long long)arg2;
- (void)setImageScaling:(unsigned long long)arg1 forSegment:(long long)arg2;
- (unsigned long long)imageScalingForSegment:(long long)arg1;
- (id)alternateImageForSegment:(long long)arg1;
- (void)setAlternateImage:(id)arg1 forSegment:(long long)arg2;
- (id)imageForSegment:(long long)arg1;
- (void)setImage:(id)arg1 forSegment:(long long)arg2;
- (double)widthForSegment:(long long)arg1;
- (void)setWidth:(double)arg1 forSegment:(long long)arg2;
@property long long segmentDistribution;
@property(readonly) long long indexOfSelectedItem;
- (BOOL)selectSegmentWithTag:(long long)arg1;
- (long long)selectedTag;
@property long long selectedSegment;
@property long long segmentCount;
- (void)springLoadingExited:(id)arg1;
- (void)springLoadingHighlightChanged:(id)arg1;
- (void)springLoadingActivated:(BOOL)arg1 draggingInfo:(id)arg2;
- (unsigned long long)springLoadingUpdated:(id)arg1;
- (unsigned long long)springLoadingEntered:(id)arg1;
- (void)updateConstraints;
- (struct CGSize)_defaultContentCompressionResistancePriorities;
- (void)_updateConstraint:(id *)arg1 forAnchor:(id)arg2 atMinSize:(double)arg3 priority:(double)arg4;
- (struct CGSize)intrinsicContentSize;
- (struct CGSize)minimumIntrinsicContentSize;
- (void)viewDidEndLiveResize;
- (void)_windowChangedKeyState;
- (void)_setWindow:(id)arg1;
- (void)_updateMenuUniquing;
- (void)moveRight:(id)arg1;
- (void)moveLeft:(id)arg1;
- (BOOL)acceptsFirstMouse:(id)arg1;
- (struct CGRect)_opaqueRectForWindowMoveWhenInTitlebar;
- (id)_makeSCAuxIfNeeded;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (BOOL)isFlipped;
- (id)_descriptionForTouchBarLogging;
- (void)_setSpringLoadsOnDrag:(BOOL)arg1;
- (BOOL)_springLoadsOnDrag;
- (id)ns_widgetType;

@end

