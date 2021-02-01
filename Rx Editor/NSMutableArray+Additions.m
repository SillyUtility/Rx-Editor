//
//  NSMutableArray+Additions.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/1/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "NSMutableArray+Additions.h"

@implementation NSMutableArray (Additions)

- (void)push:(id)anObject
{
    [self addObject:anObject];
}

- (id)pop
{
    id last = [self lastObject];
    [self removeLastObject];
    return last;
}

@end
