//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/AVAudioPlayerDelegate-Protocol.h>
#import <AppKit/NSSoundEngine-Protocol.h>

@class AVAudioPlayer, NSString;
@protocol NSSoundEngineDelegate;

__attribute__((visibility("hidden")))
@interface NSAVAudioPlayerSoundEngine : NSObject <AVAudioPlayerDelegate, NSSoundEngine>
{
    id <NSSoundEngineDelegate> _delegate;
    AVAudioPlayer *_audioPlayer;
}

- (void).cxx_destruct;
- (void)dealloc;
- (id)initWithDelegate:(id)arg1;
- (void)audioPlayerDidFinishPlaying:(id)arg1 successfully:(BOOL)arg2;
- (void)deviceUIDDidChange;
- (void)channelMappingDidChange;
- (void)volumeDidChange;
- (void)shouldLoopDidChange;
- (void)stop;
- (void)resetPosition;
- (BOOL)resume;
- (BOOL)play;
- (BOOL)pause;
@property(readonly) double duration;
@property double currentTime;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

