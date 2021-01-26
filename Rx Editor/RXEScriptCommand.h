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

@interface RXEScriptCommand : NSObject

- initWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@property (readonly) NSString *name;
@property (readonly) NSString *commandID;
@property (readonly) NSString *code;
@property (readonly) NSString *commandDescription;
@property (readonly) NSString *hidden;

@property (readonly) RXEScriptCocoaImp *cocoaImp;
@property (readonly) NSArray<RXEScriptAccessGroup *> *accessGroups;

// I think synonym, direct-parameter, parameter, and result are pairs.
// Each can have a documentation element imediately following it.

@end

@interface RXEScriptEvent : NSObject
@end

@interface RXEScriptDirectParameter : NSObject
@end

@interface RXEScriptParameter : NSObject
@end

@interface RXEScriptResult : NSObject
@end

NS_ASSUME_NONNULL_END
