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
    return [self->_bridgeObj performSelector:_cmd];
}

void setString_Property(RXERuntimeObject *self, SEL _cmd, NSString *str)
{
    SLYTraceCall(@"%@ %@ %@", self, self->_bridgeObj, NSStringFromSelector(_cmd));
    [self->_bridgeObj performSelector:_cmd withObject:str];
}

int getInt_Property(id self, SEL _cmd)
{
    return 0;
}

void setInt_Property_i(id self, SEL _cmd, int i)
{

}

@end
