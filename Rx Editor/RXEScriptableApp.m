//
//  RXEScriptableApp.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <SillyLog/SillyLog.h>

#import "RXEScriptableApp.h"
#import "RXESDefParser.h"
#import "RXEUtilities.h"

@implementation RXEScriptableApp

- initWithName:(NSString *)name scriptingDefinition:(CFDataRef)scdata
{
    NSData *data;
    RXESDefParser *parser;

    if (!(self = [super init]))
        return self;

    _appName = name;
    
    data = (__bridge NSData *)scdata;
    parser = [[RXESDefParser alloc] initWithData:data];
    [parser parse];

    _suites = parser.suites;

    return self;
}

- (NSString *)appClassName
{
    return RXEClassNameFromString(self.appName);
}

@end
