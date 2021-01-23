//
//  RXEScriptClass.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptClass.h"

@implementation RXEScriptClass

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _name = attributes[@"name"];
    _classID = attributes[@"id"];
    _code = attributes[@"code"];
    _hidden = attributes[@"hidden"];
    _plural = attributes[@"plural"];
    _inherits = attributes[@"inherits"];
    _classDescription = attributes[@"description"];

    return self;
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
