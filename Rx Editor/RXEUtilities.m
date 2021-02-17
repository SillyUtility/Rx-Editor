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
    Protocol *p, SEL sel, BOOL required, BOOL instance);
#endif

/*
    License: APSL

    objc derivative
*/

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
    const method_list_t *mlist, SEL sel)
{
    uint32_t i, count;

    count = method_list_count(mlist);

    for (i = 0; i < count; i++)
        if (method_list_nth(mlist, i)->name == sel)
            return i;

    return -1;
}

static uint32_t rxe_protocol_getExtendedTypeIndexForMethod(
    protocol_t *proto,
    SEL sel,
    BOOL required,
    BOOL instance)
{
    uint32_t a = 0;
    uint32_t b = 0;

    if (required && instance) {
        b = rxe_method_list_search(proto->instanceMethods, sel);
        return a + b;
    }
    a += method_list_count(proto->instanceMethods);

    if (required && !instance) {
        b = rxe_method_list_search(proto->classMethods, sel);
        return a + b;
    }
    a += method_list_count(proto->classMethods);

    if (!required && instance) {
        b = rxe_method_list_search(proto->optionalInstanceMethods, sel);
        return a + b;
    }
    a += method_list_count(proto->optionalInstanceMethods);

    if (!required && !instance) {
        b = rxe_method_list_search(proto->optionalClassMethods, sel);
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

void rxe_protocol_addExtendedTypesForMethod(
    Protocol *proto, SEL sel, const char *extTypes)
{
    protocol_t *p;
    uint32_t m_index, m_count;
    BOOL required = YES, instance = YES;

    p = newprotocol(proto);
    m_index = rxe_protocol_getExtendedTypeIndexForMethod(p, sel, required, instance);
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

/*
    License: BSD 2-Clause

    JavaScriptCore derivative
*/

static const char *rxe_make_var_name(const char *name)
{
    size_t nameLength;
    char *buffer;

    nameLength = strlen(name);
    buffer = calloc(nameLength + 1, sizeof(char));
    buffer[0] = '_';
    memcpy(buffer + 1, name, nameLength);
    buffer[nameLength] = 0;

    return buffer;
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
    NSMutableString *name;
    NSArray<NSString *> *words;
    NSCharacterSet *wsSet;
    NSUInteger i;

    name = NSMutableString.string;
    wsSet = NSCharacterSet.whitespaceAndNewlineCharacterSet;
    words = [str componentsSeparatedByCharactersInSet:wsSet];

    for (i = 0; i < words.count; i++)
        if (i == 0)
            [name appendString:words[i]];
        else
            [name appendString:[words[i] capitalizedString]];

    return name;
}

NSString *RXEMethodNameFromString(NSString *str)
{
    NSString *name;
    return name;
}

const char *RXEEncodedTypeForScriptType(NSString *type)
{
    if ([type isEqualToString:@"text"])
        return strdup(@encode(NSString *));
    if ([type isEqualToString:@"boolean"])
        return strdup(@encode(BOOL));

    return strdup(@encode(id));
}

const char *RXEEncodedExtendedTypeForScriptType(NSString *type)
{
    NSString *c;

    if ([type isEqualToString:@"text"])
        c = NSStringFromClass(NSString.class);
    // else if ()

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
        return (IMP)getBool_Property;

    return (IMP)getObject_Property;
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

    if (YES /*prop.isReadOnly*/) {
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

    exportProtocolName = [NSString stringWithFormat:@"%sExports",
        class_getName(class)
    ].UTF8String;
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

void RXERuntimeClassExportProperty(Class class, RXEScriptProperty *property)
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

    if (![property.type isEqualToString:@"text"] && ![property.type isEqualToString:@"boolean"])
        return; // skip all but text & boolean for now

    proto = RXEGetExportProtocolForClass(class);

    className = class_getName(class);
    protoName = protocol_getName(proto);

    propName = strdup(RXEPropertyNameFromString(property.name).UTF8String);
    // FIXME: off by one
    //propVar = rxe_make_var_name(propName);

    getName = strdup(propName);
    getTypes = strdup(RXEGetterTypesForProperty(property).UTF8String);
    getExtTypes = strdup(RXEGetterExtendedTypesForProperty(property).UTF8String);

    pattrs = RXEPropertyAttributesForProperty(property, &outc);

    success = class_addProperty(class, propName,
        (const objc_property_attribute_t *)pattrs, outc);
    SLYTrace(@"add prop %s to %s? %@", propName, className, @(success));

    protocol_addProperty(proto, propName,
        (const objc_property_attribute_t *)pattrs, outc, YES, YES);
    SLYTrace(@"add prop %s to %s? %@", propName, protoName, @(success));

    getSel = sel_registerName(getName);
    getImp = RXEGetterImplementationForPropertyType(property.type);
    success = class_addMethod(class, getSel, getImp, getTypes);
    SLYTrace(@"add meth %s to %s? %@", getName, className, @(success));

    protocol_addMethodDescription(proto, getSel, getTypes, YES, YES);
    SLYTrace(@"add meth %s to %s", getName, protoName);

    rxe_protocol_addExtendedTypesForMethod(proto, getSel, getExtTypes);

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
    SLYTrace(@"add meth %s to %s? %@", setName, className, @(success));

    protocol_addMethodDescription(proto, setSel, setTypes, YES, YES);
    SLYTrace(@"add meth %s to %s", setName, protoName);

    rxe_protocol_addExtendedTypesForMethod(proto, setSel, setExtTypes);
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
