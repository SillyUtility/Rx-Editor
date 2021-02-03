//
//  RXERuntimeController.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/2/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptableApp, Application, JSContext;

@interface RXERuntimeController : NSObject

- init;

@property (readonly) JSContext *JSContext;

- (void)exportFundamentalClasses;

+ (void)exportScriptableApp:(RXEScriptableApp *)sapp
    appInstance:(Application *)app
    context:(JSContext *)ctx;

@end

NS_ASSUME_NONNULL_END
