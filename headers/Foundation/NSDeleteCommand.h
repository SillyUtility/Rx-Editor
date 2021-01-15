//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSScriptCommand.h>

@class NSScriptObjectSpecifier;

@interface NSDeleteCommand : NSScriptCommand
{
    NSScriptObjectSpecifier *_keySpecifier;
}

- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)description;
- (id)performDefaultImplementation;
@property(readonly, retain) NSScriptObjectSpecifier *keySpecifier;
- (void)dealloc;
- (void)setReceiversSpecifier:(id)arg1;

@end

