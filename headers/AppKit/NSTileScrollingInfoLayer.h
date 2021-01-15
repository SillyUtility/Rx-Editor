//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <QuartzCore/CALayer.h>

#import <AppKit/CALayerDelegate-Protocol.h>

@class NSMutableDictionary, NSString, _NSTiledLayer;

__attribute__((visibility("hidden")))
@interface NSTileScrollingInfoLayer : CALayer <CALayerDelegate>
{
    _NSTiledLayer *_tileLayer;
    NSMutableDictionary *_tiles;
    CALayer *_coverageRectLayer;
    CALayer *_activeRectLayer;
}

@property _NSTiledLayer *tileLayer; // @synthesize tileLayer=_tileLayer;
- (void)layoutSublayers;
- (void)_updateTileRepresentation;
- (id)actionForLayer:(id)arg1 forKey:(id)arg2;
- (void)display;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

