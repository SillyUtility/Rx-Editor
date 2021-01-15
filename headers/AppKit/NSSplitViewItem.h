//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSAnimatablePropertyContainer-Protocol.h>
#import <AppKit/NSAppearanceCustomization-Protocol.h>
#import <AppKit/NSCoding-Protocol.h>

@class NSAppearance, NSDictionary, NSString, NSViewController;

@interface NSSplitViewItem : NSObject <NSAppearanceCustomization, NSAnimatablePropertyContainer, NSCoding>
{
    id _splitViewItemPrivateData;
    struct {
        unsigned int _collapsed:1;
        unsigned int _canCollapse:1;
        unsigned int _isOverlaid:1;
        unsigned int _revealsOnEdgeHoverInFullscreen:1;
        unsigned int _springLoaded:1;
        unsigned int _forceWithinWindowBlending:1;
        unsigned int _reserved:26;
    } _flags;
}

+ (id)defaultAnimationForKey:(id)arg1;
+ (id)keyPathsForValuesAffectingEffectiveCollapseBehavior;
+ (BOOL)automaticallyNotifiesObserversOfCollapsed;
+ (id)keyPathsForValuesAffectingSidebar;
+ (id)contentListWithViewController:(id)arg1;
+ (id)sidebarWithViewController:(id)arg1;
+ (id)splitViewItemWithViewController:(id)arg1;
- (id)animationForKey:(id)arg1;
@property(copy) NSDictionary *animations;
- (id)animator;
- (Class)_animatorClass;
- (void)_setForceWithinWindowBlending:(BOOL)arg1;
- (BOOL)_forceWithinWindowBlending;
- (void)_setHasBaseVibrancyEffect:(BOOL)arg1;
- (BOOL)_hasBaseVibrancyEffect;
@property(getter=isSpringLoaded) BOOL springLoaded;
- (BOOL)hasUserSetSize;
- (void)setHasUserSetSize:(BOOL)arg1;
- (void)setRevealsOnEdgeHoverInFullscreen:(BOOL)arg1;
- (BOOL)revealsOnEdgeHoverInFullscreen;
- (void)setAutoHidesWhenFullscreen:(BOOL)arg1;
- (BOOL)autoHidesWhenFullscreen;
- (BOOL)isAnimating;
- (void)_markAnimationEnd;
- (void)_markAnimationStart;
- (void)setPrefersImplicitAnimations:(BOOL)arg1;
- (BOOL)prefersImplicitAnimations;
- (BOOL)isOverlaid;
- (void)setOverlaid:(BOOL)arg1;
- (BOOL)_canLiveCollapse;
@property double preferredThicknessFraction;
- (void)setPreferredSizeRatio:(double)arg1;
- (double)preferredSizeRatio;
@property double automaticMaximumThickness;
- (void)setAutomaticMaximumSize:(double)arg1;
- (double)automaticMaximumSize;
@property double maximumThickness;
- (void)setMaximumSize:(double)arg1;
- (double)maximumSize;
@property double minimumThickness;
- (void)setMinimumSize:(double)arg1;
- (double)minimumSize;
- (BOOL)canOverlay;
- (BOOL)_wantsMaterialBackground;
- (float)_effectiveHoldingPriority;
- (id)_overrideHoldingPriority;
- (void)_setOverrideHoldingPriority:(id)arg1;
@property float holdingPriority;
- (id)_splitViewController;
- (void)_uncollapsePreferringOverlay;
- (void)setPrefersPreservingSiblingSizesOnCollapse:(BOOL)arg1;
- (BOOL)prefersPreservingSiblingSizesOnCollapse;
- (long long)effectiveCollapseBehavior;
@property long long collapseBehavior;
- (void)_didChangeCollapsed;
- (void)_willChangeCollapsed;
@property(getter=isCollapsed) BOOL collapsed;
- (void)_setCollapsed:(BOOL)arg1;
- (void)_setCanCollapseFromWindowResize:(BOOL)arg1;
- (BOOL)_canCollapseFromWindowResize;
- (void)setCanCollapseFromWindowResize:(BOOL)arg1;
- (BOOL)canCollapseFromWindowResize;
@property BOOL canCollapse;
@property(retain) NSViewController *viewController;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;
- (id)init;
- (BOOL)isSidebar;
- (void)setSidebar:(BOOL)arg1;
@property(readonly) long long behavior;
- (void)setBehavior:(long long)arg1;
@property(readonly) NSAppearance *effectiveAppearance;
@property(retain) NSAppearance *appearance;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

