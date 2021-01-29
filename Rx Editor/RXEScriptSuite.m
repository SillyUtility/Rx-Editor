//
//  RXEScriptSuite.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"

@implementation RXEScriptSuite {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray *_accessGroups;
    NSMutableArray *_classes;
    NSMutableArray *_classExts;
    NSMutableArray *_commands;
    NSMutableArray *_enumerations;
    NSMutableArray *_events;
    NSMutableArray *_recordTypes;
    NSMutableArray *_valueTypes;
    NSMutableArray *_docs;
}

- (instancetype)initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
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
