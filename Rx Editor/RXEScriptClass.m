//
//  RXEScriptClass.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptClass.h"

@implementation RXEScriptClassContent {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptAccessGroup *> *_accessGroups;
    NSMutableArray<RXEScriptElement *> *_elements;
    NSMutableArray<RXEScriptProperty *> *_properties;
    NSMutableArray<RXEScriptClassCommand *> *_classCommands;
    NSMutableArray<RXEScriptSynonym *> *_synonyms;
    NSMutableArray<RXEScriptDocumentation *> *_docs;
    NSMutableArray<RXEScriptXRef *> *_xrefs;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _identifier = attributes[@"id"];
    _hidden = attributes[@"hidden"];
    _commentary = attributes[@"description"];

    _cocoaImp = nil;
    _accessGroups = NSMutableArray.array;
    _elements = NSMutableArray.array;
    _properties = NSMutableArray.array;
    _classCommands = NSMutableArray.array;
    _synonyms = NSMutableArray.array;
    _docs = NSMutableArray.array;
    _xrefs = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup
{
    [_accessGroups addObject:accessGroup];
}

- (void)addElement:(RXEScriptElement *)element
{
    [_elements addObject:element];
}

- (void)addProperty:(RXEScriptProperty *)property
{
    [_properties addObject:property];
}

- (void)addClassCommand:(RXEScriptClassCommand *)classCommand
{
    [_classCommands addObject:classCommand];
}

- (void)addSynonym:(RXEScriptSynonym *)synonym
{
    [_synonyms addObject:synonym];
}

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

- (void)addXRef:(RXEScriptXRef *)xref
{
    [_xrefs addObject:xref];
}

@end

@implementation RXEScriptClass {
    NSMutableArray<RXEScriptType *> *_types;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super initWithAttributes:attributes]))
        return self;

    _name = attributes[@"name"];
    _code = attributes[@"code"];
    _plural = attributes[@"plural"];
    _inherits = attributes[@"inherits"];

    _types = NSMutableArray.array;

    return self;
}

- (void)addType:(RXEScriptType *)type
{
    [_types addObject:type];
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

@implementation RXEScriptClassExt

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super initWithAttributes:attributes]))
        return self;

    _extends = attributes[@"extends"];
    _title = attributes[@"title"];

    return self;
}

@end

@implementation RXEScriptElement {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptAccessGroup *> *_accessGroups;
    NSMutableArray<RXEScriptAccessor *> *_accessors;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _type = attributes[@"type"];
    _access = attributes[@"access"];
    _hidden = attributes[@"hidden"];
    _commentary = attributes[@"description"];

    _cocoaImp = nil;
    _accessGroups = NSMutableArray.array;
    _accessors = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup
{
    [_accessGroups addObject:accessGroup];
}

- (void)addAccessor:(RXEScriptAccessor *)accessor
{
    [_accessors addObject:accessor];
}

@end

@implementation RXEScriptPropBase {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptAccessGroup *> *_accessGroups;
    NSMutableArray<RXEScriptType *> *_types;
    NSMutableArray<RXEScriptSynonym *> *_synonyms;
    NSMutableArray<RXEScriptDocumentation *> *_docs;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _name = attributes[@"name"];
    _code = attributes[@"code"];
    _hidden = attributes[@"hidden"];
    _type = attributes[@"type"];
    _access = attributes[@"access"];
    _inProperties = attributes[@"in-properties"];
    _commentary = attributes[@"description"];

    _cocoaImp = nil;
    _accessGroups = NSMutableArray.array;
    _types = NSMutableArray.array;
    _synonyms = NSMutableArray.array;
    _docs = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup
{
    [_accessGroups addObject:accessGroup];
}

- (void)addType:(RXEScriptType *)type
{
    [_types addObject:type];
}

- (void)addSynonym:(RXEScriptSynonym *)synonym
{
    [_synonyms addObject:synonym];
}

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

@end

@implementation RXEScriptClassCommand {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptAccessGroup *> *_accessGroups;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _command = attributes[@"command"];
    _hidden = attributes[@"hidden"];
    _name = attributes[@"name"];

    _cocoaImp = nil;
    _accessGroups = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup
{
    [_accessGroups addObject:accessGroup];
}

@end

@implementation RXEScriptAccessor

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _style = attributes[@"style"];

    return self;
}

@end
