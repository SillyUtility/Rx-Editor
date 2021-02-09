//
//  RXEUtilities.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/4/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptProperty;

@interface RXEUtilities : NSObject

@end

NSString *RXEClassNameFromString(NSString *str);
NSString *RXEPropertyNameFromString(NSString *str);
NSString *RXEMethodNameFromString(NSString *str);

Protocol *RXEExportProtocolForClassName(NSString *className);
Protocol *RXEGetExportProtocolForClass(Class class);

void RXERuntimeClassExportProperty(Class class, RXEScriptProperty *property);

NSString *RXEDescribeClass(Class class);
NSString *RXEDescribeProtocol(Protocol *proto);
NSString *RXEDescribeProperty(objc_property_t prop);
NSString *RXEDescribeMethod(Method meth);
NSString *RXEDescribeIvar(Ivar ivar);

NS_ASSUME_NONNULL_END
