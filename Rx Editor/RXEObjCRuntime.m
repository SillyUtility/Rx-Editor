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

/*
    License: APSL

    objc derivative
*/

//
//  RXEObjCRuntime.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/17/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <SillyLog/SillyLog.h>
#import "RXEObjCRuntime.h"

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


static uint32_t fixed_up_method_list = 3;
static uint32_t fixed_up_protocol = (1<<31) | (1<<30);

void rxe_method_list_unfix(method_list_t *mlist)
{
    if (mlist)
        mlist->entsize_NEVER_USE &= ~fixed_up_method_list;
}

void rxe_protocol_unfix(Protocol *proto)
{
    protocol_t *p;

    p = newprotocol(proto);
    rxe_method_list_unfix(p->instanceMethods);
    rxe_method_list_unfix(p->classMethods);
    rxe_method_list_unfix(p->optionalInstanceMethods);
    rxe_method_list_unfix(p->optionalClassMethods);

    p->flags &= ~fixed_up_protocol;
}

void rxe_protocol_addExtendedTypesForMethod(
    Protocol *proto, SEL sel, const char *extTypes)
{
    protocol_t *p;
    uint32_t midx, mcount, newcount;
    BOOL required = YES, instance = YES;

    p = newprotocol(proto);
    midx = rxe_protocol_getExtendedTypeIndexForMethod(p, sel, required, instance);
    mcount = rxe_protocol_method_count(p);
    newcount = midx + 1;

    const char **tlist = p->_extendedMethodTypes;
    if (tlist) {
        if (newcount >= mcount)
            tlist = realloc(tlist, newcount * sizeof(char *));
    } else {
        tlist = calloc(mcount, sizeof(char *));
    }
    tlist[midx] = strdup(extTypes);
    p->_extendedMethodTypes = tlist;
}

const char *copyPropertyAttributeString(
    const objc_property_attribute_t *attrs,
    unsigned int count)
{
    char *result;
    unsigned int i;
    if (count == 0) return strdup("");

#ifndef NDEBUG
    // debug build: sanitize input
    for (i = 0; i < count; i++) {
        assert(attrs[i].name);
        assert(strlen(attrs[i].name) > 0);
        assert(! strchr(attrs[i].name, ','));
        assert(! strchr(attrs[i].name, '"'));
        if (attrs[i].value) assert(! strchr(attrs[i].value, ','));
    }
#endif

    size_t len = 0;
    for (i = 0; i < count; i++) {
        if (attrs[i].value) {
            size_t namelen = strlen(attrs[i].name);
            if (namelen > 1) namelen += 2;  // long names get quoted
            len += namelen + strlen(attrs[i].value) + 1;
        }
    }

    result = (char *)malloc(len + 1);
    char *s = result;
    for (i = 0; i < count; i++) {
        if (attrs[i].value) {
            size_t namelen = strlen(attrs[i].name);
            if (namelen > 1) {
                s += sprintf(s, "\"%s\"%s,", attrs[i].name, attrs[i].value);
            } else {
                s += sprintf(s, "%s%s,", attrs[i].name, attrs[i].value);
            }
        }
    }

    // remove trailing ',' if any
    if (s > result) s[-1] = '\0';

    return result;
}
