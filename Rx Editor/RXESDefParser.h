//
//  RXESDefParser.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/14/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXESDefParser : NSObject <NSXMLParserDelegate>

- (instancetype)initWithData:(NSData *)xmlData;
- (BOOL)parse;

@end

NS_ASSUME_NONNULL_END
