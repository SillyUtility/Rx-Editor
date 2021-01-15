//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

@class CALayer, CAProxyLayer, NSCGSWindowBackdrop, NSDictionary, NSImage, NSString;

@interface NSVisualEffectView : NSView
{
    NSCGSWindowBackdrop *_cgsWindowBackdrop;
    CALayer *_materialLayerActive;
    CALayer *_materialLayerInactive;
    CAProxyLayer *_proxyLayer;
    long long _material;
    long long _internalMaterialType;
    long long _blendingMode;
    long long _state;
    NSImage *_cachedFillMaskImage;
    NSString *_groupName;
    NSDictionary *_coreUIOptions;
    NSDictionary *_coreUIMetadata;
    unsigned long long _zOrderDidChangeNotificationToken;
    CALayer *_darkenLayer;
    CALayer *_colorCopyLayer;
    CALayer *_backdropLayer;
    NSImage *_maskImage;
    unsigned int _clear:1;
    unsigned int _emphasized:1;
    unsigned int _appearsDarker:1;
    unsigned int _inheritsBlendGroup:1;
    unsigned int _needsClearProxy:1;
    unsigned int _usesMaterialPreferredAppearance:1;
    unsigned int _reservedFlags:26;
}

+ (void)endFreezingInWindow:(id)arg1;
+ (void)beginFreezingInWindow:(id)arg1;
+ (id)_representativeColorForMaterial:(long long)arg1 isActive:(BOOL)arg2;
+ (id)keyPathsForValuesAffecting_effectiveGroupName;
- (id)_stringValueForIntrospectorPropertyKey:(id)arg1;
- (id)_propertyKeysForIntrospector;
- (unsigned long long)_vibrantBlendingStyleForSubtree;
- (void)_updateVibrancy;
@property(retain) NSImage *maskImage;
- (id)_generateMaskImageWithCurrentFillColor;
- (void)setFrameSize:(struct CGSize)arg1;
- (void)_freeCachedMaskImages;
- (BOOL)_needsDarkening;
- (BOOL)_needsProxyLayer;
- (BOOL)_needsWindowBackdrop;
- (BOOL)_currentMaterialHasCGSMaterial;
- (void)layout;
- (void)geometryInWindowDidChange;
- (void)viewDidUnhide;
- (void)viewDidHide;
- (void)drawRect:(struct CGRect)arg1;
- (id)_currentFillColor;
- (BOOL)_useAccessibilityColors;
- (void)viewWillMoveToWindow:(id)arg1;
- (void)viewDidMoveToWindow;
- (void)setLayer:(id)arg1;
- (void)updateLayer;
- (BOOL)wantsUpdateLayer;
- (BOOL)wantsLayer;
- (void)_windowChangedKeyState;
- (void)_removeColorCopyLayerIfNeeded;
- (void)_updateColorCopyLayer;
- (id)debugDescription;
- (void)_removeDarkenLayerIfNeeded;
- (void)_updateDarkenLayer;
- (void)_updateCABackdropLayerGroupName;
- (void)_removeMaterialLayerIfNeeded;
- (void)_updateMaterialLayer;
- (id)_coreUIOptions;
@property long long vibrancyEffect;
- (void)_removeProxyLayerIfNeeded;
- (void)_updateProxyLayer;
- (void)_removeWindowBackdropIfNeeded;
- (void)_updateWindowBackdrop;
@property long long blendingMode;
- (void)_accessibilityRTChanged:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)_markDirtyIfHasAccelerationChanged;
- (struct CGRect)rectToClearBackingStore;
- (BOOL)_shouldUseActiveAppearance;
@property(readonly) long long interiorBackgroundStyle;
@property(readonly, copy) NSString *_effectiveGroupName;
@property(copy, setter=_setGroupName:) NSString *_groupName;
@property(setter=_setNeedsClearProxyLayer:) BOOL _needsClearProxyLayer;
@property(getter=_isClear, setter=_setClear:) BOOL _clear;
@property(setter=_setInternalMaterialType:) long long _internalMaterialType;
- (void)_reactToMaterialChangeDiscardingMaterialLayers:(BOOL)arg1 invalidatingPreferredAppearance:(BOOL)arg2;
- (id)_currentMaterialName;
- (void)_markDirty;
@property long long state;
@property BOOL appearsDarker;
@property BOOL inheritsBlendGroup;
@property(getter=isEmphasized) BOOL emphasized;
- (BOOL)emphasized;
- (void)viewDidChangeEffectiveAppearance;
@property long long material;
- (id)_preferredAppearance;
@property(nonatomic, setter=_setUsesMaterialPreferredAppearance:) BOOL _usesMaterialPreferredAppearance;
- (void)dealloc;

@end

