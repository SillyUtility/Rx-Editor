//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSKeyGetBinding.h>

__attribute__((visibility("hidden")))
@interface _NSSelectorGetBinding : NSKeyGetBinding
{
    SEL getSel;
    CDUnknownFunctionPointerType getMethod;
    CDUnknownFunctionPointerType get;
}

- (id)getValueFromObject:(id)arg1;
- (id)initWithFunc:(CDUnknownFunctionPointerType)arg1 forImp:(CDUnknownFunctionPointerType)arg2 selector:(SEL)arg3;

@end

