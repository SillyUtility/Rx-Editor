//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/_NSTextFieldPlugin.h>

__attribute__((visibility("hidden")))
@interface _NSTextPlugin : _NSTextFieldPlugin
{
}

- (id)shownValueInObject:(id)arg1;
- (void)showValue:(id)arg1 inObject:(id)arg2;
- (BOOL)acceptsMarker:(id)arg1 binding:(id)arg2 overrideWithPlaceholderIfDefined:(char *)arg3;
- (BOOL)acceptsStyleChanges;
- (BOOL)conditionalBehaviorOffByDefault:(id)arg1;
- (Class)valueClass:(id)arg1 forBinding:(id)arg2;
- (Class)_valueClass:(id)arg1;
- (unsigned long long)allowedValueBindingMask;
- (id)objectMechanismsRequired;

@end

