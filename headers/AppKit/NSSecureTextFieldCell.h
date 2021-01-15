//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSTextFieldCell.h>

@class NSData;

@interface NSSecureTextFieldCell : NSTextFieldCell
{
    BOOL _echosBullets;
}

+ (id)_sharedSecureFieldEditor;
+ (void)initialize;
- (id)initWithCoder:(id)arg1;
- (void)drawInteriorWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)_drawForegroundOfTextLayer;
- (BOOL)wantsUpdateLayerInView:(id)arg1;
- (id)_bulletStringForString:(id)arg1;
@property BOOL echosBullets;
- (id)initTextCell:(id)arg1;
- (unsigned short)_bulletCharacter;
- (void)_setBulletCharacter:(unsigned short)arg1;
- (void)selectWithFrame:(struct CGRect)arg1 inView:(id)arg2 editor:(id)arg3 delegate:(id)arg4 start:(long long)arg5 length:(long long)arg6;
- (void)editWithFrame:(struct CGRect)arg1 inView:(id)arg2 editor:(id)arg3 delegate:(id)arg4 event:(id)arg5;
- (id)setUpFieldEditorAttributes:(id)arg1;
- (id)fieldEditorForView:(id)arg1;
- (struct _NSRange)textView:(id)arg1 willChangeSelectionFromCharacterRange:(struct _NSRange)arg2 toCharacterRange:(struct _NSRange)arg3;
- (BOOL)validatePasswordSessionValue:(id)arg1;
@property(readonly) NSData *passwordSessionValue; // @dynamic passwordSessionValue;
@property(getter=isKernelSecureMode) BOOL kernelSecureMode; // @dynamic kernelSecureMode;
- (const void *)_securePromptSession;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (id)accessibilityChildrenAttribute;
- (BOOL)accessibilityIsValueDescriptionAttributeSettable;
- (id)accessibilityValueDescriptionAttribute;
- (id)accessibilityValueAttribute;
- (BOOL)accessibilityIsSubroleAttributeSettable;
- (id)accessibilitySubroleAttribute;
- (id)accessibilityParameterizedAttributeNames;
- (id)accessibilityAttributeNames;

@end

