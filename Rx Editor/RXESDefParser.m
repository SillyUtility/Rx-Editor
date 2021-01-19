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
NSString * const RXESDefSuiteKey = @"suite";

@interface RXESDefParser ()
@end

@implementation RXESDefParser {
    NSXMLParser *_parser;
    NSMutableArray *_stack;
    NSMutableArray *_suites;
}

- (instancetype)initWithData:(NSData *)xmlData
{
    if (!(self = [super init]))
        return self;

    // TODO: process document with NSXMLDocumentXInclude

    _parser = [[NSXMLParser alloc] initWithData:xmlData];
    _parser.delegate = self;
    _stack = NSMutableArray.array;
    _suites = NSMutableArray.array;

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

     if ([elementName isEqualToString:RXESDefSuiteKey]) {
        RXEScriptSuite *suite = [[RXEScriptSuite alloc]
            initWithAttributes:attributeDict];
        [_stack addObject:suite];
     }
}

- (void)parser:(NSXMLParser *)parser
    didEndElement:(NSString *)elementName
    namespaceURI:(nullable NSString *)namespaceURI
    qualifiedName:(nullable NSString *)qName
{
    SLYTrace(@"endElem %@:%@", parser, elementName);

    if ([elementName isEqualToString:RXESDefSuiteKey]) {
        id last = _stack.lastObject;
        [_suites addObject:last];
        [_stack removeLastObject];
    }
}

- (void)parser:(NSXMLParser *)parser
    foundCharacters:(NSString *)string
{
    SLYTrace(@"chars %@:%@", parser, string);
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
