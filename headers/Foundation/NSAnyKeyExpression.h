//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSExpression.h>

__attribute__((visibility("hidden")))
@interface NSAnyKeyExpression : NSExpression
{
}

+ (BOOL)_allowsEvaluation;
+ (BOOL)supportsSecureCoding;
+ (id)defaultInstance;
+ (id)allocWithZone:(struct _NSZone *)arg1;
+ (void)initialize;
- (id)expressionValueWithObject:(id)arg1 context:(id)arg2;
- (id)predicateFormat;
- (id)init;
- (id)_initPrivate;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)autorelease;
- (BOOL)_tryRetain;
- (BOOL)_isDeallocating;
- (oneway void)release;
- (unsigned long long)retainCount;
- (id)retain;

@end

