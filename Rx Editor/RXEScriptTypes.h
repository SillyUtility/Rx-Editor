//
//  RXEScriptTypes.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/22/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptSynonym, RXEScriptProperty, RXEScriptEnumerator,
    RXEScriptDocumentation, RXEScriptXRef;

@interface RXEScriptType : NSObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property NSString *type;
@property NSString *list;
@property NSString *hidden;

@property NSArray<RXEScriptType *> *types;

- (void)addType:(RXEScriptType *)type;

@end

@interface RXEScriptValueType : NSObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property (readonly) NSString *name;
@property (readonly) NSString *identifier;
@property (readonly) NSString *code;
@property (readonly) NSString *hidden;
@property (readonly) NSString *plural;
@property (readonly) NSString *commentary;

@property (readonly) NSArray<RXEScriptSynonym *> *synonyms;
@property (readonly) NSArray<RXEScriptDocumentation *> *docs;
@property (readonly) NSArray<RXEScriptXRef *> *xrefs;

- (void)addSynonym:(RXEScriptSynonym *)synonym;
- (void)addDocumentation:(RXEScriptDocumentation *)doc;
- (void)addXRef:(RXEScriptXRef *)xref;

@end


@interface RXEScriptRecordType : NSObject
@property NSString *name;
@property NSString *identifier;
@property NSString *code;
@property NSString *hidden;
@property NSString *plural;
@property NSString *commentary;
@end


@interface RXEScriptEnumeration : NSObject
@property NSString *name;
@property NSString *identifier;
@property NSString *code;
@property NSString *hidden;
@property NSString *commentary;
@property NSString *inLine;
@end


@interface RXEScriptEnumerator : NSObject
@property NSString *name;
@property NSString *code;
@property NSString *hidden;
@property NSString *commentary;
@end


NS_ASSUME_NONNULL_END
