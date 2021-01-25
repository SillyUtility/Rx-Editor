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
