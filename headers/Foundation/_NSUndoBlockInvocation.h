//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/_NSUndoObject.h>

__attribute__((visibility("hidden")))
@interface _NSUndoBlockInvocation : _NSUndoObject
{
    CDUnknownBlockType _handler;
}

- (void)invoke;
- (void)dealloc;
- (id)initWithTarget:(id)arg1 handler:(CDUnknownBlockType)arg2;

@end

