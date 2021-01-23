//
//  RXEScriptSuite.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"

@implementation RXEScriptSuite {
    NSMutableArray *_classes;
}

- (instancetype)initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes
{
    if (!(self = [super init]))
        return self;

    _name = attributes[@"name"];
    _code = attributes[@"code"];
    _suiteDescription = attributes[@"description"];
    _hidden = attributes[@"hidden"];

    _classes = NSMutableArray.array;

    return self;
}

- (void)addClass:(RXEScriptClass *)klass
{
    [_classes addObject:klass];
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
