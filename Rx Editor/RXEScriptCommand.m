//
//  RXEScriptCommand.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptCommand.h"

@implementation RXEScriptVerb {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptSynonym *> *_synonyms;
    RXEScriptDirectParameter *_directParameter;
    NSMutableArray<RXEScriptParameter *> *_parameters;
    RXEScriptResult *_result;
    NSMutableArray<RXEScriptXRef *> *_xrefs;
    NSMutableArray<RXEScriptDocumentation *> *_docs;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _name = attributes[@"name"];
    _identifier = attributes[@"id"];
    _code = attributes[@"code"];
    _commentary = attributes[@"description"];
    _hidden = attributes[@"hidden"];

    _cocoaImp = nil;
    _synonyms = NSMutableArray.array;
    _directParameter = nil;
    _parameters = NSMutableArray.array;
    _result = nil;
    _xrefs = NSMutableArray.array;
    _docs = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addSynonym:(RXEScriptSynonym *)synonym
{
    [_synonyms addObject:synonym];
}

- (void)addDirectParameter:(RXEScriptDirectParameter *)directParameter
{
    _directParameter = directParameter;
}

- (void)addParameter:(RXEScriptParameter *)parameter
{
    [_parameters addObject:parameter];
}

- (void)addResult:(RXEScriptResult *)result
{
    _result = result;
}

- (void)addXRef:(RXEScriptXRef *)xref
{
    [_xrefs addObject:xref];
}

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

@end

@implementation RXEScriptCommand {
    NSMutableArray<RXEScriptAccessGroup *> *_accessGroups;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super initWithAttributes:attributes]))
        return self;

    _accessGroups = NSMutableArray.array;

    return self;
}

- (void)addAccessGroup:(RXEScriptAccessGroup *)accessGroup
{
    [_accessGroups addObject:accessGroup];
}

@end

@implementation RXEScriptEvent
@end

@implementation RXEScriptDirectParameter {
    NSMutableArray<RXEScriptType *> *_types;
    NSMutableArray<RXEScriptDocumentation *> *_docs;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _type = attributes[@"type"];
    _optional = attributes[@"optional"];
    _requiresAccess = attributes[@"requires-access"];
    _commentary = attributes[@"description"];

    _types = NSMutableArray.array;
    _docs = NSMutableArray.array;

    return self;
}

- (void)addType:(RXEScriptType *)type
{
    [_types addObject:type];
}

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

@end

@implementation RXEScriptParameter {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptType *> *_types;
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
    _optional = attributes[@"optional"];
    _requiresAccess = attributes[@"requires-access"];
    _commentary = attributes[@"description"];

    _cocoaImp = nil;
    _types = NSMutableArray.array;
    _docs = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addType:(RXEScriptType *)type
{
    [_types addObject:type];
}

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

@end

@implementation RXEScriptResult {
    NSMutableArray<RXEScriptType *> *_types;
    NSMutableArray<RXEScriptDocumentation *> *_docs;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _type = attributes[@"type"];
    _commentary = attributes[@"description"];

    _types = NSMutableArray.array;
    _docs = NSMutableArray.array;

    return self;
}

- (void)addType:(RXEScriptType *)type
{
    [_types addObject:type];
}

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

@end
