//
//  RXERuntimeController.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/2/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <JavaScriptCore/JavaScriptCore.h>
#import <objc/runtime.h>
#import <SillyLog/SillyLog.h>
#import "RXERuntimeController.h"
#import "RXERuntimeObject.h"
#import "RXEScriptableApp.h"
#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"
#import "Application.h"

@implementation RXERuntimeController {
    JSContext *_context;
}

- init
{
    SLYTraceCall();

    if (!(self = [super init]))
        return self;

    _context = [[JSContext alloc] init];
    [self exportFundamentalClasses];

    return self;
}

- (JSContext *)JSContext
{
    return _context;
}

- (void)exportFundamentalClasses
{
    _context[@"Application"] = Application.class;
}

+ (void)exportScriptableApp:(RXEScriptableApp *)sapp
    appInstance:(Application *)app
    context:(JSContext *)ctx
{
    SLYTrace(@"_scriptableApp %@", sapp);

    [self exportAppClass:sapp appInstance:app context:ctx];

    for (id suite in sapp.suites)
        [self exportSuite:suite appInstance:app context:ctx];
}

+ (void)exportAppClass:(RXEScriptableApp *)sapp
    appInstance:(Application *)app
    context:(JSContext *)ctx
{
    Class AppClass;
    const char *appClassName;

    appClassName = sapp.appName.UTF8String;
    AppClass = objc_allocateClassPair(
        RXERuntimeObject.class,
        appClassName,
        0
    );
}

+ (void)exportSuite:(RXEScriptSuite *)suite
    appInstance:(Application *)app
    context:(JSContext *)ctx
{

}

+ (void)exportCommand
{

}

+ (void)exportClass:(RXEScriptClass *)class
    appInstance:(Application *)app
    ctx:(JSContext *)ctx
{

}

@end
