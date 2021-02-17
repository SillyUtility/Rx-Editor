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

BOOL getBool_Property(id self, SEL _cmd);
void setBoll_Property(id self, SEL _cmd, BOOL b);

@end

NS_ASSUME_NONNULL_END
