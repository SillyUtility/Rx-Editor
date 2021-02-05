//
//  RXERuntimeObject.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/2/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import "RXERuntimeObject.h"

@implementation RXERuntimeObject {
    id _bridgeObj;
}

@end

id getObject_Property(id self, SEL _cmd)
{
    return nil;
}

void setObject_Property(id self, SEL _cmd, id obj)
{

}

int getInt_Property(id self, SEL _cmd)
{
    return 0;
}

void setInt_Property_i(id self, SEL _cmd, int i)
{

}
