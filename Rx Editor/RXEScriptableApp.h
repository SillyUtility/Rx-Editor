//
//  RXEScriptableApp.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptSuite;

@interface RXEScriptableApp : NSObject
- (instancetype)initWithName:(NSString *)name
    scriptingDefinition:(CFDataRef)scdata;
@property (nullable, readonly, copy) NSString *appName;
@property (readonly) NSArray<RXEScriptSuite *> *suites;
@end

NS_ASSUME_NONNULL_END
