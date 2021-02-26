//
//  RXESDefParser.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/14/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RXEScriptableApp.h"
#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface RXESDefParser : NSObject <NSXMLParserDelegate>

- initWithData:(NSData *)xmlData;
- (BOOL)parse;

@property (weak) RXEScriptableApp *scriptableApp;
@property NSArray<RXEScriptSuite *> *suites;
@property NSDictionary<NSString *, RXEScriptBaseObject *> *types;

@end

NS_ASSUME_NONNULL_END
