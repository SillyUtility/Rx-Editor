/*
 * Copyright (c) 1999-2007 Apple Inc.  All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

//
//  RXEObjCRuntime.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/17/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <objc/runtime.h>

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

void rxe_protocol_unfix(Protocol *proto);

void rxe_protocol_addExtendedTypesForMethod(
    Protocol *proto, SEL sel, const char *extTypes);

const char *copyPropertyAttributeString(
    const objc_property_attribute_t *attrs,
    unsigned int count);
