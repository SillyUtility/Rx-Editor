//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSDictionary, NSMapTable, _NSQuickActionPresentation;

@interface _NSQuickActionConfiguration : NSObject
{
    _NSQuickActionPresentation *_presentation;
    NSDictionary *_indexByIdentifier;
    NSMapTable *_activePreferences;
}

- (void).cxx_destruct;
- (void)save;
- (void)setActive:(BOOL)arg1 forQuickAction:(id)arg2;
- (void)setOrderedQuickActions:(id)arg1;
- (id)init;
- (id)initWithPresentation:(id)arg1;

@end

