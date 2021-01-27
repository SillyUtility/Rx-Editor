//
//  RXEScriptCommand.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/15/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RXEScriptCocoaImp, RXEScriptAccessGroup, RXEScriptSynonym,
    RXEScriptDocumentation, RXEScriptDirectParameter,
    RXEScriptParameter, RXEScriptResult, RXEScriptXRef;

@interface RXEScriptVerb : NSObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property (readonly) NSString *name;
@property (readonly) NSString *commandID;
@property (readonly) NSString *code;
@property (readonly) NSString *commandDescription;
@property (readonly) NSString *hidden;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptSynonym *> *synonyms;
@property (readonly) RXEScriptDirectParameter *directParameter;
@property (readonly) NSArray<RXEScriptParameter *> *parameters;
@property (readonly) RXEScriptResult *result;
@property (readonly) NSArray<RXEScriptXRef *> *xrefs;
@property (readonly) NSArray<RXEScriptDocumentation *> *docs;

- (void)addCocoaImp:(RXEScriptCocoaImp *)cocoaImp;
- (void)addSynonym:(RXEScriptSynonym *)synonym;
- (void)addDirectParameter:(RXEScriptDirectParameter *)directParameter;
- (void)addParameter:(RXEScriptParameter *)parameter;
- (void)addResult:(RXEScriptResult *)result;
- (void)addXRef:(RXEScriptXRef *)xref;
- (void)addDocumentation:(RXEScriptDocumentation *)doc;

@end

@interface RXEScriptCommand : RXEScriptVerb

@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;

- (void)addAccessGroup:(RXEScriptAccessGroup *)accessGroup;

@end

@interface RXEScriptEvent : RXEScriptVerb
@end

@interface RXEScriptDirectParameter : NSObject
@end

@interface RXEScriptParameter : NSObject
@end

@interface RXEScriptResult : NSObject
@end

NS_ASSUME_NONNULL_END
