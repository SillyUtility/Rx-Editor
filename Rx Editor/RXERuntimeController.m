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
#import "RXEUtilities.h"
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

+ (Class)exportScriptableApp:(RXEScriptableApp *)sapp
    appInstance:(Application *)app
    context:(JSContext *)ctx
{
    SLYTrace(@"_scriptableApp %@", sapp);

    Class AppClass;

    AppClass = [self exportAppClass:sapp appInstance:app context:ctx];

    for (id suite in sapp.suites)
        [self exportSuite:suite appClass:AppClass context:ctx];

    // TODO: register classes & protocols
    objc_registerClassPair(AppClass);
    objc_registerProtocol(RXEGetExportProtocolForClass(AppClass));

    ctx[sapp.appClassName] = AppClass;

    return AppClass;
}

+ (Class)exportAppClass:(RXEScriptableApp *)sapp
    appInstance:(Application *)app
    context:(JSContext *)ctx
{
    Class AppClass;
    Protocol *ExportProtocol;
    NSString *className;
    const char *appClassName;

    className = sapp.appClassName;
    appClassName = className.UTF8String;
    AppClass = objc_allocateClassPair(
        RXERuntimeObject.class,
        appClassName,
        0
    );

    ExportProtocol = RXEExportProtocolForClassName(className);
    class_addProtocol(AppClass, ExportProtocol);

    return AppClass;
}

+ (void)exportSuite:(RXEScriptSuite *)suite
    appClass:(Class)appClass
    context:(JSContext *)ctx
{
    for (id class in suite.classes)
        [self exportClass:class appClass:appClass ctx:ctx];
}

+ (void)exportCommand
{

}

+ (void)exportClass:(RXEScriptClass *)class
    appClass:(Class)appClass
    ctx:(JSContext *)ctx
{
    if ([class.name isEqualToString:@"application"]) {
        SLYTrace(@"construct the application class");
        RXEScriptProperty *prop = [[RXEScriptProperty alloc] initWithAttributes:@{
            @"name": @"version",
            @"code": @"vers",
            @"type": @"text",
            @"access": @"r",
            @"description": @"the version of the Finder",
        }];
        RXERuntimeClassExportProperty(appClass, prop);
    }
}

@end
