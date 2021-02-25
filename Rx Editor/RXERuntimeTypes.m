//
//  RXERuntimeTypes.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/24/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXERuntimeTypes.h"

@implementation RXERuntimeClassDescription

- (Class)returnClassForSelector:(SEL)sel
{
    return nil;
}

@end

@implementation RXERuntimeMethodDescription

- (Class)returnClass
{
    return nil;
}

@end
