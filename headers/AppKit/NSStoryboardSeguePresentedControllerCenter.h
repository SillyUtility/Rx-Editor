//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMapTable;

__attribute__((visibility("hidden")))
@interface NSStoryboardSeguePresentedControllerCenter : NSObject
{
    NSMapTable *_registeredControllers;
}

+ (id)defaultCenter;
@property(retain) NSMapTable *registeredControllers; // @synthesize registeredControllers=_registeredControllers;
- (id)controllerWithIdentifier:(id)arg1;
- (void)unregisterControllerWithOptions:(id)arg1;
- (void)registerController:(id)arg1 withOptions:(id)arg2;
- (void)dealloc;
- (id)init;

@end

