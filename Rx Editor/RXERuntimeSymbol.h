//
//  RXERuntimeSymbol.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/19/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXERuntimeSymbol : NSObject

- initWithClass:(Class)class;
- initWithProtocol:(Protocol *)proto;

@property (readonly) BOOL isClass;
@property (readonly) BOOL isProtocol;
@property (readonly) BOOL isRealized;

@property (readonly) Class symbolClass;
@property (readonly) Protocol *symbolProtocol;

@end

NS_ASSUME_NONNULL_END
