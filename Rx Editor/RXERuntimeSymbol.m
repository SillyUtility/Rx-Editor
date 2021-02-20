//
//  RXERuntimeSymbol.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/19/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXERuntimeSymbol.h"

@implementation RXERuntimeSymbol {
    Class _class;
    Protocol *_protocol;
}

- initWithClass:(Class)class
{
    if (!(self = [super init]))
        return self;

    _class = class;

    return self;
}

- initWithProtocol:(Protocol *)proto
{
    if (!(self = [super init]))
        return self;

    _protocol = proto;

    return self;
}

- (BOOL)isClass
{
    return !!_class;
}

- (BOOL)isProtocol
{
    return !!_protocol;
}

- (BOOL)isRealized
{
    return NO;
}

- (Class)symbolClass
{
    return _class;
}

- (Protocol *)symbolProtocol
{
    return _protocol;
}

@end
