//
//  Application.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/16/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

#import "RXERuntimeObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ApplicationExports <JSExport>
- initWithIdentifier:(NSString *)ident;
@property (nullable, readonly, copy) NSString *name;
@end

@interface Application : RXERuntimeObject <ApplicationExports>
@property (nullable, readonly, copy) NSString *name;
@end

NS_ASSUME_NONNULL_END
