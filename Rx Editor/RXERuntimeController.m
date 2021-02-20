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
#import "RXERuntimeSymbol.h"
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
    NSMapInsert(ctxTable(),
        (__bridge void *)ctx,
        (__bridge void *)rt
    );
}

+ (RXERuntimeController *)runtimeControllerForJSContext:(JSContext *)ctx
{
    return (__bridge RXERuntimeController *)NSMapGet(ctxTable(),
        (__bridge void *)ctx);
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
    RXERuntimeSymbol *symbol;
    symbol = [[RXERuntimeSymbol alloc] initWithClass:class];
    NSMapInsert(self.symbolTable,
        (__bridge const void * _Nullable)(name),
        (__bridge const void * _Nullable)(class)
    );
}

- (void)registerProtocol:(Protocol *)proto name:(NSString *)name
{

}

- (Class)classNamed:(NSString *)name
{
    return (__bridge Class)NSMapGet(self.symbolTable,
        (__bridge void *)name);
}

- (Protocol *)protocolNamed:(NSString *)name
{
    return (__bridge Protocol *)NSMapGet(self.symbolTable,
        (__bridge void *)name);
}

- (void)exportFundamentalClasses
{
    [self registerClass:Application.class name:@"Application"];
    _context[@"Application"] = Application.class;
}

#if 0
+ (Class)exportScriptableApp:(RXEScriptableApp *)sapp
    appInstance:(Application *)app
    context:(JSContext *)ctx
{
    Class AppClass;

    SLYTraceCall(@"_scriptableApp %@", sapp);

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
#endif

+ (Class)exportScriptableApp:(RXEScriptableApp *)sapp
    inContext:(JSContext *)ctx
{
    RXERuntimeController *rt;
    rt = [self runtimeControllerForJSContext:ctx];
    return [rt exportScriptableApp:sapp];
}

- (Class)exportScriptableApp:(RXEScriptableApp *)sapp
{
    for (id suite in sapp.suites)
        [self exportSuite:suite];

    // TODO: export symbols to js ctx
    // for each symbol key that is a class
    //     _context[symbolKey] = class;

    return [self classNamed:sapp.appClassName];
}

- (void)exportSuite:(RXEScriptSuite *)suite
{
    // TODO: suite.cocoaImp

    for (RXEScriptAccessGroup *accessGroup in suite.accessGroups)
        SLYTrace(@"accessGroup %@", accessGroup);

    for (RXEScriptClass *class in suite.classes)
        [self exportClass:class];

    for (RXEScriptClassExt *classExt in suite.classExts)
        [self exportClassExtention:classExt];

    for (RXEScriptCommand *command in suite.commands)
        [self exportCommand:command];

    for (RXEScriptEnumeration *enumeration in suite.enumerations)
        [self exportEnumeration:enumeration];

    for (RXEScriptEvent *event in suite.events)
        [self exportEvent:event];

    for (RXEScriptRecordType *recordType in suite.recordTypes)
        [self exportRecordType:recordType];

    for (RXEScriptValueType *valueType in suite.valueTypes)
        [self exportValueType:valueType];

    for (RXEScriptDocumentation *doc in suite.docs)
        SLYTrace(@"doc %@", doc);
}

- (void)exportClass:(RXEScriptClass *)class
{
    Class cls;
    NSString *className;

    if ([class.name isEqualToString:@"application"]) {
        className = class.app.appClassName;
        cls = [self classNamed:className];
    } else {
        className = class.className; // FIXME: wrong class name
        cls = [self classNamed:className];
    }

    if (!cls) {
        cls = RXERuntimeMakeClass(className);
        [self registerClass:cls name:className];
        [self registerProtocol:nil /* export proto */ name:nil /* className + Exports */];
    }

    for (RXEScriptProperty *prop in class.properties)
        RXERuntimeClassExportProperty(cls, prop);

    for (RXEScriptElement *element in class.elements)
        SLYTrace(@"element %@", element);

    for (RXEScriptClassCommand *method in class.classCommands)
        SLYTrace(@"method %@", method);
}

- (void)exportClassExtention:(RXEScriptClassExt *)classExt
{

}

- (void)exportCommand:(RXEScriptCommand *)command
{

}

- (void)exportEnumeration:(RXEScriptEnumeration *)enumeration
{

}

- (void)exportEvent:(RXEScriptEvent *)event
{

}

- (void)exportRecordType:(RXEScriptRecordType *)recordType
{

}

- (void)exportValueType:(RXEScriptValueType *)valueType
{

}

@end
