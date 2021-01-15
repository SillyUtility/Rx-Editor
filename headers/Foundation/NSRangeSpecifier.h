//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSScriptObjectSpecifier.h>

@interface NSRangeSpecifier : NSScriptObjectSpecifier
{
    NSScriptObjectSpecifier *_startSpec;
    NSScriptObjectSpecifier *_endSpec;
}

- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (BOOL)_putKeyFormAndDataInRecord:(id)arg1;
- (id)_simpleDescription;
- (BOOL)_specifiesSingleIndexedObjectPerContainer;
- (id)_specifiedIndexesOfObjectsInContainer:(id)arg1;
@property(retain) NSScriptObjectSpecifier *endSpecifier;
@property(retain) NSScriptObjectSpecifier *startSpecifier;
- (void)dealloc;
- (id)_initFromRecord:(id)arg1;
- (id)initWithContainerClassDescription:(id)arg1 containerSpecifier:(id)arg2 key:(id)arg3 startSpecifier:(id)arg4 endSpecifier:(id)arg5;
- (id)initWithContainerClassDescription:(id)arg1 containerSpecifier:(id)arg2 key:(id)arg3;

@end

