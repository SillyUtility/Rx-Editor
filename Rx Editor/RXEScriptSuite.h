//
//  RXEScriptSuite.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXEScriptSuite : NSObject
- (instancetype)initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;
@property (readonly) NSString *name;
@property (readonly) NSString *code;
@property (readonly) NSString *suiteDescription;
@property (readonly) NSString *hidden;
@end

NS_ASSUME_NONNULL_END
