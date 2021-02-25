//
//  RXEScriptClass.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RXEScriptSuite.h"

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptCocoaImp, RXEScriptAccessGroup, RXEScriptType,
    RXEScriptElement, RXEScriptContents, RXEScriptProperty,
    RXEScriptClassCommand, RXEScriptSynonym, RXEScriptAccessor,
    RXEScriptDocumentation, RXEScriptXRef;

@interface RXEScriptClassContent : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *identifier;
@property NSString *hidden;
@property NSString *commentary;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;
@property (readonly) NSArray<RXEScriptElement *> *elements;
@property (readonly) NSArray<RXEScriptContents *> *contents;
@property (readonly) NSArray<RXEScriptProperty *> *properties;
@property (readonly) NSArray<RXEScriptClassCommand *> *classCommands;
@property (readonly) NSArray<RXEScriptSynonym *> *synonyms;
@property (readonly) NSArray<RXEScriptDocumentation *> *docs;
@property (readonly) NSArray<RXEScriptXRef *> *xrefs;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;
- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup;
- (void)addElement:(RXEScriptElement *)element;
- (void)addContents:(RXEScriptContents *)contents;
- (void)addProperty:(RXEScriptProperty *)property;
- (void)addClassCommand:(RXEScriptClassCommand *)classCommand;
- (void)addSynonym:(RXEScriptSynonym *)synonym;
- (void)addDocumentation:(RXEScriptDocumentation *)doc;
- (void)addXRef:(RXEScriptXRef *)xref;

@end

@interface RXEScriptClass : RXEScriptClassContent

@property NSString *name;
@property NSString *code;
@property NSString *plural;
@property NSString *inherits;

@property (readonly) NSArray<RXEScriptType *> *types;

- (void)addType:(RXEScriptType *)type;

@property (readonly) NSString *exportName;

@end

@interface RXEScriptClassExt : RXEScriptClassContent

@property NSString *extends;
@property NSString *title;

@end

@interface RXEScriptElement : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *type;
@property NSString *access;
@property NSString *hidden;
@property NSString *commentary;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;
@property (readonly) NSArray<RXEScriptAccessor *> *accessors;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;
- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup;
- (void)addAccessor:(RXEScriptAccessor *)accessor;

@end

@interface RXEScriptPropBase : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *name;
@property NSString *code;
@property NSString *hidden;
@property NSString *type;
@property NSString *access;
@property NSString *inProperties;
@property NSString *commentary;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;
@property (readonly) NSArray<RXEScriptType *> *types;
@property (readonly) NSArray<RXEScriptSynonym *> *synonyms;
@property (readonly) NSArray<RXEScriptDocumentation *> *docs;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;
- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup;
- (void)addType:(RXEScriptType *)type;
- (void)addSynonym:(RXEScriptSynonym *)synonym;
- (void)addDocumentation:(RXEScriptDocumentation *)doc;

@property (readonly) NSString *exportTypeName;

@property (readonly) BOOL isReadOnly;

@end

@interface RXEScriptContents : RXEScriptPropBase
@end

@interface RXEScriptProperty : RXEScriptPropBase
@end

// aka responds-to
@interface RXEScriptClassCommand : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *command;
@property NSString *hidden;
@property NSString *name;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;
- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup;

@end

@interface RXEScriptAccessor : RXEScriptBaseObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *style;

@end

NS_ASSUME_NONNULL_END
