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
NSString * const RXESDefElementKey = @"element";
NSString * const RXESDefAccessorTypeKey = @"accessor-type";
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

- (instancetype)initWithData:(NSData *)xmlData
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
    attributes:(NSDictionary<NSString *, NSString *> *)attributeDict
{
    SLYTrace(@"startElem %@:%@ %@", parser, elementName, attributeDict);

    if ([elementName isEqualToString:RXESDefDocumentationKey]) {
        RXEScriptDocumentation *doc = [[RXEScriptDocumentation alloc] init];
        [_stack addObject:doc];
    } else if ([elementName isEqualToString:RXESDefHTMLKey]) {
        // noop
    } else if ([elementName isEqualToString:RXESDefSuiteKey]) {
        RXEScriptSuite *suite = [[RXEScriptSuite alloc]
            initWithAttributes:attributeDict];
        [_stack addObject:suite];
    } else if ([elementName isEqualToString:RXESDefClassKey]) {
        RXEScriptClass *klass = [[RXEScriptClass alloc]
            initWithAttributes:attributeDict];
        [_stack addObject:klass];
    }
}

- (void)parser:(NSXMLParser *)parser
    didEndElement:(NSString *)elementName
    namespaceURI:(nullable NSString *)namespaceURI
    qualifiedName:(nullable NSString *)qName
{
    SLYTrace(@"endElem %@:%@", parser, elementName);

    if ([elementName isEqualToString:RXESDefDocumentationKey]) {
        id doc = _stack.lastObject;
        [_stack removeLastObject];
        if (_stack.count == 0)
            [_docs addObject:doc];
        else
            [_stack.lastObject addDocumentation:doc];
    } else if ([elementName isEqualToString:RXESDefHTMLKey]) {
        // noop
    } else if ([elementName isEqualToString:RXESDefSuiteKey]) {
        id suite = _stack.lastObject;
        [_stack removeLastObject];
        [_suites addObject:suite];
    } else if ([elementName isEqualToString:RXESDefClassKey]) {
        id klass = _stack.lastObject;
        [_stack removeLastObject];
        [_stack.lastObject addClass:klass];
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
