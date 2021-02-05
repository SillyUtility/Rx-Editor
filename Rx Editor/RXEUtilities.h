//
//  RXEUtilities.h
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/4/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RXEUtilities : NSObject

@end

NSString *RXEClassNameFromString(NSString *str);
NSString *RXEPropertyNameFromString(NSString *str);
NSString *RXEMethodNameFromString(NSString *str);

NS_ASSUME_NONNULL_END
