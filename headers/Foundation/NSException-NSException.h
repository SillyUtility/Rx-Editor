//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSException.h>

@interface NSException (NSException)
+ (BOOL)supportsSecureCoding;
+ (id)validationExceptionWithFormat:(id)arg1;
+ (id)aggregateExceptionWithExceptions:(id)arg1;
- (id)debugDescription;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)exceptionRememberingObject:(id)arg1 key:(id)arg2;
- (id)exceptionAddingEntriesToUserInfo:(id)arg1;
- (id)replacementObjectForPortCoder:(id)arg1;
@end

