//
//  RXERuntimeDescriptionTests.m
//  Rx EditorTests
//
//  Created by Eddie Hillenbrand on 2/24/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "RXEUtilities.h"

@interface C1 : NSObject
@property (readonly) id object;
@property (readonly) void *pointer;
@property (readonly) BOOL boolean;
@property (readonly) char character;
@property (readonly) short shortInteger;
@property (readonly) int integer;
@property (readonly) long longInteger;
@property (readonly) long long longLongInteger;
@property (readonly) unsigned char unsignedCharacter;
@property (readonly) unsigned short unsignedShortInteger;
@property (readonly) unsigned int unsignedInteger;
@property (readonly) unsigned long unsignedLongInteger;
@property (readonly) unsigned long long unsignedLongLongInteger;
@end

@implementation C1
@end

typedef struct big_t {
    unsigned long long big1;
    unsigned long long big2;
    unsigned long long big3;
    unsigned long long big4;
    unsigned long long big5;
    unsigned long long big6;
    unsigned long long big7;
    unsigned long long big8;
} big_t;

@interface C2 : NSObject
@property (readonly) CGPoint point;
@property (readonly) big_t big;
@end

@implementation C2
@end

@interface C3 : NSObject
@property (readonly) NSObject *object;
@end

@implementation C3
@end


@interface RXERuntimeDescriptionTests : XCTestCase
@end

@implementation RXERuntimeDescriptionTests

- (void)testDescribeClassWithPrimitiveProperties
{
    NSString *description = RXEDescribeClass(C1.class);
    NSLog(@"describe \n%@", description);

    NSMethodSignature *sigULL = [C1 instanceMethodSignatureForSelector:@selector(unsignedLongLongInteger)];
    NSUInteger lenULL = sigULL.methodReturnLength;
    NSLog(@"sizeof CGPoint return %lu", lenULL);
}

- (void)testDescribeClassWithStructProperties
{
    NSString *description = RXEDescribeClass(C2.class);
    NSLog(@"describe \n%@", description);

    NSMethodSignature *sigPoint = [C2 instanceMethodSignatureForSelector:@selector(point)];
    NSUInteger lenPoint = sigPoint.methodReturnLength;
    NSLog(@"sizeof CGPoint return %lu", lenPoint);

    NSMethodSignature *sigBig = [C2 instanceMethodSignatureForSelector:@selector(big)];
    NSUInteger lenBig = sigBig.methodReturnLength;
    NSLog(@"sizeof big_t return %lu", lenBig);
}

- (void)testDescribeClassWithObjectProperties
{
    NSString *description = RXEDescribeClass(C3.class);
    NSLog(@"describe \n%@", description);

    NSMethodSignature *sigObj= [C3 instanceMethodSignatureForSelector:@selector(object)];
    NSUInteger lenObj = sigObj.methodReturnLength;
    NSLog(@"return type %s", sigObj.methodReturnType);
    NSLog(@"sizeof NSObject* return %lu", lenObj);
}

@end
