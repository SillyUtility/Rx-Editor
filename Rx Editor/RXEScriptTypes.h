//
//  RXEScriptTypes.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/22/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXEScriptType : NSObject
@property NSString *type;
@property NSString *list;
@property NSString *hidden;
@end

@interface RXEScriptValueType : NSObject
@property NSString *name;
@property NSString *valueTypeID;
@property NSString *code;
@property NSString *hidden;
@property NSString *plural;
@property NSString *valueTypeDescription;
@end


@interface RXEScriptRecordType : NSObject
@property NSString *name;
@property NSString *recordTypeID;
@property NSString *code;
@property NSString *hidden;
@property NSString *plural;
@property NSString *recordTypeDescription;
@end


@interface RXEScriptEnumeration : NSObject
@property NSString *name;
@property NSString *enumerationID;
@property NSString *code;
@property NSString *hidden;
@property NSString *enumerationDescription;
@property NSString *inLine;
@end


@interface RXEScriptEnumerator : NSObject
@property NSString *name;
@property NSString *code;
@property NSString *hidden;
@property NSString *enumeratorDescription;
@end


NS_ASSUME_NONNULL_END
