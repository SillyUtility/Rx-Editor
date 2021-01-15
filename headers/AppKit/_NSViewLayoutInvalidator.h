//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSSet, NSView;

__attribute__((visibility("hidden")))
@interface _NSViewLayoutInvalidator : NSObject
{
    NSView *_observedView;
    NSSet *_observedKeyPaths;
    BOOL _handleAlignmentRectInsets;
}

+ (id)newInvalidatorForView:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
@property NSView *observedView;
- (id)keyPathsForPropertiesObservedDirectly;
- (id)autorelease;
- (void)dealloc;

@end

