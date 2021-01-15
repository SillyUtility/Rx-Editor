//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSCell.h>

#import <AppKit/NSCoding-Protocol.h>
#import <AppKit/NSCopying-Protocol.h>

@class NSImage;

@interface NSImageCell : NSCell <NSCopying, NSCoding>
{
    id _controlView;
    struct _NSImageCellAnimationState *_animationState;
    NSImage *_scaledImage;
    struct __ICFlags {
        unsigned int _unused:21;
        unsigned int _animates:1;
        unsigned int _align:4;
        unsigned int _scale:3;
        unsigned int _style:3;
    } _icFlags;
}

+ (struct CGRect)_imageRectForDrawingImageOfAlignmentRectSize:(struct CGSize)arg1 inFrame:(struct CGRect)arg2 scaling:(unsigned long long)arg3 alignment:(unsigned long long)arg4 flipped:(BOOL)arg5;
+ (struct CGSize)_cellSizeAccountingForImageOfSize:(struct CGSize)arg1 frameStyle:(unsigned long long)arg2 flipped:(BOOL)arg3;
+ (struct CGRect)_drawingRectForBounds:(struct CGRect)arg1 frameStyle:(unsigned long long)arg2 flipped:(BOOL)arg3;
+ (void)initialize;
- (void)_animationTimerCallback:(id)arg1;
- (void)_stopAnimation;
- (void)_startAnimation;
- (void)_setAnimates:(BOOL)arg1;
- (BOOL)_animates;
- (void)_setContentTintColor:(id)arg1;
- (id)_contentTintColor;
- (id)controlView;
- (void)setControlView:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)setFormatter:(id)arg1;
- (BOOL)isOpaque;
- (BOOL)_needRedrawOnWindowChangedKeyState;
- (long long)interiorBackgroundStyle;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)_drawBorderStyleWithRect:(struct CGRect)arg1 inView:(id)arg2;
- (struct CGRect)focusRingMaskBoundsForFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)drawFocusRingMaskWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (int)_vibrancyBlendModeForControlView:(id)arg1;
- (struct __CFDictionary *)_newCUIGrayBezelDrawOptionsInView:(id)arg1;
- (BOOL)_wantsFocusRingForControlView:(id)arg1;
- (unsigned long long)hitTestForEvent:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (void)drawInteriorWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)_drawImageWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (BOOL)_shouldDrawWithContentTintColorInView:(id)arg1;
- (long long)_contentBacking;
- (void)_updateAppearanceContentStyle:(id)arg1 inView:(id)arg2;
- (long long)_interiorContentPresentationStateInView:(id)arg1;
- (long long)_interiorContentValueInView:(id)arg1;
- (long long)_interiorContentStateInView:(id)arg1;
- (unsigned long long)_currentImageStateForView:(id)arg1;
- (BOOL)_shouldClip;
- (struct CGRect)_imageRectForDrawing:(id)arg1 inFrame:(struct CGRect)arg2 inView:(id)arg3;
- (struct CGSize)_cellSizeAccountingForImage:(id)arg1 inControl:(id)arg2;
- (struct CGSize)cellSizeForBounds:(struct CGRect)arg1;
- (struct CGRect)drawingRectForBounds:(struct CGRect)arg1;
- (struct CGRect)titleRectForBounds:(struct CGRect)arg1;
- (struct CGRect)imageRectForBounds:(struct CGRect)arg1;
- (void)setImage:(id)arg1;
- (id)image;
- (void)setObjectValue:(id)arg1;
@property unsigned long long imageFrameStyle;
@property unsigned long long imageScaling;
@property unsigned long long imageAlignment;
- (void)setEditable:(BOOL)arg1;
- (BOOL)trackMouse:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 untilMouseUp:(BOOL)arg4;
- (void)highlight:(BOOL)arg1 withFrame:(struct CGRect)arg2 inView:(id)arg3;
- (void)_setContents:(id)arg1;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)copy;
- (void)_autoflipUnarchivedProperties;
- (id)initImageCell:(id)arg1;
- (id)init;
- (BOOL)_hasAccessibilityTitle;
- (id)accessibilityAuditLabel;
- (BOOL)accessibilityIsDescriptionAttributeSettable;
- (id)accessibilityDescriptionAttribute;
- (id)accessibilityRoleAttribute;
- (id)accessibilityAttributeNames;

@end

