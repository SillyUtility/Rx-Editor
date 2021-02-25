//
//  RXERuntimeTypes.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/24/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXERuntimeClassDescription : NSObject
- (Class)returnClassForSelector:(SEL)sel;
@end

@interface RXERuntimeMethodDescription : NSObject
@property (readonly) Class returnClass;
@end

NS_ASSUME_NONNULL_END
