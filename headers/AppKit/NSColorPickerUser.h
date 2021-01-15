//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSColorPicker.h>

#import <AppKit/NSColorPickingCustom-Protocol.h>

@class NSMenuItem, NSMutableDictionary, NSPopUpButton, NSString, NSView;

__attribute__((visibility("hidden")))
@interface NSColorPickerUser : NSColorPicker <NSColorPickingCustom>
{
    NSView *_userPickerView;
    id tiffView;
    id reserved1;
    id renamePanelController;
    NSPopUpButton *palettePopUpButton;
    id reserved2;
    id optionsPopUp;
    BOOL bScaleOrNot;
    NSMutableDictionary *imageDictionary;
    id paste;
    id renameField;
    id defaultTiffImage;
    id removeField;
    NSString *currImageName;
    NSMenuItem *spectrumMenuItem;
}

@property(retain) NSView *userPickerView; // @synthesize userPickerView=_userPickerView;
- (void)remove:(id)arg1;
- (void)_remove:(id)arg1;
- (BOOL)_removeOrRename:(id)arg1;
- (void)paste:(id)arg1;
- (void)copy:(id)arg1;
- (void)rename:(id)arg1;
- (void)_rename:(id)arg1;
- (id)validateRename;
- (id)_popUpButton;
- (void)open:(id)arg1;
- (void)_open:(id)arg1;
- (void)_open:(id)arg1 fromImage:(id)arg2 withName:(id)arg3;
- (void)_addImage:(id)arg1 named:(id)arg2;
- (id)_newImageName:(id)arg1;
- (void)switchImage:(id)arg1;
- (void)_switchImage:(id)arg1 andUpdateColor:(BOOL)arg2;
- (BOOL)worksWhenModal;
- (void)_restoreMode;
- (void)_saveMode;
- (void)setColor:(id)arg1;
- (long long)currentMode;
- (BOOL)supportsMode:(long long)arg1;
- (id)buttonToolTip;
- (double)_insertionOrder;
- (id)provideNewView:(BOOL)arg1;
- (id)initWithPickerMask:(unsigned long long)arg1 colorPanel:(id)arg2;
- (BOOL)saveImageNamed:(id)arg1 andShowWarnings:(BOOL)arg2;
- (id)_shortNameFor:(id)arg1;
- (void)dealloc;
- (void)_setCurrImageName:(id)arg1;
- (id)_imageFromItemTitle:(id)arg1;

@end

