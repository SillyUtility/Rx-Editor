//
//  NSMutableArray+Additions.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/1/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableArray<ObjectType> (Additions)
- (void)push:(ObjectType)anObject;
- (ObjectType)pop;
- (ObjectType)ancestor;
@end

NS_ASSUME_NONNULL_END
