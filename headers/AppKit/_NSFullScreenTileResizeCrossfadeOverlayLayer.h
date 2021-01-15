//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <QuartzCore/CALayer.h>

@class _NSFullScreenTileResizeCrossfadeOverlayWindow;

__attribute__((visibility("hidden")))
@interface _NSFullScreenTileResizeCrossfadeOverlayLayer : CALayer
{
    unsigned long long _tileID;
    unsigned long long _parentSpaceID;
    _NSFullScreenTileResizeCrossfadeOverlayWindow *_window;
    BOOL _active;
    CALayer *_windowContentLayer;
    BOOL _includeBorder;
    struct CGRect _tileFrame;
}

- (void)resizeForTileFrame:(struct CGRect)arg1;
- (struct CGRect)tileFrame;
- (unsigned long long)tileID;
- (void)addWindowsWithIDs:(id)arg1;
- (void)setWindowContents:(id)arg1;
- (id)initWithTileID:(unsigned long long)arg1 parentSpaceID:(unsigned long long)arg2 tileFrame:(struct CGRect)arg3 includeBorder:(BOOL)arg4 window:(id)arg5;
- (void)dealloc;

@end

