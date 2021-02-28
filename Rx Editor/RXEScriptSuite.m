//
//  RXEScriptSuite.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <SillyLog/SillyLog.h>

#import "RXEScriptSuite.h"
#import "RXEScriptableApp.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"

@implementation RXEScriptBaseObject

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector
{
    NSString *selName;
    char *t1, *t2, *t3, *t4;
    char sig[32];

    if ([self respondsToSelector:aSelector])
        return [super methodSignatureForSelector:aSelector];

    selName = NSStringFromSelector(aSelector);
    if ([selName hasPrefix:@"add"]) {
        t1 = @encode(void);
        t2 = @encode(id);
        t3 = @encode(SEL);
        t4 = @encode(id);
        sprintf(sig, "%s%s%s%s", t1, t2, t3, t4);
        return [NSMethodSignature signatureWithObjCTypes:(const char *)sig];
    }

    return [super methodSignatureForSelector:aSelector];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation
{
    SEL sel;
    NSString *selName;

    sel = [anInvocation selector];
    selName = NSStringFromSelector(sel);

    SLYWarn(@"%@ doesn't respond to %@", self, selName);
}

@end

@implementation RXEScriptTypeDefinition

- (BOOL)isClass
{
    return NO;
}

- (BOOL)isEnumeration
{
    return NO;
}

- (BOOL)isRecordType
{
    return NO;
}

- (BOOL)isValueType
{
    return NO;
}

- (BOOL)isComplexType
{
    return NO;
}

@end

@implementation RXEScriptTypedObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _type = attributes[@"type"];

    return self;
}

- (RXEScriptTypeDefinition *)typeDefinition
{
    return [self.app scriptingDefinitionForScriptingType:self.type];
}

@end

@implementation RXEScriptSuite {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptAccessGroup *> *_accessGroups;
    NSMutableArray<RXEScriptClass *> *_classes;
    NSMutableArray<RXEScriptClassExt *> *_classExts;
    NSMutableArray<RXEScriptCommand *> *_commands;
    NSMutableArray<RXEScriptEnumeration *> *_enumerations;
    NSMutableArray<RXEScriptEvent *> *_events;
    NSMutableArray<RXEScriptRecordType *> *_recordTypes;
    NSMutableArray<RXEScriptValueType *> *_valueTypes;
    NSMutableArray<RXEScriptDocumentation *> *_docs;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _name = attributes[@"name"];
    _code = attributes[@"code"];
    _commentary = attributes[@"description"];
    _hidden = attributes[@"hidden"];

    _cocoaImp = nil;
    _accessGroups = NSMutableArray.array;
    _classes = NSMutableArray.array;
    _classExts = NSMutableArray.array;
    _commands = NSMutableArray.array;
    _enumerations = NSMutableArray.array;
    _events = NSMutableArray.array;
    _recordTypes = NSMutableArray.array;
    _valueTypes = NSMutableArray.array;
    _docs = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addAccessGroup:(RXEScriptAccessGroup *)accessGroup
{
    [_accessGroups addObject:accessGroup];
}

- (void)addClass:(RXEScriptClass *)klass
{
    [_classes addObject:klass];
}

- (void)addClassExt:(RXEScriptClassExt *)classExt
{
    [_classExts addObject:classExt];
}

- (void)addCommand:(RXEScriptCommand *)command
{
    [_commands addObject:command];
}

- (void)addEnumeration:(RXEScriptEnumeration *)enumeration
{
    [_enumerations addObject:enumeration];
}

- (void)addEvent:(RXEScriptEvent *)event
{
    [_events addObject:event];
}

- (void)addRecordType:(RXEScriptRecordType *)recordType
{
    [_recordTypes addObject:recordType];
}

- (void)addValueType:(RXEScriptValueType *)valueType
{
    [_valueTypes addObject:valueType];
}

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@: %p %@ '%@'>",
        NSStringFromClass(self.class),
        self,
        self.name,
        self.code
    ];
}

@end

@implementation RXEScriptDocumentation {
    NSMutableArray<NSString *> *_htmlFragments;
}

- init
{
    if (!(self = [super init]))
        return self;

    _htmlFragments = NSMutableArray.array;

    return self;
}

- (void)addHTML:(NSString *)html
{
    [_htmlFragments addObject:html];
}

@end

@implementation RXEScriptXRef

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _target = attributes[@"target"];
    _hidden = attributes[@"hidden"];

    return self;
}

@end

@implementation RXEScriptAccessGroup

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _identifier = attributes[@"identifier"];
    _access = attributes[@"access"];

    return self;
}

@end

@implementation RXEScriptCocoaImp

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _name = attributes[@"name"];
    _cocoaClass = attributes[@"class"];
    _key = attributes[@"key"];
    _method = attributes[@"method"];
    _insertAtBeginning = attributes[@"insert-at-beginning"];
    _booleanValue = attributes[@"boolean-value"];
    _integerValue = attributes[@"integer-value"];
    _stringValue = attributes[@"string-value"];

    return self;
}

@end

@implementation RXEScriptSynonym {
    RXEScriptCocoaImp *_cocoaImp;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _name = attributes[@"name"];
    _code = attributes[@"code"];
    _hidden = attributes[@"hidden"];

    _cocoaImp = nil;
    
    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

@end
