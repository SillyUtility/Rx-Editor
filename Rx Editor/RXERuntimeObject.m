//
//  RXERuntimeObject.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/2/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <SillyLog/SillyLog.h>
#import <ScriptingBridge/ScriptingBridge.h>

#import "RXERuntimeObject.h"
#import "RXERuntimeController.h"
#import "RXERuntimeTypes.h"
#import "RXEUtilities.h"

@implementation RXERuntimeObject {
    id _bridgeObj;
    // TODO: invocation cache
    // TODO: wrapper cache
}

- initWithBridgeObject:(id)bridgeObj
{
    if (!(self = [super init]))
        return self;

    _bridgeObj = bridgeObj;

    return self;
}

#ifdef DEBUG
- (void)dealloc
{
    SLYTraceCall(@"Dealloc runtime obj: %p of type %@", self, self.className);
}

- (NSString *)address
{
    return [NSString stringWithFormat:@"%p", self];
}
#endif

id getObject_Property(RXERuntimeObject *self, SEL _cmd)
{
    return nil;
}

void setObject_Property(RXERuntimeObject *self, SEL _cmd, id obj)
{

}

NSString *getString_Property(RXERuntimeObject *self, SEL _cmd)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    return [self->_bridgeObj performSelector:_cmd];
#   pragma clang diagnostic pop
}

void setString_Property(RXERuntimeObject *self, SEL _cmd, NSString *str)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    [self->_bridgeObj performSelector:_cmd withObject:str];
#   pragma clang diagnostic pop
}

int getInt_Property(RXERuntimeObject *self, SEL _cmd)
{
    return 0;
}

void setInt_Property_i(RXERuntimeObject *self, SEL _cmd, int i)
{

}

long getLong_Property(RXERuntimeObject *self, SEL _cmd)
{
    return 0;
}

void setLong_Property(RXERuntimeObject *self, SEL _cmd, long l)
{

}

long long getLongLong_Property(RXERuntimeObject *self, SEL _cmd)
{
    return 0;
}

void setLongLong_Property(RXERuntimeObject *self, SEL _cmd, long long ll)
{

}

double getDouble_Property(RXERuntimeObject *self, SEL _cmd)
{
    return 0.0;
}

void setDouble_Property(RXERuntimeObject *self, SEL _cmd, double d)
{

}

BOOL getBool_Property(RXERuntimeObject *self, SEL _cmd)
{
    NSMethodSignature *sig;
    NSInvocation *inv;
    BOOL ret;

    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));

    sig = [self methodSignatureForSelector:_cmd];
    inv = [NSInvocation invocationWithMethodSignature:sig];
    inv.selector = _cmd;
    inv.target = self->_bridgeObj;
    [inv invoke];
    [inv getReturnValue:&ret];

    return ret;
}

void setBoll_Property(RXERuntimeObject *self, SEL _cmd, BOOL b)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
}

NSNumber *getBoxedBool_Property(RXERuntimeObject *self, SEL _cmd)
{
    NSMethodSignature *sig;
    NSInvocation *inv;
    BOOL ret;

    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));

    sig = [self methodSignatureForSelector:_cmd];
    inv = [NSInvocation invocationWithMethodSignature:sig];
    inv.selector = _cmd;
    inv.target = self->_bridgeObj;
    [inv invoke];
    [inv getReturnValue:&ret];

    return [NSNumber numberWithBool:ret];
}

void setBoxedBool_Property(RXERuntimeObject *self, SEL _cmd, NSNumber *b)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
}

NSNumber *getBoxedNumber_Property(RXERuntimeObject * self, SEL _cmd)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    return [self->_bridgeObj performSelector:_cmd];
#   pragma clang diagnostic pop
}

void setBoxedNumber_Property(RXERuntimeObject * self, SEL _cmd, NSNumber *n)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    [self->_bridgeObj performSelector:_cmd withObject:n];
#   pragma clang diagnostic pop
}

NSNumber *getBoxedOSType_Property(RXERuntimeObject *self, SEL _cmd)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    return [self->_bridgeObj performSelector:_cmd];
#   pragma clang diagnostic pop
}

void setBoxedOSType_Property(RXERuntimeObject *self, SEL _cmd, NSNumber *type)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    [self->_bridgeObj performSelector:_cmd withObject:type];
#   pragma clang diagnostic pop
}

NSDictionary *getDictionary_Property(RXERuntimeObject *self, SEL _cmd)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    return [self->_bridgeObj performSelector:_cmd];
#   pragma clang diagnostic pop
}

void setDictionary_Property(RXERuntimeObject *self, SEL _cmd, NSDictionary *dict)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    [self->_bridgeObj performSelector:_cmd withObject:dict];
#   pragma clang diagnostic pop
}

NSArray *getArray_Property(RXERuntimeObject *self, SEL _cmd)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    return [self->_bridgeObj performSelector:_cmd];
#   pragma clang diagnostic pop
}

void setArray_Property(RXERuntimeObject *self, SEL _cmd, NSArray *array)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    [self->_bridgeObj performSelector:_cmd withObject:array];
#   pragma clang diagnostic pop
}

NSDate *getDate_Property(RXERuntimeObject *self, SEL _cmd)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    return [self->_bridgeObj performSelector:_cmd];
#   pragma clang diagnostic pop
}

void setDate_Property(RXERuntimeObject *self, SEL _cmd, NSDate *date)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    [self->_bridgeObj performSelector:_cmd withObject:date];
#   pragma clang diagnostic pop
}

CGPoint getPoint_Property(RXERuntimeObject *self, SEL _cmd)
{
    NSMethodSignature *sig;
    NSInvocation *inv;
    CGPoint ret;
    //size_t size;

    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));

    sig = [self methodSignatureForSelector:_cmd];
    // size = [sig methodReturnLength];
    // ret = calloc(1, size);

    inv = [NSInvocation invocationWithMethodSignature:sig];
    inv.selector = _cmd;
    inv.target = self->_bridgeObj;
    [inv invoke];
    [inv getReturnValue:&ret];

    return ret;
}

void setPoint_Property(RXERuntimeObject *self, SEL _cmd, CGPoint p)
{

}

CGRect getRectangle_Property(RXERuntimeObject *self, SEL _cmd)
{
    NSMethodSignature *sig;
    NSInvocation *inv;
    CGRect ret;
    //size_t size;
    
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));

    sig = [self methodSignatureForSelector:_cmd];
    // size = [sig methodReturnLength];
    // ret = calloc(1, size);

    inv = [NSInvocation invocationWithMethodSignature:sig];
    inv.selector = _cmd;
    inv.target = self->_bridgeObj;
    [inv invoke];
    [inv getReturnValue:&ret];

    return ret;
}

void setRectangle_Property(RXERuntimeObject *self, SEL _cmd, CGRect r)
{

}

id getWrappedObject_Property(RXERuntimeObject *self, SEL _cmd)
{
    id bridgeObj;
    RXERuntimeClassDescription *wrapperClassDesription;
    Class wrapperClass;

    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));

#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    // TODO: verify this doesn't leak
    bridgeObj = [self->_bridgeObj performSelector:_cmd];
#   pragma clang diagnostic pop

    // TODO: wrapper cache?

    wrapperClassDesription = [RXERuntimeController
        classDescriptionForClass:self.class
        inContext:JSContext.currentContext
    ];
    wrapperClass = [wrapperClassDesription returnClassForSelector:_cmd];
    SLYTrace(@"DESCRIBE wrapperClass \n%@", RXEDescribeClass(wrapperClass));

    return [[wrapperClass alloc] initWithBridgeObject:bridgeObj];
}

void setWrappedObject_Property(RXERuntimeObject *self, SEL _cmd, id obj)
{

}

id getWrappedEnumerator_Property(id self, SEL _cmd)
{
    return nil;
}

void setWrappedEnumerator_Property(id self, SEL _cmd, id enumerator)
{

}

id getWrappedRecord_Property(id self, SEL _cmd)
{
    return nil;
}

void setWrappedRecord_Property(id self, SEL _cmd, id record)
{

}

@end
