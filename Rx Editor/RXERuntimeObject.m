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

@implementation RXERuntimeObject {
    id _bridgeObj;
}

- initWithBridgeObject:(id)bridgeObj
{
    if (!(self = [super init]))
        return self;

    _bridgeObj = bridgeObj;

    return self;
}

#ifdef DEBUG
- (NSString *)address
{
    return [NSString stringWithFormat:@"%p", self];
}
#endif

id getObject_Property(id self, SEL _cmd)
{
    return nil;
}

void setObject_Property(id self, SEL _cmd, id obj)
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

int getInt_Property(id self, SEL _cmd)
{
    return 0;
}

void setInt_Property_i(id self, SEL _cmd, int i)
{

}

BOOL getBool_Property(RXERuntimeObject *self, SEL _cmd)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
    NSMethodSignature *sig;
    NSInvocation *inv;
    BOOL ret;

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

@end
