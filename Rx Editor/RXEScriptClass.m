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
