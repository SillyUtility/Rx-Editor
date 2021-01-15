//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCoding-Protocol.h>

@class NSStoryboard, NSString;

@interface NSStoryboardSegueTemplate : NSObject <NSCoding>
{
    NSString *_identifier;
    NSString *_segueClassName;
    NSStoryboard *_storyboard;
    id _controller;
    NSString *_destinationControllerIdentifier;
    BOOL _performOnViewLoad;
    NSString *_destinationControllerCreationSelectorName;
}

@property(readonly) NSString *destinationControllerCreationSelectorName; // @synthesize destinationControllerCreationSelectorName=_destinationControllerCreationSelectorName;
@property(readonly) NSString *destinationControllerIdentifier; // @synthesize destinationControllerIdentifier=_destinationControllerIdentifier;
@property BOOL performOnViewLoad; // @synthesize performOnViewLoad=_performOnViewLoad;
@property id controller; // @synthesize controller=_controller;
@property NSStoryboard *storyboard; // @synthesize storyboard=_storyboard;
@property(readonly) NSString *identifier; // @synthesize identifier=_identifier;
- (void)perform:(id)arg1;
- (void)_perform:(id)arg1;
- (id)segueWithDestinationViewController:(id)arg1;
- (CDUnknownBlockType)newDefaultPerformHandlerForSegue:(id)arg1;
- (CDUnknownBlockType)newDefaultPrepareHandlerForSegue:(id)arg1;
- (id)targetController;
- (Class)effectiveSegueClass;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;

@end

