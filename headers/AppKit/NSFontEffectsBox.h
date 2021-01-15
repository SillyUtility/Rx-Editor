//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSBox.h>

#import <AppKit/NSToolbarDelegate-Protocol.h>

@class NSMutableArray, NSMutableDictionary, NSString;

__attribute__((visibility("hidden")))
@interface NSFontEffectsBox : NSBox <NSToolbarDelegate>
{
    id _blurSlider;
    id _opacitySlider;
    id _radiusSlider;
    id _angleDial;
    id _mainControlsBox;
    id _shadowControlsBox;
    id _mainEffectsBox;
    id _angleLabel;
    id _underlineButton;
    id _strikeButton;
    id _shadowOpacitySliderToolbarItem;
    id _shadowBlurSliderToolbarItem;
    id _shadowOffsetSliderToolbarItem;
    id _shadowAngleDialToolbarItem;
    id _shadowToggleButton;
    id _textColorButton;
    id _documentColorButton;
    NSMutableDictionary *_attributesToAdd;
    NSMutableArray *_attributesToRemove;
    id _febUnused[5];
    int _shadowBlur;
    int _colorState;
    struct __feblags {
        unsigned int showUnderline:1;
        unsigned int showStrikethrough:1;
        unsigned int showTextColor:1;
        unsigned int showDocumentColor:1;
        unsigned int showShadowEffects:1;
        unsigned int updatingAttributes:1;
        unsigned int reserved:26;
    } _febFlags;
}

- (id)toolbarAllowedItemIdentifiers:(id)arg1;
- (id)toolbarDefaultItemIdentifiers:(id)arg1;
- (void)_validateShadowEffect:(BOOL)arg1;
- (void)_validateDocumentColor:(BOOL)arg1;
- (void)_validateTextColor:(BOOL)arg1;
- (void)_validateStrikethrough:(BOOL)arg1;
- (void)_validateUnderline:(BOOL)arg1;
- (BOOL)_sendChangeAttributesActionIfSupported;
- (void)_sendCarbonNotificationFor:(unsigned long long)arg1 tags:(const unsigned int *)arg2 withValuePtrs:(const void **)arg3 andSizes:(const unsigned long long *)arg4;
- (void)_sendCarbonNotificationForTag:(unsigned int)arg1 withValuePtr:(const void *)arg2 andSize:(unsigned long long)arg3;
- (void *)carbonNotificationProc;
- (void)_toggleShadow:(id)arg1;
- (void)_openEffectsButton:(id)arg1;
- (long long)_lineStyleForLineStyleButton:(id)arg1;
- (long long)_strikethroughStyle;
- (long long)_underlineStyle;
- (void)_validateFontPanelFontAttributes:(id)arg1;
- (id)_documentBackgroundColor;
- (id)_foregroundColor;
- (void)_setAttributes:(id)arg1 isMultiple:(BOOL)arg2;
- (id)convertAttributes:(id)arg1;
- (id)_currentShadowForFont:(id)arg1;
- (BOOL)shadowsEnabled;
- (void)_orderFrontModalColorPanel;
- (void)_changeColorToColor:(id)arg1;
- (void)changeColor:(id)arg1;
- (void)_changeShadowBlur:(id)arg1;
- (void)_changeShadowAngle:(id)arg1;
- (void)_changeShadowOpacity:(id)arg1;
- (void)_changeDocumentColor:(id)arg1;
- (void)_changeTextColor:(id)arg1;
- (BOOL)_ignoreBadFirstResponders;
- (void)awakeFromNib;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

