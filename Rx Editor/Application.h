//
//  Application.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/16/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ApplicationExports <JSExport>
- (instancetype)initWithIdentifier:(NSString *)ident;
@property (nullable, readonly, copy) NSString *name;
@end

@interface Application : NSObject <ApplicationExports>
@property (nullable, readonly, copy) NSString *name;
@end

NS_ASSUME_NONNULL_END
