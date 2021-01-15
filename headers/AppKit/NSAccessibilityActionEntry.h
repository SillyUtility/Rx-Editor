//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface NSAccessibilityActionEntry : NSObject
{
    NSString *_action;
    NSString *_accessibilityDescription;
    CDUnknownBlockType _handler;
}

+ (id)entryWithName:(id)arg1 description:(id)arg2 handler:(CDUnknownBlockType)arg3;
@property(readonly, copy) NSString *accessibilityDescription; // @synthesize accessibilityDescription=_accessibilityDescription;
@property(readonly, copy) CDUnknownBlockType handler; // @synthesize handler=_handler;
@property(readonly, copy) NSString *action; // @synthesize action=_action;
- (void)dealloc;
- (id)initWithName:(id)arg1 description:(id)arg2 handler:(CDUnknownBlockType)arg3;

@end

