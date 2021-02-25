//
//  RXERuntimeTypes.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/24/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RXERuntimeMethodDescription;

@interface RXERuntimeClassDescription : NSObject

- initWithClass:(Class)class;

- (void)addMethodDescription:(RXERuntimeMethodDescription *)methDesc;

- (Class)returnClassForSelector:(SEL)sel;

@end

@interface RXERuntimeMethodDescription : NSObject

- initWithSelector:(SEL)sel returnType:(Class)retClass;

@property (readonly) SEL selector;
@property (readonly) Class returnClass;

@end

NS_ASSUME_NONNULL_END
