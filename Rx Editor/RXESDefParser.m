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
    NSMutableArray *_suites;
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
        [_stack push:[[RXEScriptClass alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefContentsKey]) {
        [_stack push:[[RXEScriptContents alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefElementKey]) {
        [_stack push:[[RXEScriptElement alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefAccessorKey]) {
        [_stack push:[[RXEScriptAccessor alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefPropertyKey]) {
        [_stack push:[[RXEScriptProperty alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefRespondsToKey]) {
        [_stack push:[[RXEScriptClassCommand alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefClassExtKey]) {
        [_stack push:[[RXEScriptClassExt alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefValueTypeKey]) {
        [_stack push:[[RXEScriptValueType alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefRecordTypeKey]) {
        [_stack push:[[RXEScriptRecordType alloc] initWithAttributes:attributes]];
    } else if ([elementName isEqualToString:RXESDefEnumerationKey]) {
        [_stack push:[[RXEScriptEnumeration alloc] initWithAttributes:attributes]];
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
        [_stack.lastObject addXRef:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefAccessGroupKey]) {
        [_stack.lastObject addAccessGroup:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefCocoaKey]) {
        [_stack.lastObject addCocoaImp:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefSuiteKey]) {
        [_suites addObject:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefSynonymKey]) {
        [_stack.lastObject addSynonym:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefTypeKey]) {
        [_stack.lastObject addType:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefCommandKey]) {
        [_stack.lastObject addCommand:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefEventKey]) {
        [_stack.lastObject addEvent:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefDirectParameterKey]) {
        [_stack.lastObject addDirectParameter:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefResultKey]) {
        [_stack.lastObject addResult:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefParameterKey]) {
        [_stack.lastObject addParameter:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefClassKey]) {
        [_stack.lastObject addClass:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefContentsKey]) {
        [_stack.lastObject addContents:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefElementKey]) {
        [_stack.lastObject addElement:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefAccessorKey]) {
        [_stack.lastObject addAccessor:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefPropertyKey]) {
        [_stack.lastObject addProperty:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefRespondsToKey]) {
        [_stack.lastObject addClassCommand:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefClassExtKey]) {
        [_stack.lastObject addClassExt:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefValueTypeKey]) {
        [_stack.lastObject addValueType:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefRecordTypeKey]) {
        [_stack.lastObject addRecordType:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefEnumerationKey]) {
        [_stack.lastObject addEnumeration:_stack.pop];
    } else if ([elementName isEqualToString:RXESDefEnumeratorKey]) {
        [_stack.lastObject addEnumerator:_stack.pop];
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
