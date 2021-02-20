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

// map js context instances to runtime controller instances
static NSMapTable<JSContext *, RXERuntimeController *> *contextTable;

static void RXERuntimeControllerInitContextTable()
{
    NSPointerFunctionsOptions keyOptions, valueOptions;

    keyOptions = NSPointerFunctionsOpaqueMemory;
    keyOptions |= NSPointerFunctionsOpaquePersonality;

    valueOptions = NSPointerFunctionsWeakMemory;
    valueOptions |= NSPointerFunctionsObjectPersonality;

    assert(!contextTable);
    contextTable = [[NSMapTable<JSContext *, RXERuntimeController *> alloc]
        initWithKeyOptions:keyOptions
        valueOptions:valueOptions
        capacity:0
    ];
}

static NSMapTable *RXERuntimeControllerContextTable()
{
    if (!contextTable)
        RXERuntimeControllerInitContextTable();
    return contextTable;
}

#define ctxTable() RXERuntimeControllerContextTable()

@implementation RXERuntimeController {
    JSContext *_context;
    NSMapTable *_symbolTable;
}

- init
{
    SLYTraceCall();

    if (!(self = [super init]))
        return self;

    _context = [[JSContext alloc] init];
    [self.class associateJSContext:_context withRuntimeController:self];;
    _symbolTable = [self symbolTable];
    [self exportFundamentalClasses];

    return self;
}

+ (void)associateJSContext:(JSContext *)ctx
    withRuntimeController:(RXERuntimeController *)rt
{
    NSMapInsert(ctxTable(), (__bridge void *)ctx, (__bridge void *)rt);
}

+ (RXERuntimeController *)runtimeControllerForJSContext:(JSContext *)ctx
{
    return (__bridge RXERuntimeController *)NSMapGet(ctxTable(), (__bridge void *)ctx);
}

- (JSContext *)JSContext
{
    return _context;
}

- (NSMapTable *)symbolTable
{
    NSPointerFunctionsOptions keyOptions, valueOptions;

    if (_symbolTable)
        return _symbolTable;

    keyOptions = NSPointerFunctionsOpaqueMemory;
    keyOptions |= NSPointerFunctionsOpaquePersonality;

    valueOptions = NSPointerFunctionsWeakMemory;
    valueOptions |= NSPointerFunctionsObjectPersonality;

    return _symbolTable = [[NSMapTable<NSString *, id> alloc]
        initWithKeyOptions:keyOptions
        valueOptions:valueOptions
        capacity:0
    ];
}

- (void)registerSymbol:(id)symbol name:(NSString *)name
{

}

- (void)registerClass:(Class)class name:(NSString *)name
{

}

- (void)registerProtocol:(Protocol *)proto name:(NSString *)name
{

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
        for (RXEScriptProperty *prop in class.properties)
            RXERuntimeClassExportProperty(appClass, prop);
    }
}

@end
