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

void RXERuntimeClassExportProperty(Class class, RXEScriptProperty *property)
{
    BOOL success;
    Protocol *proto;
    SEL getSel, setSel;
    IMP getImp, setImp;
    const char *propName, *propVar,
        *getName, *setName, *getType,
        *setType, *className, *protoName;

    proto = RXEGetExportProtocolForClass(class);

    className = class_getName(class);
    protoName = protocol_getName(proto);

    propName = property.name.UTF8String;
    propVar = [NSString stringWithFormat:@"_%@", property.name].UTF8String;
    getName = strdup(propName);
    setName = [NSString stringWithFormat:@"set%@:", property.name.capitalizedString].UTF8String;
    getType = "@@:";
    setType = "v@:@";

    const objc_property_attribute_t pattrs[] = {
        { "T", @encode(NSString *) },
        { "V", propVar },
    };
    success = class_addProperty(class, propName, pattrs, 2);
    SLYTrace(@"add prop %s to %s? %@", propName, className, @(success));

    protocol_addProperty(proto, propName, pattrs, 2, YES, YES);
    SLYTrace(@"add prop %s to %s? %@", propName, protoName, @(success));

    getSel = sel_registerName(getName);
    getImp = (IMP)getString_Property;
    success = class_addMethod(class, getSel, getImp, getType);
    SLYTrace(@"add meth %s to %s? %@", getName, className, @(success));

    setSel = sel_registerName(setName);
    setImp = (IMP)setString_Property;
    success = class_addMethod(class, setSel, setImp, setType);
    SLYTrace(@"add meth %s to %s? %@", setName, className, @(success));
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
    const char *name;
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
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\tr meth %s %s\n",
            sel_getName(methodlist[i].name),
            methodlist[i].types
        ];

    methodlist = protocol_copyMethodDescriptionList(proto, NO, YES, &outc);
    for (i = 0; i < outc; i++)
        [description appendFormat:@"\to meth %s %s\n",
            sel_getName(methodlist[i].name),
            methodlist[i].types
        ];

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
