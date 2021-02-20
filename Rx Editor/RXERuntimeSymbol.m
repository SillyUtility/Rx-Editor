//
//  RXERuntimeSymbol.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/19/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXERuntimeSymbol.h"

@implementation RXERuntimeSymbol

- initWithClass:(Class)class
{
    return nil;
}

- initWithProtocol:(Protocol *)proto
{
    return nil;
}

- (BOOL)isClass
{
    return NO;
}

- (BOOL)isProtocol
{
    return NO;
}

- (BOOL)isRealized
{
    return NO;
}

- (Class)symbolClass
{
    return nil;
}

- (Protocol *)symbolProtocol
{
    return nil;
}

@end
