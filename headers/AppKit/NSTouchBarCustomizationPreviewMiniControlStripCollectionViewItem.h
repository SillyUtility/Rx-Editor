//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSTouchBarCustomizationPreviewCollectionViewItem.h>

@class CALayer;

__attribute__((visibility("hidden")))
@interface NSTouchBarCustomizationPreviewMiniControlStripCollectionViewItem : NSTouchBarCustomizationPreviewCollectionViewItem
{
    CALayer *_leftCornerRadiusMask;
    CALayer *_rightCornerRadiusMask;
}

- (id)preferredViewAppearanceShowingAppState:(BOOL)arg1;
- (void)applyLayoutAttributes:(id)arg1;
- (void)_updateJiggle;
- (void)loadView;

@end

