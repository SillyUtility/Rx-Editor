//
//  Rx_EditorTests.m
//  Rx EditorTests
//
//  Created by Eddie Hillenbrand on 1/9/21.
//

#import <XCTest/XCTest.h>
#import "RXEUtilities.h"

@interface Rx_EditorTests : XCTestCase

@end

@implementation Rx_EditorTests

- (void)testRXEClassNameFromString
{
    NSString *className;
    NSString *expect;

    className = RXEClassNameFromString(@"Finder");
    expect = @"Finder";
    XCTAssert([className isEqualToString:expect],
         @"expected %@, got %@", expect, className
    );

    className = RXEClassNameFromString(@"Script Editor");
    expect = @"ScriptEditor";
    XCTAssert([className isEqualToString:expect],
         @"expected %@, got %@", expect, className
    );

//    className = RXEClassNameFromString(@"  Shit2 app! ");
//    expect = @"Shit2App";
//    XCTAssert([className isEqualToString:expect],
//        @"expected %@, got %@", expect, className
//    );

    className = RXEClassNameFromString(@"Sweet β");
    expect = @"SweetB";
    XCTAssert([className isEqualToString:expect],
         @"expected %@, got %@", expect, className
    );
}

@end
