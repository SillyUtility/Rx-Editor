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
#import "RXEObjCRuntime.h"
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
    License: BSD 2-Clause

    JavaScriptCore derivative
*/

#if 0
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
#endif

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

NSString *RXEExportsProtocolNameFromClassName(NSString *className)
{
    return [className stringByAppendingString:@"Exports"];
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

Class RXERuntimeMakeClass(NSString *name)
{
    Class NewClass;
    Protocol *ExportProtocol;
    const char *className;

    className = name.UTF8String;
    NewClass = objc_allocateClassPair(
        RXERuntimeObject.class,
        className,
        0
    );

    ExportProtocol = RXERuntimeMakeExportsProtocol(name);
    class_addProtocol(NewClass, ExportProtocol);

    return NewClass;
}

Protocol *RXERuntimeMakeExportsProtocol(NSString *className)
{
    Protocol *ExportsProtocol;
    Protocol *JSExportProtocol;
    const char *protocolName;

    protocolName = RXEExportsProtocolNameFromClassName(className).UTF8String;
    ExportsProtocol = objc_allocateProtocol(protocolName);

    JSExportProtocol = objc_getProtocol("JSExport");
    protocol_addProtocol(ExportsProtocol, JSExportProtocol);

    return ExportsProtocol;
}

Protocol *RXEClassFindExportsProtocol(Class class)
{
    Protocol *ExportsProtocol;
    const char *protocolName;
    Protocol * __unsafe_unretained _Nonnull *protoList;
    unsigned int outc;

    protocolName = [NSString stringWithFormat:@"%sExports",
        class_getName(class)
    ].UTF8String;

    /* NOTE: objc_getProtocol will fail to find protocols that are
     * under construction */

    // ExportsProtocol = objc_getProtocol(protocolName);

    // perform a linear search on the class' protocol list
    protoList = class_copyProtocolList(class, &outc);
    for (unsigned int i = 0; i < outc; i++) {
        const char *name = protocol_getName(protoList[i]);
        if (strcmp(name, protocolName) == 0) {
            ExportsProtocol = protoList[i];
            break;
        }
    }

    return ExportsProtocol;
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

    if (!RXEBuiltInScriptType(property.type))
        return; // skip non-built-in types for now

    // if (RXESkipScriptType_To_Be_Removed(property.type))
    //     return;

    proto = RXEClassFindExportsProtocol(class);

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
    SLYTrace(@"\tattrs %s", copyPropertyAttributeString(pattrs, outc));

    protocol_addProperty(proto, propName,
        (const objc_property_attribute_t *)pattrs, outc, YES, YES);
    SLYTrace(@"add prop %s to %s? %@", propName, protoName, @(success));
    SLYTrace(@"\tattrs %s", copyPropertyAttributeString(pattrs, outc));

    getSel = sel_registerName(getName);
    getImp = RXEGetterImplementationForPropertyType(property.type);
    success = class_addMethod(class, getSel, getImp, getTypes);
    SLYTrace(@"add meth %s to %s? %@", getName, className, @(success));
    SLYTrace(@"\ttypes %s", getTypes);

    protocol_addMethodDescription(proto, getSel, getTypes, YES, YES);
    SLYTrace(@"add meth %s to %s", getName, protoName);
    SLYTrace(@"\ttypes %s", getTypes);

    rxe_protocol_unfix(proto);

    rxe_protocol_addExtendedTypesForMethod(proto, getSel, getExtTypes);
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
    SLYTrace(@"add meth %s to %s? %@", setName, className, @(success));

    protocol_addMethodDescription(proto, setSel, setTypes, YES, YES);
    SLYTrace(@"add meth %s to %s", setName, protoName);

    rxe_protocol_unfix(proto);

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
