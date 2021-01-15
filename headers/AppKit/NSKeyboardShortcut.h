//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCopying-Protocol.h>

@class NSString;

@interface NSKeyboardShortcut : NSObject <NSCopying>
{
    NSString *_keyEquivalent;
    unsigned long long _modifierMask;
}

+ (id)emptyShortcut;
+ (id)shortcutWithPreferencesEncoding:(id)arg1;
+ (id)shortcutWithKeyEquivalent:(id)arg1 modifierMask:(unsigned long long)arg2;
@property(readonly) unsigned long long modifierMask; // @synthesize modifierMask=_modifierMask;
@property(readonly) NSString *keyEquivalent; // @synthesize keyEquivalent=_keyEquivalent;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;
- (void)dealloc;
@property(readonly) NSString *preferencesEncoding;
@property(readonly) NSString *localizedModifierMaskDisplayName;
- (BOOL)_keyEquivalentIsUpperCase;
@property(readonly) NSString *localizedKeyEquivalentDisplayName;
- (id)localizedExtendedDisplayName:(BOOL)arg1;
@property(readonly) NSString *localizedDisplayName;
- (BOOL)isFunctionKey;
- (BOOL)isEmpty;
- (id)initWithKeyEquivalent:(id)arg1 modifierMask:(unsigned long long)arg2;

@end

