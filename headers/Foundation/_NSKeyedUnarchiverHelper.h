//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSError, NSMutableArray;

__attribute__((visibility("hidden")))
@interface _NSKeyedUnarchiverHelper : NSObject
{
    NSArray *_white;
    unsigned int _lastRef;
    NSMutableArray *_allowedClasses;
    NSError *_decodeError;
}

@property(copy) NSError *decodeError; // @synthesize decodeError=_decodeError;
- (BOOL)classNameAllowed:(Class)arg1;
- (void)setAllowedClassNames:(id)arg1;
- (id)allowedClassNames;
- (void)dealloc;
- (id)init;

@end

