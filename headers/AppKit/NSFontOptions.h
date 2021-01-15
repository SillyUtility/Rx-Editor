//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSDictionary, NSMutableArray, NSMutableDictionary, NSString, NSTextView, NSWindow;

__attribute__((visibility("hidden")))
@interface NSFontOptions : NSObject
{
    id panel;
    id fontField;
    id fontColorWell;
    id backgroundColorWell;
    id favoritesPullDown;
    id kerningButton;
    id kerningSlider;
    id expansionButton;
    id expansionSlider;
    id baselineButton;
    id baselineSlider;
    id obliquenessButton;
    id obliquenessSlider;
    id shadowButton;
    id shadowHeightSlider;
    id shadowWidthSlider;
    id shadowBlurRadiusSlider;
    id strokeMatrix;
    id strokeColorWell;
    id strokeSlider;
    id underlineMatrix;
    id underlineColorWell;
    id underlineTypeButton;
    id underlineStylePopUp;
    id strikethroughMatrix;
    id strikethroughColorWell;
    id strikethroughTypeButton;
    id strikethroughStylePopUp;
    id optionsPanel;
    id optionsMatrix;
    id optionsButtons;
    id optionsPopUp;
    id optionsPreviewField;
    id optionsPreviewBackground;
    id optionsAttributesField;
    id optionsAddRemoveButton;
    id colorOptionsPanel;
    id colorOptionsFontColorWell;
    id colorOptionsBackgroundColorWell;
    id colorOptionsStrokeColorWell;
    id colorOptionsUnderlineColorWell;
    id colorOptionsStrikethroughColorWell;
    id colorOptionsStrokeMatrix;
    id colorOptionsStrokeSlider;
    id addFavoritePanel;
    id favoriteNameField;
    id includeFontButton;
    id includeRulerButton;
    id confirmAddFavoriteButton;
    id selectButton;
    id replaceFavoritePanel;
    id removeFavoritePanel;
    id removeFavoritePopUp;
    id selectPanel;
    id selectByFontFamilyButton;
    id selectByFontButton;
    id selectByCharStyleButton;
    id selectByParStyleButton;
    id selectWithinSelectionMatrix;
    NSMutableDictionary *_attributesToAdd;
    NSMutableArray *_attributesToRemove;
    NSMutableDictionary *_favoriteStyles;
    NSDictionary *_standardFavoriteStyles;
    NSMutableDictionary *_selectedAttributes;
    NSDictionary *_optionsAttributes;
    NSDictionary *_attributesForNewFavorite;
    NSString *_stringForOptions;
    NSString *_optionsAddTitle;
    NSString *_optionsRemoveTitle;
    struct {
        unsigned int isMultiple:1;
        unsigned int observingTextViewAppearance:1;
        unsigned int reserved:30;
    } _flags;
    NSWindow *_windowForSheets;
    NSWindow *_windowForOptions;
    NSTextView *_textViewForOptions;
    struct _NSRange _rangeForOptions;
    NSWindow *_windowForColorOptions;
    struct CGRect _previewRect;
}

+ (id)sharedFontOptions;
- (void)selectAllInView:(id)arg1 selectionOnly:(BOOL)arg2 fontFamily:(BOOL)arg3 font:(BOOL)arg4 characterStyle:(BOOL)arg5 paragraphStyle:(BOOL)arg6;
- (void)sheetDidEnd:(id)arg1 returnCode:(long long)arg2 contextInfo:(void *)arg3;
- (void)removeFavoriteInWindow:(id)arg1;
- (void)addFavoriteInWindow:(id)arg1;
- (void)addFavorite;
- (void)cancelSheet:(id)arg1;
- (void)confirmSheet:(id)arg1;
- (void)controlTextDidChange:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (void)changeOptionsPanelSettings:(id)arg1;
- (void)selectNextRangeForward:(BOOL)arg1;
- (void)selectFarthestRangeForward:(BOOL)arg1;
- (void)selectDefaultRange;
- (id)stringForRange:(struct _NSRange)arg1;
- (void)modifyOptionsViaPanel:(id)arg1;
- (id)convertAttributes:(id)arg1;
- (id)optionsAttributes;
- (void)setOptionsAttributes:(id)arg1 string:(id)arg2;
- (id)selectedAttributes;
- (void)setSelectedAttributes:(id)arg1 isMultiple:(BOOL)arg2;
- (BOOL)textView:(id)arg1 shouldSetColor:(id)arg2;
- (void)orderFrontFontPanel:(id)arg1;
- (void)orderFrontStylesPanelInWindow:(id)arg1 textView:(id)arg2;
- (void)orderFrontStylesPanel:(id)arg1;
- (BOOL)getStylesPanelTextView:(id *)arg1 window:(id *)arg2;
- (void)orderFrontFontOptionsPanel:(id)arg1;
- (void)orderFrontColorOptionsPanelInWindow:(id)arg1;
- (void)updateFavoritesUI;
- (id)favoriteAttributesForName:(id)arg1;
- (id)favoriteAttributesNames;
- (void)updateColorOptionsUI;
- (void)updateOptionsUI;
- (id)displayStringsForParagraphStyle:(id)arg1;
- (id)displayStringsForAttributes:(id)arg1 includeBoldItalic:(BOOL)arg2;
- (void)updateUI;
- (void)enableAll:(BOOL)arg1;
- (void)dealloc;
- (void)loadUI;
- (id)init;
- (void)updateFavoritesFromDefaults;
- (void)saveFavoritesToDefaults;
- (id)storedAttributes;

@end

