//
//  RXEScriptTypes.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/22/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptTypes.h"

@implementation RXEScriptType {
    NSMutableArray<RXEScriptType *> *_types;
}

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _type = attributes[@"type"];
    _list = attributes[@"list"];
    _hidden = attributes[@"hidden"];

    _types = NSMutableArray.array;

    return self;
}

- (void)addType:(RXEScriptType *)type
{
    [_types addObject:type];
}

@end

@implementation RXEScriptValueType {
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
    _commentary = attributes[@"description"];

    _synonyms = NSMutableArray.array;
    _docs = NSMutableArray.array;
    _xrefs = NSMutableArray.array;

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

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

- (void)addXRef:(RXEScriptXRef *)xref
{
    [_xrefs addObject:xref];
}

@end

@implementation RXEScriptRecordType {
    NSMutableArray<RXEScriptSynonym *> *_synonyms;
    NSMutableArray<RXEScriptProperty *> *_properties;
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
    _commentary = attributes[@"description"];

    _synonyms = NSMutableArray.array;
    _properties = NSMutableArray.array;
    _docs = NSMutableArray.array;
    _xrefs = NSMutableArray.array;

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

- (void)addProperty:(RXEScriptProperty *)property
{
    [_properties addObject:property];
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

@implementation RXEScriptEnumeration {
    NSMutableArray<RXEScriptEnumerator *> *_enumerators;
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
    _commentary = attributes[@"description"];
    _inLine = attributes[@"inline"];

    _enumerators = NSMutableArray.array;
    _docs = NSMutableArray.array;
    _xrefs = NSMutableArray.array;

    return self;
}

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp
{
    _cocoaImp = cocoaImp;
}

- (void)addEnumerator:(RXEScriptEnumerator *)enumerator
{
    [_enumerators addObject:enumerator];
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

@implementation RXEScriptEnumerator {
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
    _commentary = attributes[@"description"];

    _synonyms = NSMutableArray.array;
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

- (void)addDocumentation:(RXEScriptDocumentation *)doc
{
    [_docs addObject:doc];
}

@end
