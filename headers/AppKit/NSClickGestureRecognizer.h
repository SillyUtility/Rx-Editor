//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSGestureRecognizer.h>

#import <AppKit/NSCoding-Protocol.h>

@class NSMutableArray;

@interface NSClickGestureRecognizer : NSGestureRecognizer <NSCoding>
{
    long long _flags;
    struct CGPoint _location;
    unsigned long long _buttonMask;
    long long _numberOfClicksRequired;
    long long _currentButtonCount;
    long long _activeButtonCount;
    long long _currentClickCount;
    double _allowableMovement;
    long long _behavior;
    long long _stage;
    double _pressure;
    double _stageTransition;
    long long _numberOfTouchesRequired;
    long long _activeTouchCount;
    NSMutableArray *_trackingTouchIdentities;
}

@property long long numberOfTouchesRequired; // @synthesize numberOfTouchesRequired=_numberOfTouchesRequired;
@property long long numberOfClicksRequired; // @synthesize numberOfClicksRequired=_numberOfClicksRequired;
- (BOOL)canPreventGestureRecognizer:(id)arg1;
- (void)touchesCancelledWithEvent:(id)arg1;
- (void)touchesEndedWithEvent:(id)arg1;
- (void)touchesMovedWithEvent:(id)arg1;
- (void)touchesBeganWithEvent:(id)arg1;
- (void)pressureChangeWithEvent:(id)arg1;
- (void)otherMouseUp:(id)arg1;
- (void)otherMouseDragged:(id)arg1;
- (void)otherMouseDown:(id)arg1;
- (void)rightMouseUp:(id)arg1;
- (void)rightMouseDragged:(id)arg1;
- (void)rightMouseDown:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (void)mouseDown:(id)arg1;
- (id)_desiredPressureBehavior;
- (void)_failRecognition;
- (void)_beginTouchInteraction;
- (void)_beginMouseInteraction;
- (void)tooSlow:(id)arg1;
- (void)startClickTimer:(double)arg1;
- (void)clearClickTimer;
- (void)reset;
- (struct CGPoint)locationInView:(id)arg1;
@property unsigned long long buttonMask;
- (void)_appendSubclassDescription:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithTarget:(id)arg1 action:(SEL)arg2;
- (void)dealloc;
- (id)_descriptionForTouchBarLogging;
@property(readonly) double stageTransition;
@property(readonly) double pressure;
@property(readonly) long long stage;
@property long long behavior;
@property double allowableMovement;
- (void)_setHasCustomAllowableMovement:(BOOL)arg1;
- (BOOL)_hasCustomAllowableMovement;

@end

