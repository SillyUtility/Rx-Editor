//
//  main.m
//  ObjCRuntimeFun
//
//  Created by Eddie Hillenbrand on 2/3/21.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#define BEGIN_AUTORELEASE @autoreleasepool {
#define END_AUTORELEASE }

@interface C1 : NSObject
@property int prop1;
@end

@implementation C1
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

void setInt_Property(id self, SEL _cmd, int i)
{

}

int main(int argc, const char * argv[])
{
    BEGIN_AUTORELEASE

    BOOL success;

    Class c1 = objc_getClass("C1");
    NSLog(@"c1 %p", c1);

    const objc_property_attribute_t pattrs[] = {
        { "T", @encode(int) },
        { "V", "_prop2" },
    };
    success = class_addProperty(c1, "prop2", pattrs, 1);
    NSLog(@"addProp success %@", @(success));

    SEL s1 = sel_registerName("prop2");
    IMP m1 = (IMP)getInt_Property;
    success = class_addMethod(c1, s1, m1, "i@:");
    NSLog(@"addMethod success %@", @(success));

    SEL s2 = sel_registerName("setProp2:");
    IMP m2 = (IMP)setInt_Property;
    success = class_addMethod(c1, s2, m2, "v@:i");
    NSLog(@"addMethod success %@", @(success));

    objc_property_t *c1plist;
    unsigned int outc;
    c1plist = class_copyPropertyList(c1, &outc);

    for (int i = 0; i < outc; i++) {
        const char *pname = property_getName(c1plist[i]);
        const char *pattr = property_getAttributes(c1plist[i]);
        NSLog(@"%s %s", pname, pattr);
    }

    C1 *o1 = C1.new;
    NSLog(@"%@", [o1 valueForKey:@"prop1"]);
    NSLog(@"%@", [o1 valueForKey:@"prop2"]);

    END_AUTORELEASE

    return 0;
}
