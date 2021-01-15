//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSAnimation.h>

@class _NSFullScreenSpace;

__attribute__((visibility("hidden")))
@interface _NSFullScreenSpaceMenuRevealAnimation : NSAnimation
{
    float _startingReveal;
    float _endingReveal;
    double _serverStartTime;
    _NSFullScreenSpace *_siblingSpace;
}

@property(retain, nonatomic) _NSFullScreenSpace *siblingSpace; // @synthesize siblingSpace=_siblingSpace;
@property(nonatomic) double serverStartTime; // @synthesize serverStartTime=_serverStartTime;
@property(nonatomic) float endingReveal; // @synthesize endingReveal=_endingReveal;
@property(nonatomic) float startingReveal; // @synthesize startingReveal=_startingReveal;
- (void)setCurrentProgress:(float)arg1;
- (void)dealloc;

@end

