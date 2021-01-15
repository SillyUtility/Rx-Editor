//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSString, OSALanguagePrivate;

@interface OSALanguage : NSObject
{
    OSALanguagePrivate *_private;
}

+ (void)setDefaultLanguage:(id)arg1;
+ (id)defaultLanguage;
+ (id)languageForScriptDataDescriptor:(id)arg1;
+ (id)languageForName:(id)arg1;
+ (id)availableLanguages;
+ (id)finalizeDispatchQueue;
+ (id)languageForSubType:(unsigned int)arg1;
+ (id)languageForScript:(id)arg1;
+ (struct ComponentInstanceRecord *)defaultAppleScriptComponentInstance;
+ (struct ComponentInstanceRecord *)defaultComponentInstance;
+ (id)genericComponentInstance;
@property(readonly, getter=isThreadSafe) BOOL threadSafe;
@property(readonly) unsigned long long features;
@property(readonly) unsigned int manufacturer;
@property(readonly) unsigned int subType;
@property(readonly) unsigned int type;
@property(readonly, copy) NSString *version;
@property(readonly, copy) NSString *info;
@property(readonly, copy) NSString *name;
@property(readonly) struct ComponentInstanceRecord *componentInstance;
- (id)sharedLanguageInstance;
- (void)dealloc;
- (id)initWithComponent:(struct ComponentRecord *)arg1;
- (BOOL)supportsEventHandling;
- (BOOL)supportsDialects;
- (BOOL)supportsConvenience;
- (BOOL)supportsRecording;
- (BOOL)supportsAESending;
- (BOOL)supportsAECoercion;
- (BOOL)supportsGetSource;
- (BOOL)supportsCompiling;
- (struct ComponentRecord *)component;

@end

