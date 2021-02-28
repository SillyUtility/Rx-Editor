//
//  RXESDefParser.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/14/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <SillyLog/SillyLog.h>
#import "RXESDefParser.h"
#import "RXEScriptableApp.h"
#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"
#import "NSMutableArray+Additions.h"

NSString * const RXESDefDictionaryKey = @"dictionary";
NSString * const RXESDefDocumentationKey = @"documentation";
NSString * const RXESDefHTMLKey = @"html";
NSString * const RXESDefXRefKey = @"xref";
NSString * const RXESDefAccessGroupKey = @"access-group";
NSString * const RXESDefCocoaKey = @"cocoa";
NSString * const RXESDefSuiteKey = @"suite";
NSString * const RXESDefSynonymKey = @"synonym";
NSString * const RXESDefTypeKey = @"type";
NSString * const RXESDefCommandKey = @"command";
NSString * const RXESDefEventKey = @"event";
NSString * const RXESDefDirectParameterKey = @"direct-parameter";
NSString * const RXESDefResultKey = @"result";
NSString * const RXESDefParameterKey = @"parameter";
NSString * const RXESDefClassKey = @"class";
NSString * const RXESDefContentsKey = @"contents";
NSString * const RXESDefElementKey = @"element";
NSString * const RXESDefAccessorKey = @"accessor";
NSString * const RXESDefPropertyKey = @"property";
NSString * const RXESDefRespondsToKey = @"responds-to";
NSString * const RXESDefClassExtKey = @"class-extension";
NSString * const RXESDefValueTypeKey = @"value-type";
NSString * const RXESDefRecordTypeKey = @"record-type";
NSString * const RXESDefEnumerationKey = @"enumeration";
NSString * const RXESDefEnumeratorKey = @"enumerator";

@interface RXESDefParser ()
@end

@implementation RXESDefParser {
    NSXMLParser *_parser;
    NSMutableArray *_stack;
    NSMutableArray<RXEScriptSuite *> *_suites;
    NSMutableDictionary<NSString *, RXEScriptTypeDefinition *> *_types;
    NSMutableArray<RXEScriptDocumentation *> *_docs;
}

- initWithData:(NSData *)xmlData
{
    NSXMLDocument *xmlDoc;
    NSError *err;

    if (!(self = [super init]))
        return self;

    // process any xi:include directives with NSXMLDocumentXInclude
    xmlDoc = [[NSXMLDocument alloc]
        initWithData:xmlData
        options:NSXMLDocumentXInclude
        error:&err
    ];
    if (err) {
        SLYError(@"%@", err);
        return nil;
    }

    _parser = [[NSXMLParser alloc] initWithData:xmlDoc.XMLData];
    _parser.delegate = self;
    _stack = NSMutableArray.array;
    _suites = NSMutableArray.array;
    _types = [NSMutableDictionary<NSString *, RXEScriptTypeDefinition *> dictionary];
    _docs = NSMutableArray.array;

    return self;
}

- (BOOL)parse
{
    return [_parser parse];
}

#pragma mark - XML Parser Delegate

- (void)parserDidStartDocument:(NSXMLParser *)parser
{
    SLYTrace(@"start %@", parser);
}

- (void)parserDidEndDocument:(NSXMLParser *)parser
{
    SLYTrace(@"end %@", parser);
}

- (void)parser:(NSXMLParser *)parser
    didStartElement:(NSString *)elementName
    namespaceURI:(nullable NSString *)namespaceURI
    qualifiedName:(nullable NSString *)qName
    attributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    SLYTrace(@"startElem %@:%@ %@", parser, elementName, attributes);

    if ([elementName isEqualToString:RXESDefDocumentationKey]) {
        [_stack push:[[RXEScriptDocumentation alloc] init]];
    } else if ([elementName isEqualToString:RXESDefHTMLKey]) {
        // noop
    } else if ([elementName isEqualToString:RXESDefXRefKey]) {
        [_stack push:[[RXEScriptXRef alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefAccessGroupKey]) {
        [_stack push:[[RXEScriptAccessGroup alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefCocoaKey]) {
        [_stack push:[[RXEScriptCocoaImp alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefSuiteKey]) {
        [_stack push:[[RXEScriptSuite alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefSynonymKey]) {
        [_stack push:[[RXEScriptSynonym alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefTypeKey]) {
        [_stack push:[[RXEScriptType alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefCommandKey]) {
        [_stack push:[[RXEScriptCommand alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefEventKey]) {
        [_stack push:[[RXEScriptEvent alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefDirectParameterKey]) {
        [_stack push:[[RXEScriptDirectParameter alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefResultKey]) {
        [_stack push:[[RXEScriptResult alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefParameterKey]) {
        [_stack push:[[RXEScriptParameter alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefClassKey]) {
        RXEScriptClass *class = [[RXEScriptClass alloc] initWithAttributes:attributes];
        class.app = self.scriptableApp;
        class.parent = _stack.lastObject;
        _types[class.name] = class;
        [_stack push:class];
    } else if ([elementName isEqualToString:RXESDefContentsKey]) {
        [_stack push:[[RXEScriptContents alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefElementKey]) {
        [_stack push:[[RXEScriptElement alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefAccessorKey]) {
        [_stack push:[[RXEScriptAccessor alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefPropertyKey]) {
        RXEScriptProperty *prop = [[RXEScriptProperty alloc] initWithAttributes:attributes];
        prop.app = self.scriptableApp;
        prop.parent = _stack.lastObject;
        [_stack push:prop];
    } else if ([elementName isEqualToString:RXESDefRespondsToKey]) {
        [_stack push:[[RXEScriptClassCommand alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefClassExtKey]) {
        RXEScriptClassExt *classExt = [[RXEScriptClassExt alloc] initWithAttributes:attributes];
        classExt.app = self.scriptableApp;
        classExt.parent = _stack.lastObject;
        [_stack push:classExt];
    } else if ([elementName isEqualToString:RXESDefValueTypeKey]) {
        RXEScriptValueType *valueType = [[RXEScriptValueType alloc] initWithAttributes:attributes];
        valueType.app = self.scriptableApp;
        valueType.parent = _stack.lastObject;
        _types[valueType.name] = valueType;
        [_stack push:valueType];
    } else if ([elementName isEqualToString:RXESDefRecordTypeKey]) {
        RXEScriptRecordType *recordType = [[RXEScriptRecordType alloc] initWithAttributes:attributes];
        recordType.app = self.scriptableApp;
        recordType.parent = _stack.lastObject;
        _types[recordType.name] = recordType;
        [_stack push:recordType];
    } else if ([elementName isEqualToString:RXESDefEnumerationKey]) {
        RXEScriptEnumeration *enumeration = [[RXEScriptEnumeration alloc] initWithAttributes:attributes];
        enumeration.app = self.scriptableApp;
        enumeration.parent = _stack.lastObject;
        _types[enumeration.name] = enumeration;
        [_stack push:enumeration];
    } else if ([elementName isEqualToString:RXESDefEnumeratorKey]) {
        [_stack push:[[RXEScriptEnumerator alloc] initWithAttributes:attributes]];
    }
}

- (void)parser:(NSXMLParser *)parser
    didEndElement:(NSString *)elementName
    namespaceURI:(nullable NSString *)namespaceURI
    qualifiedName:(nullable NSString *)qName
{
    SLYTrace(@"endElem %@:%@", parser, elementName);

    if ([elementName isEqualToString:RXESDefDocumentationKey]) {
        id doc = _stack.pop;
        if (_stack.count == 0)
            [_docs addObject:doc];
        else
            [_stack.lastObject addDocumentation:doc];
    } else if ([elementName isEqualToString:RXESDefHTMLKey]) {
        // noop
    } else if ([elementName isEqualToString:RXESDefXRefKey]) {
        [_stack.ancestor addXRef:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefAccessGroupKey]) {
        [_stack.ancestor addAccessGroup:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefCocoaKey]) {
        [_stack.ancestor addCocoaImp:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefSuiteKey]) {
        [_suites addObject:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefSynonymKey]) {
        [_stack.ancestor addSynonym:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefTypeKey]) {
        [_stack.ancestor addType:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefCommandKey]) {
        [_stack.ancestor addCommand:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefEventKey]) {
        [_stack.ancestor addEvent:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefDirectParameterKey]) {
        [_stack.ancestor addDirectParameter:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefResultKey]) {
        [_stack.ancestor addResult:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefParameterKey]) {
        [_stack.ancestor addParameter:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefClassKey]) {
        [_stack.ancestor addClass:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefContentsKey]) {
        [_stack.ancestor addContents:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefElementKey]) {
        [_stack.ancestor addElement:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefAccessorKey]) {
        [_stack.ancestor addAccessor:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefPropertyKey]) {
        [_stack.ancestor addProperty:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefRespondsToKey]) {
        [_stack.ancestor addClassCommand:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefClassExtKey]) {
        [_stack.ancestor addClassExt:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefValueTypeKey]) {
        [_stack.ancestor addValueType:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefRecordTypeKey]) {
        [_stack.ancestor addRecordType:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefEnumerationKey]) {
        [_stack.ancestor addEnumeration:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefEnumeratorKey]) {
        [_stack.ancestor addEnumerator:_stack.pop];
    }
}

- (void)parser:(NSXMLParser *)parser
    foundCharacters:(NSString *)string
{
    SLYTrace(@"chars %@:%@", parser, string);

    id last = _stack.lastObject;
    if ([last respondsToSelector:@selector(addHTML:)])
        [last addHTML:string];
}

- (void)parser:(NSXMLParser *)parser
    foundCDATA:(NSData *)CDATABlock
{
    SLYTrace(@"data %@:%@", parser, CDATABlock);
}

- (void)parser:(NSXMLParser *)parser
    parseErrorOccurred:(NSError *)parseError
{
    SLYTrace(@"parseError %@:%@", parser, parseError);
}

- (void)parser:(NSXMLParser *)parser
    validationErrorOccurred:(NSError *)validationError
{
    SLYTrace(@"validationError %@:%@", parser, validationError);
}

@end
