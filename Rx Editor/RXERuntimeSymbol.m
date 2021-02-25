//
//  RXERuntimeSymbol.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/19/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <objc/runtime.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <SillyLog/SillyLog.h>

#import "RXERuntimeSymbol.h"

@implementation RXERuntimeSymbol {
    Class _class;
    Protocol *_protocol;
}

- init
{
    if (!(self = [super init]))
        return self;

    _isRealized = NO;
    _isExported = NO;

    return self;
}

- initWithClass:(Class)class
{
    if (!(self = [self init]))
        return self;

    _class = class;

    return self;
}

- initWithProtocol:(Protocol *)proto
{
    if (!(self = [self init]))
        return self;

    _protocol = proto;

    return self;
}

- (BOOL)isClass
{
    return !!_class;
}

- (BOOL)isProtocol
{
    return !!_protocol;
}

- (NSString *)name
{
    if (self.isClass)
        return @(class_getName(self.symbolClass));
    if (self.isProtocol)
        return @(protocol_getName(self.symbolProtocol));

    return @"";
}

- (Class)symbolClass
{
    return _class;
}

- (Protocol *)symbolProtocol
{
    return _protocol;
}

- (void)registerSymbolWithObjCRuntime
{
    SLYTrace(@"REGISTER w/OBJC %@", self.name);

    if (_isRealized)
        return;

    if (self.isClass) {
        objc_registerClassPair(self.symbolClass);
        _isRealized = YES;
        return;
    }

    if (self.isProtocol) {
        objc_registerProtocol(self.symbolProtocol);
        _isRealized = YES;
        return;
    }
}

- (void)exportToJSContext:(JSContext *)ctx
{
    if (_isExported)
        return;

    ctx[self.name] = self.symbolClass;
    _isExported = YES;
}

@end
