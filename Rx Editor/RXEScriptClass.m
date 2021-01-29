//
//  RXEScriptClass.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptClass.h"

@implementation RXEScriptClass {
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

    _name = attributes[@"name"];
    _identifier = attributes[@"id"];
    _code = attributes[@"code"];
    _hidden = attributes[@"hidden"];
    _plural = attributes[@"plural"];
    _inherits = attributes[@"inherits"];
    _commentary = attributes[@"description"];

    return self;
}

- (void)add:(RXEScriptCocoaImp *)cocoaImp
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
