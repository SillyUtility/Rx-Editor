//
//  RXEUtilities.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/4/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <JavaScriptCore/JavaScriptCore.h>
#import <SillyLog/SillyLog.h>

#import "RXEUtilities.h"
#import "RXERuntimeObject.h"
#import "RXEScriptableApp.h"
#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"

#ifdef DEBUG
const char *_protocol_getMethodTypeEncoding(
    Protocol *p, SEL sel, BOOL isRequiredMethod, BOOL isInstanceMethod);
#endif

typedef struct method_t {
    SEL name;
    const char *types;
    IMP imp;
} method_t;

typedef struct method_list_t {
    uint32_t entsize_NEVER_USE;  // high bits used for fixup markers
    uint32_t count;
    method_t first;
} method_list_t;

typedef struct ivar_t {
    // *offset is 64-bit by accident even though other
    // fields restrict total instance size to 32-bit.
    uintptr_t *offset;
    const char *name;
    const char *type;
    // alignment is sometimes -1; use ivar_alignment() instead
    uint32_t alignment  __attribute__((deprecated));
    uint32_t size;
} ivar_t;

typedef struct ivar_list_t {
    uint32_t entsize;
    uint32_t count;
    ivar_t first;
} ivar_list_t;

typedef struct objc_property {
    const char *name;
    const char *attributes;
} property_t;

typedef struct property_list_t {
    uint32_t entsize;
    uint32_t count;
    property_t first;
} property_list_t;

typedef uintptr_t protocol_ref_t;  // protocol_t *, but unremapped

typedef struct protocol_t {
    id isa;
    const char *name;
    struct protocol_list_t *protocols;
    method_list_t *instanceMethods;
    method_list_t *classMethods;
    method_list_t *optionalInstanceMethods;
    method_list_t *optionalClassMethods;
    property_list_t *instanceProperties;
    uint32_t size;   // sizeof(protocol_t)
    uint32_t flags;
    const char **_extendedMethodTypes;
    const char *_demangledName;
    property_list_t *_classProperties;
} protocol_t;

typedef struct protocol_list_t {
    // count is 64-bit by accident.
    uintptr_t count;
    protocol_ref_t list[0]; // variable-size
} protocol_list_t;

#define newcls(cls) ((class_t *)cls)
#define newmethod(meth) ((method_t *)meth)
#define newivar(ivar) ((ivar_t *)ivar)
#define newcategory(cat) ((category_t *)cat)
#define newprotocol(p) ((__bridge protocol_t *)p)
#define newproperty(p) ((property_t *)p)

static const uint32_t method_flag_mask = 0xffff0003;

// low bit used by dyld shared cache
static uint32_t method_list_entsize(const method_list_t *mlist)
{
    return mlist->entsize_NEVER_USE & ~method_flag_mask;
}

#if 0 /* unused functions */
static const uint32_t small_method_list_flag = 0x80000000;

static BOOL method_is_small(const method_t *m)
{
    return ((uintptr_t)m & 1) == 1;
}

static uint32_t method_list_flags(const method_list_t *mlist)
{
    return mlist->entsize_NEVER_USE & method_flag_mask;
}

static uint32_t method_list_is_small(const method_list_t *mlist)
{
    return method_list_flags(mlist) & small_method_list_flag;
}

static size_t method_list_size(const method_list_t *mlist)
{
    return sizeof(method_list_t)
        + (mlist->count - 1) * method_list_entsize(mlist);
}
#endif

static method_t *method_list_nth(const method_list_t *mlist, uint32_t i)
{
    assert(i < mlist->count);
    return (method_t *)(i * method_list_entsize(mlist)
        + (char *)&mlist->first);
}

static uint32_t method_list_count(const method_list_t *mlist)
{
    return mlist ? mlist->count : 0;
}

#if 0 /* unused functions */
static uint32_t method_list_index
    (const method_list_t *mlist, const method_t *m)
{

    uint32 entsize = method_list_entsize(mlist);
    return mlist ?
        (uint32_t)(((uintptr_t)m - (uintptr_t)mlist) / entsize) : 0;
}
#endif

static int rxe_method_list_search(
    const method_list_t *mlist, const method_t *m)
{
    uint32_t i, count;

    count = method_list_count(mlist);

    for (i = 0; i < count; i++)
        if (method_list_nth(mlist, i)->name == m->name)
            return i;

    return -1;
}

static uint32_t rxe_protocol_getExtendedTypeIndexForMethod(
    protocol_t *proto,
    const method_t *m,
    BOOL required,
    BOOL instance)
{
    uint32_t a = 0;
    uint32_t b = 0;

    if (required && instance) {
        b = rxe_method_list_search(proto->instanceMethods, m);
        return a + b;
    }
    a += method_list_count(proto->instanceMethods);

    if (required && !instance) {
        b = rxe_method_list_search(proto->classMethods, m);
        return a + b;
    }
    a += method_list_count(proto->classMethods);

    if (!required && instance) {
        b = rxe_method_list_search(proto->optionalInstanceMethods, m);
        return a + b;
    }
    a += method_list_count(proto->optionalInstanceMethods);

    if (!required && !instance) {
        b = rxe_method_list_search(proto->optionalClassMethods, m);
        return a + b;
    }
    a += method_list_count(proto->optionalClassMethods);

    return a + b;
}

static uint32_t rxe_protocol_method_count(protocol_t *proto)
{
    return method_list_count(proto->instanceMethods)
        + method_list_count(proto->classMethods)
        + method_list_count(proto->optionalInstanceMethods)
        + method_list_count(proto->optionalClassMethods);
}

@implementation RXEUtilities

@end

/*
    - Ensure the first character is an ascii letter
    - Capitablize the first character of every word
    - Preserve the case of any other character
    - Remove spaces and special characters
 */
NSString *RXEClassNameFromString(NSString *str)
{
    NSMutableString *name;
    NSUInteger i;
    unichar c;
    NSCharacterSet *wsSet;
    BOOL capitalizeNext;

    name = NSMutableString.string;
    wsSet = NSCharacterSet.whitespaceAndNewlineCharacterSet;
    capitalizeNext = NO;
    str = [str
        stringByApplyingTransform:NSStringTransformToLatin
        reverse:NO
    ];

    for (i = 0; i < str.length; i++) {
        c = [str characterAtIndex:i];
        if ([wsSet characterIsMember:c]) {
            capitalizeNext = YES;
            continue;
        } else if (isalpha(c)) {
            if (name.length == 0 || capitalizeNext) {
                capitalizeNext = NO;
                c = toupper(c);
            }
        } else if (isdigit(c)) {
            if (name.length == 0)
                continue;
            capitalizeNext = NO;
        } else {
            if (name.length == 0)
                continue;
            capitalizeNext = YES;
            c = '_';
        }
        [name appendFormat:@"%c", c];
    }
    return name;
}

NSString *RXEPropertyNameFromString(NSString *str)
{
    NSString *name;
    return name;
}

NSString *RXEMethodNameFromString(NSString *str)
{
    NSString *name;
    return name;
}

Protocol *RXEExportProtocolForClassName(NSString *className)
{
    Protocol *ExportProtocol;
    Protocol *JSExportProtocol;
    const char *exportProtocolName;

    exportProtocolName = [className stringByAppendingString:@"Exports"].UTF8String;
    ExportProtocol = objc_allocateProtocol(exportProtocolName);

    JSExportProtocol = objc_getProtocol("JSExport");
    protocol_addProtocol(ExportProtocol, JSExportProtocol);

    return ExportProtocol;
}

Protocol *RXEGetExportProtocolForClass(Class class)
{
    Protocol *ExportProtocol;
    const char *exportProtocolName;
    Protocol * __unsafe_unretained _Nonnull *protoList;
    unsigned int outc;

    exportProtocolName = [NSString stringWithFormat:@"%sExports", class_getName(class)].UTF8String;
    //ExportProtocol = objc_getProtocol(exportProtocolName);

    protoList = class_copyProtocolList(class, &outc);
    for (unsigned int i = 0; i < outc; i++) {
        const char *protoName = protocol_getName(protoList[i]);
        if (strcmp(protoName, exportProtocolName) == 0) {
            ExportProtocol = protoList[i];
            break;
        }
    }

    return ExportProtocol;
}

void rxe_protocol_addExtendedTypesForMethod(
    Protocol *proto, SEL sel, const char *extTypes)
{
    protocol_t *p;
    method_t *m;
    struct objc_method_description m_desc;
    uint32_t m_index, m_count;
    BOOL required = YES, instance = YES;

    p = newprotocol(proto);
    m_desc = protocol_getMethodDescription(proto, sel, required, instance);
    m = newmethod(&m_desc);
    m_index = rxe_protocol_getExtendedTypeIndexForMethod(p, m, required, instance);
    m_count = rxe_protocol_method_count(p);
    if (p->_extendedMethodTypes) {
        if (m_index > m_count)
            p->_extendedMethodTypes = realloc(
                p->_extendedMethodTypes, m_index * sizeof(char *));
    } else {
        p->_extendedMethodTypes = calloc(m_count, sizeof(char *));
    }

    p->_extendedMethodTypes[m_index] = strdup(extTypes);
}

void RXERuntimeClassExportProperty(Class class, RXEScriptProperty *property)
{
    BOOL success;
    Protocol *proto;
    SEL getSel;//, setSel;
    IMP getImp;//, setImp;
    const char *propName, *propVar,
        *getName, *setName, *getType,
        *setType, *getExtType, *setExtName,
        *className, *protoName;

    proto = RXEGetExportProtocolForClass(class);

    className = class_getName(class);
    protoName = protocol_getName(proto);

    propName = property.name.UTF8String;
    propVar = [NSString stringWithFormat:@"_%@", property.name].UTF8String;
    getName = strdup(propName);
    setName = [NSString stringWithFormat:@"set%@:", property.name.capitalizedString].UTF8String;
    getType = "@16@0:8";
    setType = "v@:@";
    getExtType = "@\"NSString\"16@0:8";
    setExtName = "";

    const objc_property_attribute_t pattrs[] = {
        { "T", "@\"NSString\"" /*@encode(NSString *)*/ },
        { "R", "" },
        //{ "G", getName },
        //{ "V", propVar },
    };
    success = class_addProperty(class, propName, pattrs, 2);
    SLYTrace(@"add prop %s to %s? %@", propName, className, @(success));

    protocol_addProperty(proto, propName, pattrs, 2, YES, YES);
    SLYTrace(@"add prop %s to %s? %@", propName, protoName, @(success));

    getSel = sel_registerName(getName);
    getImp = (IMP)getString_Property;
    success = class_addMethod(class, getSel, getImp, getType);
    SLYTrace(@"add meth %s to %s? %@", getName, className, @(success));

    protocol_addMethodDescription(proto, getSel, getType, YES, YES);
    SLYTrace(@"add meth %s to %s", getName, protoName);

    rxe_protocol_addExtendedTypesForMethod(proto, getSel, getExtType);

//    setSel = sel_registerName(setName);
//    setImp = (IMP)setString_Property;
//    success = class_addMethod(class, setSel, setImp, setType);
//    SLYTrace(@"add meth %s to %s? %@", setName, className, @(success));
//
//    protocol_addMethodDescription(proto, setSel, setType, YES, YES);
//    SLYTrace(@"add meth %s to %s", setName, protoName);
//
//    rxe_protocol_addExtendedTypesForMethod(proto, setSel, setExtType);
}

NSString *RXEDescribeClass(Class class)
{
    NSMutableString *description;
    Class superclass;
    const char *name, *supername;
    Protocol * __unsafe_unretained _Nonnull * _Nullable protolist;
    Ivar _Nonnull * _Nullable ivarlist;
    objc_property_t _Nonnull * _Nullable proplist;
    Method _Nonnull * _Nullable methodlist;
    unsigned int i, outc;

    description = NSMutableString.string;
    name = class_getName(class);
    superclass = class_getSuperclass(class);
    supername = class_getName(superclass);

    [description appendFormat:@"%s extends %s\n", name, supername];

    protolist = class_copyProtocolList(class, &outc);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\tconforms to %s\n", protocol_getName(protolist[i])];

    ivarlist = class_copyIvarList(class, &outc);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\tivar %@\n", RXEDescribeIvar(ivarlist[i])];

    proplist = class_copyPropertyList(class, &outc);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\tprop %@\n", RXEDescribeProperty(proplist[i])];

    methodlist = class_copyMethodList(class, &outc);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\tmeth %@\n", RXEDescribeMethod(methodlist[i])];

    return description;
}

NSString *RXEDescribeProtocol(Protocol *proto)
{
    NSMutableString *description;
    const char *name, *types = NULL;
    Protocol * __unsafe_unretained _Nonnull * _Nullable protolist;
    objc_property_t _Nonnull * _Nullable proplist;
    struct objc_method_description * _Nullable methodlist;
    unsigned int i, outc;

    description = NSMutableString.string;
    name = protocol_getName(proto);

    [description appendFormat:@"%s\n", name];

    protolist = protocol_copyProtocolList(proto, &outc);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\tconforms to %s\n", protocol_getName(protolist[i])];

    proplist = protocol_copyPropertyList2(proto, &outc, YES, YES);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\tr prop %@\n", RXEDescribeProperty(proplist[i])];

    proplist = protocol_copyPropertyList2(proto, &outc, NO, YES);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\to prop %@\n", RXEDescribeProperty(proplist[i])];

    methodlist = protocol_copyMethodDescriptionList(proto, YES, YES, &outc);
    for (i = 0; i < outc; i++) {
#ifdef DEBUG
        types = _protocol_getMethodTypeEncoding(proto, methodlist[i].name, YES, YES);
#endif
        [description appendFormat:@"\tr meth %s %s (ext: %s)\n",
            sel_getName(methodlist[i].name),
            methodlist[i].types, types ? types : "NULL"
        ];
    }

    methodlist = protocol_copyMethodDescriptionList(proto, NO, YES, &outc);
    for (i = 0; i < outc; i++) {
#ifdef DEBUG
        types = _protocol_getMethodTypeEncoding(proto, methodlist[i].name, NO, YES);
#endif
        [description appendFormat:@"\to meth %s %s (ext: %s)\n",
            sel_getName(methodlist[i].name),
            methodlist[i].types, types ? types : "NULL"
        ];
    }

    return description;
}

NSString *RXEDescribeProperty(objc_property_t prop)
{
    const char *name, *attrs;

    name = property_getName(prop);
    attrs = property_getAttributes(prop);

    return [NSString stringWithFormat:@"%s %s",
        name,
        attrs
    ];
}

NSString *RXEDescribeMethod(Method meth)
{
    SEL sel;
    IMP imp;
    const char *name, *sig;

    sel = method_getName(meth);
    imp = method_getImplementation(meth);
    name = sel_getName(sel);
    sig = method_getTypeEncoding(meth);

    return [NSString stringWithFormat:@"%s %s %p",
        name,
        sig,
        (void *)imp
    ];
}

NSString *RXEDescribeIvar(Ivar ivar)
{
    const char *name, *type;
    ptrdiff_t offset;

    name = ivar_getName(ivar);
    type = ivar_getTypeEncoding(ivar);
    offset = ivar_getOffset(ivar);

    return [NSString stringWithFormat:@"%s %s %td",
        name,
        type,
        offset
    ];
}
