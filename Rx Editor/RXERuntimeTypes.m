//
//  RXERuntimeTypes.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/24/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <objc/runtime.h>
#import "RXERuntimeTypes.h"

@implementation RXERuntimeClassDescription {
    NSMutableDictionary<NSString *, RXERuntimeMethodDescription *> *_methods;
}

- initWithClass:(Class)class
{
    if (!(self = [super init]))
        return self;

    _methods = [NSMutableDictionary<NSString *, RXERuntimeMethodDescription *> dictionary];

    return self;
}

- (void)addMethodDescription:(RXERuntimeMethodDescription *)methDesc
{
    [_methods setObject:methDesc forKey:NSStringFromSelector(methDesc.selector)];
}

- (Class)returnClassForSelector:(SEL)sel
{
    return [_methods objectForKey:NSStringFromSelector(sel)].returnClass;
}

@end

@implementation RXERuntimeMethodDescription

- initWithSelector:(SEL)sel returnType:(Class)retClass
{
    if (!(self = [super init]))
        return self;

    _selector = sel;
    _returnClass = retClass;

    return self;
}

@end
