//
//  RXEScriptSuite.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptClass, RXEScriptClassExt, RXEScriptCommand,
    RXEScriptEnumeration, RXEScriptEvent, RXEScriptRecordType,
    RXEScriptValueType, RXEScriptCocoaImp, RXEScriptAccessGroup,
    RXEScriptDocumentation;

@interface RXEScriptBaseObject : NSObject
@end

@interface RXEScriptSuite : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property (readonly) NSString *name;
@property (readonly) NSString *code;
@property (readonly) NSString *commentary;
@property (readonly) NSString *hidden;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;
@property (readonly) NSArray<RXEScriptClass *> *classes;
@property (readonly) NSArray<RXEScriptClassExt *> *classExts;
@property (readonly) NSArray<RXEScriptCommand *> *commands;
@property (readonly) NSArray<RXEScriptEnumeration *> *enumerations;
@property (readonly) NSArray<RXEScriptEvent *> *events;
@property (readonly) NSArray<RXEScriptRecordType *> *recordTypes;
@property (readonly) NSArray<RXEScriptValueType *> *valueTypes;
@property (readonly) NSArray<RXEScriptDocumentation *> *docs;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;
- (void)addAccessGroup:(RXEScriptAccessGroup *)accessGroup;
- (void)addClass:(RXEScriptClass *)klass;
- (void)addClassExt:(RXEScriptClassExt *)classExt;
- (void)addCommand:(RXEScriptCommand *)command;
- (void)addEnumeration:(RXEScriptEnumeration *)enumeration;
- (void)addEvent:(RXEScriptEvent *)event;
- (void)addRecordType:(RXEScriptRecordType *)recordType;
- (void)addValueType:(RXEScriptValueType *)valueType;
- (void)addDocumentation:(RXEScriptDocumentation *)doc;

@end

@interface RXEScriptDocumentation : RXEScriptBaseObject

- init;

@property NSArray<NSString *> *htmlFragments;

- (void)addHTML:(NSString *)html;

@end

@interface RXEScriptXRef : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *target;
@property NSString *hidden;

@end

@interface RXEScriptAccessGroup : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *identifier;
@property NSString *access;

@end

@interface RXEScriptCocoaImp : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *name;
@property NSString *cocoaClass;
@property NSString *key;
@property NSString *method;
@property NSString *insertAtBeginning;
@property NSString *booleanValue;
@property NSString *integerValue;
@property NSString *stringValue;

@end

@interface RXEScriptSynonym : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *name;
@property NSString *code;
@property NSString *hidden;

@property (readonly) RXEScriptCocoaImp *cocoaImp;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;

@end

NS_ASSUME_NONNULL_END
