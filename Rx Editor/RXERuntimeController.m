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
    [ctxTable() setObject:rt forKey:ctx];
}

+ (RXERuntimeController *)runtimeControllerForJSContext:(JSContext *)ctx
{
    return [ctxTable() objectForKey:ctx];
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

    keyOptions = NSPointerFunctionsObjectPersonality;

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
    [self.symbolTable setObject:symbol forKey:name];
}

- (RXERuntimeSymbol *)registerClass:(Class)class name:(NSString *)name
{
    RXERuntimeSymbol *symbol;
    symbol = [[RXERuntimeSymbol alloc] initWithClass:class];
    [self registerSymbol:symbol name:name];
    return symbol;
}

- (RXERuntimeSymbol *)registerProtocol:(Protocol *)proto name:(NSString *)name
{
    RXERuntimeSymbol *symbol;
    symbol = [[RXERuntimeSymbol alloc] initWithProtocol:proto];
    [self registerSymbol:symbol name:name];
    return symbol;
}

- (id)symbolNamed:(NSString *)name
{
    return [self.symbolTable objectForKey:name];
}

- (Class)classNamed:(NSString *)name
{
    RXERuntimeSymbol *symbol;
    symbol = [self symbolNamed:name];
    if (!symbol)
        return nil;
    return symbol.symbolClass;
}

- (Protocol *)protocolNamed:(NSString *)name
{
    RXERuntimeSymbol *symbol;
    symbol = [self symbolNamed:name];
    if (!symbol)
        return nil;
    return symbol.symbolProtocol;
}

- (void)exportFundamentalClasses
{
    [[self registerClass:Application.class name:@"Application"]
        exportToJSContext:_context];
}

- (void)realizeSymbols
{
    NSEnumerator *enumerator;
    RXERuntimeSymbol *symbol;

    enumerator = self.symbolTable.objectEnumerator;
    while ((symbol = enumerator.nextObject))
        [symbol registerSymbolWithObjCRuntime];
}

- (void)exportSymbolsToJS
{
    NSEnumerator *enumerator;
    RXERuntimeSymbol *symbol;

    enumerator = self.symbolTable.objectEnumerator;
    while ((symbol = enumerator.nextObject))
        if (symbol.isClass)
            [symbol exportToJSContext:_context];
}

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

    [self realizeSymbols];
    //[self exportSymbolsToJS];

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
    Protocol *protocol;
    NSString *className;
    NSString *protoName;

    if ([class.name isEqualToString:@"application"]) {
        className = class.app.appClassName;
        cls = [self classNamed:className];
    } else {
        className = class.exportName;
        cls = [self classNamed:className];
    }

    if (!cls) {
        cls = RXERuntimeMakeClass(className);
        [self registerClass:cls name:className];

        protoName = RXEExportsProtocolNameFromClassName(className);
        protocol = RXEClassFindExportsProtocol(cls);
        [self registerProtocol:protocol name:protoName];
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
