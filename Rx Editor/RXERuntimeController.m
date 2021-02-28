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
#import "RXERuntimeTypes.h"
#import "RXERuntimeObject.h"
#import "RXEScriptableApp.h"
#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"
#import "RXEUtilities.h"
#import "RXEObjCRuntime.h"
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
    NSMutableDictionary<NSString *, RXEScriptableApp *> *_scriptableApps;
    NSMapTable<NSString *, id> *_symbolTable;
    NSMapTable<Class, RXERuntimeClassDescription *> *_classTable;
}

- init
{
    SLYTraceCall();

    if (!(self = [super init]))
        return self;

    _context = [[JSContext alloc] init];
    [self.class associateJSContext:_context withRuntimeController:self];;
    _scriptableApps = NSMutableDictionary.dictionary;
    _symbolTable = self.symbolTable;
    _classTable = self.classTable;
    [self exportFundamentalClasses];

    return self;
}

- (void)addScriptableApp:(RXEScriptableApp *)sapp forClassName:(NSString *)className
{
    _scriptableApps[className] = sapp;
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

- (NSMapTable<NSString *, id> *)symbolTable
{
    NSPointerFunctionsOptions keyOptions, valueOptions;

    if (_symbolTable)
        return _symbolTable;

    keyOptions = NSPointerFunctionsObjectPersonality;

    valueOptions = NSPointerFunctionsStrongMemory;
    valueOptions |= NSPointerFunctionsObjectPersonality;

    return _symbolTable = [[NSMapTable<NSString *, id> alloc]
        initWithKeyOptions:keyOptions
        valueOptions:valueOptions
        capacity:0
    ];
}

- (NSMapTable<Class, RXERuntimeClassDescription *> *)classTable
{
    NSPointerFunctionsOptions keyOptions, valueOptions;

    if (_classTable)
        return _classTable;

    keyOptions = NSPointerFunctionsOpaqueMemory;
    keyOptions |= NSPointerFunctionsOpaquePersonality;

    valueOptions = NSPointerFunctionsStrongMemory;
    valueOptions |= NSPointerFunctionsObjectPersonality;

    return _classTable = [[NSMapTable<Class, RXERuntimeClassDescription *> alloc]
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

- (Class)classForType:(NSString *)typeName
{
    NSString *className;
    Class class;

    className = typeName;// RXEClassNameFromString(typeName);
    class = [self classNamed:className];
    class = [self class:class named:className];

    return class;
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
    [self addScriptableApp:sapp forClassName:sapp.appClassName];

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

- (Class)class:(Class)cls named:(NSString *)className
{
    Protocol *protocol;
    NSString *protoName;

    if (!cls) {
        cls = RXERuntimeMakeClass(className);
        [self registerClass:cls name:className];

        protoName = RXEExportsProtocolNameFromClassName(className);
        protocol = RXEClassFindExportsProtocol(cls);
        [self registerProtocol:protocol name:protoName];
    }

    return cls;
}

- (void)exportClass:(RXEScriptClass *)class
{
    Class cls;
    NSString *className;

    if ([class.name isEqualToString:@"application"]) {
        className = class.app.appClassName;
        cls = [self classNamed:className];
    } else {
        className = class.exportName;
        cls = [self classNamed:className];
    }

    cls = [self class:cls named:className];

    for (RXEScriptProperty *prop in class.properties)
        [self exportClass:cls property:prop];

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

// "set" Name ":\0"  => nameLength + 5.
static const char *rxe_make_setter_name(const char* name)
{
    size_t nameLength;
    char *buffer;

    nameLength = strlen(name);
    buffer = calloc(nameLength + 5, sizeof(char));
    buffer[0] = 's';
    buffer[1] = 'e';
    buffer[2] = 't';
    buffer[3] = toupper(*name);
    memcpy(buffer + 4, name + 1, nameLength - 1);
    buffer[nameLength + 3] = ':';
    buffer[nameLength + 4] = 0;

    return buffer;
}

BOOL RXEBuiltInScriptType(NSString *type)
{
    if ([type isEqualToString:@"text"])
        return YES;
    if ([type isEqualToString:@"boolean"])
        return YES;
    if ([type isEqualToString:@"integer"])
        return YES;
    if ([type isEqualToString:@"double integer"])
        return YES;
    if ([type isEqualToString:@"real"])
        return YES;
    if ([type isEqualToString:@"number"])
        return YES;
    if ([type isEqualToString:@"type"])
        return YES;
    if ([type isEqualToString:@"record"])
        return YES;
    if ([type isEqualToString:@"list"])
        return YES;
    if ([type isEqualToString:@"date"])
        return YES;
    if ([type isEqualToString:@"point"])
        return YES;
    if ([type isEqualToString:@"rectangle"])
        return YES;

    return NO;
}

BOOL RXESkipScriptType_To_Be_Removed(NSString *type)
{
    if ([type isEqualToString:@"any"])
        return YES;
    if ([type isEqualToString:@"specifier"])
        return YES;
    if ([type isEqualToString:@"location specifier"])
        return YES;

    return NO;
}

const char *RXEEncodedTypeForScriptType(NSString *type)
{
    if ([type isEqualToString:@"text"])
        return strdup(@encode(NSString *));
    if ([type isEqualToString:@"boolean"])
        return strdup(@encode(NSNumber *));
    if ([type isEqualToString:@"integer"])
        return strdup(@encode(long));
    if ([type isEqualToString:@"double integer"])
        return strdup(@encode(long long));
    if ([type isEqualToString:@"real"])
        return strdup(@encode(double));
    if ([type isEqualToString:@"number"])
        return strdup(@encode(NSNumber *));
    if ([type isEqualToString:@"type"])
        return strdup(@encode(NSNumber *));
    if ([type isEqualToString:@"record"])
        return strdup(@encode(NSDictionary *));
    if ([type isEqualToString:@"list"])
        return strdup(@encode(NSArray *));
    if ([type isEqualToString:@"date"])
        return strdup(@encode(NSDate *));
    if ([type isEqualToString:@"point"])
        return strdup(@encode(CGPoint));
    if ([type isEqualToString:@"rectangle"])
        strdup(@encode(CGRect));

    return strdup(@encode(id));
}

const char *RXEEncodedExtendedTypeForScriptType(NSString *type)
{
    NSString *c;

    if ([type isEqualToString:@"text"])
        c = NSStringFromClass(NSString.class);
    else if ([type isEqualToString:@"boolean"])
        c = NSStringFromClass(NSNumber.class);
    else if ([type isEqualToString:@"number"])
        c = NSStringFromClass(NSNumber.class);
    else if ([type isEqualToString:@"type"])
        c = NSStringFromClass(NSNumber.class);
    else if ([type isEqualToString:@"record"])
        c = NSStringFromClass(NSDictionary.class);
    else if ([type isEqualToString:@"list"])
        c = NSStringFromClass(NSArray.class);
    else if ([type isEqualToString:@"date"])
        c = NSStringFromClass(NSDate.class);
//    else if ([type isEqualToString:@"point"])
//        return strdup(@encode(CGPoint));
//    else if ([type isEqualToString:@"rectangle"])
//        strdup(@encode(CGRect));

    // TODO: other @ types

    if (c)
        return [NSString stringWithFormat:@"\"%@\"", c].UTF8String;

    return strdup("");
}

NSString *RXEGetterTypesForProperty(RXEScriptProperty *prop)
{
    return [NSString stringWithFormat:@"%s16@0:8",
        RXEEncodedTypeForScriptType(prop.type)
    ];
}

NSString *RXEGetterExtendedTypesForProperty(RXEScriptProperty *prop)
{
    return [NSString stringWithFormat:@"%s%s16@0:8",
        RXEEncodedTypeForScriptType(prop.type),
        RXEEncodedExtendedTypeForScriptType(prop.type)
    ];
}

IMP RXEGetterImplementationForPropertyType(NSString *type)
{
    if ([type isEqualToString:@"text"])
        return (IMP)getString_Property;
    if ([type isEqualToString:@"boolean"])
        return (IMP)getBoxedBool_Property;
    if ([type isEqualToString:@"integer"])
        return (IMP)getLong_Property;
    if ([type isEqualToString:@"double integer"])
        return (IMP)getLongLong_Property;
    if ([type isEqualToString:@"real"])
        return (IMP)getDouble_Property;
    if ([type isEqualToString:@"number"])
        return (IMP)getBoxedNumber_Property;
    if ([type isEqualToString:@"type"])
        return (IMP)getBoxedOSType_Property;
    if ([type isEqualToString:@"record"])
        return (IMP)getDictionary_Property;
    if ([type isEqualToString:@"list"])
        return (IMP)getArray_Property;
    if ([type isEqualToString:@"date"])
        return (IMP)getDate_Property;

    return (IMP)getWrappedObject_Property;
}

//{ "T", "@\"NSString\""  },
//{ "R", "" },
//{ "G", getName },
//{ "S", setName },
//{ "V", propVar },
objc_property_attribute_t *RXEPropertyAttributesForProperty(
    RXEScriptProperty *prop, unsigned int *outc)
{
    objc_property_attribute_t *pa;

    if ((YES) /*prop.isReadOnly*/) {
        pa = calloc((*outc = 2), sizeof(objc_property_attribute_t));
        pa[1].name = strdup("R");
        pa[1].value = strdup("");
    } else {
        pa = calloc((*outc = 1), sizeof(objc_property_attribute_t));
    }

    pa[0].name = strdup("T");
    pa[0].value = strdup([NSString stringWithFormat:@"%s%s",
        RXEEncodedTypeForScriptType(prop.type),
        RXEEncodedExtendedTypeForScriptType(prop.type)
    ].UTF8String);

    return pa;
}

- (void)exportClass:(Class)class property:(RXEScriptProperty *)property
{
    BOOL success;
    Protocol *proto;
    SEL getSel, setSel;
    IMP getImp, setImp;
    const char *propName,/* *propVar, */
        *getName, *getTypes, *getExtTypes,
        *setName, *setTypes, *setExtTypes,
        *className, *protoName;
    objc_property_attribute_t *pattrs;
    unsigned int outc;

    if (RXESkipScriptType_To_Be_Removed(property.type))
         return;

    if (property.typeDefinition.isEnumeration)
        return;

    proto = RXEClassFindExportsProtocol(class);

    className = class_getName(class);
    protoName = protocol_getName(proto);

    propName = strdup(RXEPropertyNameFromString(property.name).UTF8String);
    getName = strdup(propName);
    getTypes = strdup(RXEGetterTypesForProperty(property).UTF8String);
    getExtTypes = strdup(RXEGetterExtendedTypesForProperty(property).UTF8String);
    pattrs = RXEPropertyAttributesForProperty(property, &outc);

    success = class_addProperty(class, propName,
        (const objc_property_attribute_t *)pattrs, outc);
    protocol_addProperty(proto, propName,
        (const objc_property_attribute_t *)pattrs, outc, YES, YES);

    getSel = sel_registerName(getName);
    getImp = RXEGetterImplementationForPropertyType(property.type);
    success = class_addMethod(class, getSel, getImp, getTypes);
    protocol_addMethodDescription(proto, getSel, getTypes, YES, YES);
    rxe_protocol_unfix(proto);
    rxe_protocol_addExtendedTypesForMethod(proto, getSel, getExtTypes);

    if (!RXEBuiltInScriptType(property.type))
        [self addSelector:getSel propertyType:property.exportTypeName toClass:class];

    SLYTrace(@"add prop %s to %s", propName, className);
    SLYTrace(@"\tattrs %s", copyPropertyAttributeString(pattrs, outc));
    SLYTrace(@"add prop %s to %s", propName, protoName);
    SLYTrace(@"\tattrs %s", copyPropertyAttributeString(pattrs, outc));
    SLYTrace(@"add meth %s to %s", getName, className);
    SLYTrace(@"\ttypes %s", getTypes);
    SLYTrace(@"add meth %s to %s", getName, protoName);
    SLYTrace(@"\ttypes %s", getTypes);
    SLYTrace(@"\text types %s", getExtTypes);

    if (property.isReadOnly)
        return;

    if (!property.isReadOnly)
        return; // skip

    setName = rxe_make_setter_name(propName);
    setTypes = "v@:@";
    setExtTypes = "";

    setSel = sel_registerName(setName);
    setImp = (IMP)setString_Property;
    success = class_addMethod(class, setSel, setImp, setTypes);
    protocol_addMethodDescription(proto, setSel, setTypes, YES, YES);
    rxe_protocol_unfix(proto);
    rxe_protocol_addExtendedTypesForMethod(proto, setSel, setExtTypes);
}

- (void)addSelector:(SEL)sel
    propertyType:(NSString *)typeName
    toClass:(Class)class
{
    const char *className = class_getName(class);
    const char *selName = sel_getName(sel);
    SLYTrace(@"ADD %s %s retType %@", className, selName, typeName);

    RXERuntimeMethodDescription *methDesc;
    Class retClass;

    retClass = [self classForType:typeName];
    methDesc = [[RXERuntimeMethodDescription alloc]
        initWithSelector:sel returnType:retClass];
    [self addMethodDescription:methDesc toClass:class];
}

- (void)addMethodDescription:(RXERuntimeMethodDescription *)methDesc
    toClass:(Class)class
{
    RXERuntimeClassDescription *classDesc;
    classDesc = [self classDescriptionForClass:class];
    [classDesc addMethodDescription:methDesc];
}

- (RXERuntimeClassDescription *)classDescriptionForClass:(Class)class
{
    RXERuntimeClassDescription *classDesc;
    classDesc = [self.classTable objectForKey:class];
    if (!classDesc) {
        classDesc = [[RXERuntimeClassDescription alloc] initWithClass:class];
        [self.classTable setObject:classDesc forKey:class];
    }
    return classDesc;
}

+ (RXERuntimeClassDescription *)classDescriptionForClass:(Class)class
    inContext:(JSContext *)ctx
{
    RXERuntimeController *rt;
    rt = [self runtimeControllerForJSContext:ctx];
    return [rt classDescriptionForClass:class];
}

@end
