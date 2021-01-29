//
//  RXEScriptClass.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptCocoaImp, RXEScriptAccessGroup, RXEScriptType,
    RXEScriptElement, RXEScriptProperty, RXEScriptClassCommand,
    RXEScriptSynonym, RXEScriptAccessor, RXEScriptDocumentation,
    RXEScriptXRef;

@interface RXEScriptClassContent : NSObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *identifier;
@property NSString *hidden;
@property NSString *commentary;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;
@property (readonly) NSArray<RXEScriptElement *> *elements;
@property (readonly) NSArray<RXEScriptProperty *> *properties;
@property (readonly) NSArray<RXEScriptClassCommand *> *classCommands;
@property (readonly) NSArray<RXEScriptSynonym *> *synonyms;
@property (readonly) NSArray<RXEScriptDocumentation *> *docs;
@property (readonly) NSArray<RXEScriptXRef *> *xrefs;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;
- (void)addAccessGroups:(RXEScriptAccessGroup *)accessGroup;
- (void)addElement:(RXEScriptElement *)elements;
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

@end

@interface RXEScriptClassExt : RXEScriptClassContent

@property NSString *extends;
@property NSString *title;

@end

@interface RXEScriptElement : NSObject

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

@interface RXEScriptProperty : NSObject
@property NSString *name;
@property NSString *code;
@property NSString *hidden;
@property NSString *type;
@property NSString *access;
@property NSString *inProperties;
@property NSString *commentary;
@end

// aka responds-to
@interface RXEScriptClassCommand : NSObject
@property NSString *command;
@property NSString *hidden;
@property NSString *name;
@end

@interface RXEScriptAccessor : NSObject
@property NSString *style;
@end

NS_ASSUME_NONNULL_END
