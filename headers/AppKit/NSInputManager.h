//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSTextInput-Protocol.h>

@class NSImage, NSString;

@interface NSInputManager : NSObject <NSTextInput>
{
    id _currentClient;
    id _server;
    id _bundleObj;
    id _keybindings;
    NSString *_trueName;
    NSString *_connectionName;
    NSString *_hostName;
    NSString *_procToExec;
    NSString *_visibleName;
    NSString *_bundleName;
    NSString *_language;
    NSImage *_image;
    unsigned int _flags;
    NSString *_keyBindingsName;
}

+ (void)installInputManagerMenu:(id)arg1;
+ (BOOL)worksWhenModal;
+ (void)cycleToNextInputServerInLanguage:(id)arg1;
+ (void)cycleToNextInputLanguage:(id)arg1;
+ (id)currentInputManager;
+ (void)setCurrentInputManager:(id)arg1;
+ (void)initialize;
+ (id)_nextInputManagerInScript:(id)arg1;
+ (id)_inputManagerInNextScript:(id)arg1;
+ (void)_switchToPlatformInput:(id)arg1;
+ (void)_terminate:(id)arg1;
- (unsigned long long)characterIndexForPoint:(struct CGPoint)arg1;
- (long long)conversationIdentifier;
- (id)attributedSubstringFromRange:(struct _NSRange)arg1;
- (struct _NSRange)markedRange;
- (struct _NSRange)selectedRange;
- (struct CGRect)firstRectForCharacterRange:(struct _NSRange)arg1;
- (id)validAttributesForMarkedText;
- (void)unmarkText;
- (BOOL)hasMarkedText;
- (void)getMarkedText:(id *)arg1 selectedRange:(struct _NSRange *)arg2;
- (void)setMarkedText:(id)arg1 selectedRange:(struct _NSRange)arg2;
- (void)doCommandBySelector:(SEL)arg1;
- (void)insertText:(id)arg1;
- (id)_trueName;
- (id)description;
- (void)_terminate;
- (void)dealloc;
- (id)image;
- (id)language;
- (BOOL)wantsToHandleMouseEvents;
- (BOOL)wantsToDelayTextChangeNotifications;
- (id)bundleObject;
- (id)server;
- (void)markedTextSelectionChanged:(struct _NSRange)arg1 client:(id)arg2;
- (void)markedTextAbandoned:(id)arg1;
- (void)doCommandBySelector:(SEL)arg1 client:(id)arg2;
- (void)insertText:(id)arg1 client:(id)arg2;
- (BOOL)handleMouseEvent:(id)arg1;
- (BOOL)isEnabled;
- (BOOL)wantsToInterpretAllKeystrokes;
- (id)localizedInputManagerName;
- (void)activateInputManagerFromMenu:(id)arg1;
- (void)_setCurrentClient:(id)arg1;
- (id)_currentClient;
- (void)_senderIsInvalid:(id)arg1;
- (id)_keyBindingManager;
- (void)_loadKeyboardBindings;
- (void)_loadBundle;
- (BOOL)_validateBundleSecurity;
- (void)_activateServer;
- (id)initWithName:(id)arg1 host:(id)arg2;
- (BOOL)worksWhenModal;
- (BOOL)_isActivated;
- (BOOL)_setActivationState:(BOOL)arg1;

@end

