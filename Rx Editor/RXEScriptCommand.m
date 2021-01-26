//
//  RXEScriptCommand.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptCommand.h"

@implementation RXEScriptCommand {
    RXEScriptCocoaImp *_cocoaImp;
    NSMutableArray<RXEScriptAccessGroup *> *_accessGroups;
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
    _commandID = attributes[@"id"];
    _code = attributes[@"code"];
    _commandDescription = attributes[@"description"];
    _hidden = attributes[@"hidden"];

    _cocoaImp = nil;
    _accessGroups = NSMutableArray.array;
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

- (void)addAccessGroup:(RXEScriptAccessGroup *)accessGroup
{
    [_accessGroups addObject:accessGroup];
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
