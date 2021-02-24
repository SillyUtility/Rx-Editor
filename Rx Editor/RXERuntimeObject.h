//
//  RXERuntimeObject.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/2/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RXERuntimeObjectExports <JSExport>
#ifdef DEBUG
@property (readonly) NSString *address;
#endif
@end

@interface RXERuntimeObject : NSObject <RXERuntimeObjectExports>
- initWithBridgeObject:(id)bridgeObj;

#ifdef DEBUG
@property (readonly) NSString *address;
#endif

id getObject_Property(id self, SEL _cmd);
void setObject_Property(id self, SEL _cmd, id obj);

NSString *getString_Property(id self, SEL _cmd);
void setString_Property(id self, SEL _cmd, NSString *str);

int getInt_Property(id self, SEL _cmd);
void setInt_Property(id self, SEL _cmd, int i);

long getLong_Property(id self, SEL _cmd);
void setLong_Property(id self, SEL _cmd, long l);

long long getLongLong_Property(id self, SEL _cmd);
void setLongLong_Property(id self, SEL _cmd, long long ll);

double getDouble_Property(id self, SEL _cmd);
void setDouble_Property(id self, SEL _cmd, double d);

BOOL getBool_Property(id self, SEL _cmd);
void setBoll_Property(id self, SEL _cmd, BOOL b);

NSNumber *getBoxedBool_Property(id self, SEL _cmd);
void setBoxedBool_Property(id self, SEL _cmd, NSNumber *b);

NSNumber *getBoxedNumber_Property(id self, SEL _cmd);
void setBoxedNumber_Property(id self, SEL _cmd, NSNumber *n);

NSNumber *getBoxedOSType_Property(id self, SEL _cmd);
void setBoxedOSType_Property(id self, SEL _cmd, NSNumber *type);

NSDictionary *getDictionary_Property(id self, SEL _cmd);
void setDictionary_Property(id self, SEL _cmd, NSDictionary *dict);

NSArray *getArray_Property(id self, SEL _cmd);
void setArray_Property(id self, SEL _cmd, NSArray *array);

NSDate *getDate_Property(id self, SEL _cmd);
void setDate_Property(id self, SEL _cmd, NSDate *date);

CGPoint getPoint_Property(id self, SEL _cmd);
void setPoint_Property(id self, SEL _cmd, CGPoint p);

CGRect getRectangle_Property(id self, SEL _cmd);
void setRectangle_Property(id self, SEL _cmd, CGRect r);

@end

NS_ASSUME_NONNULL_END
