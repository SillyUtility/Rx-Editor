//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSCGSWindowLayerSurface.h>

@class NSCGSWindow;

__attribute__((visibility("hidden")))
@interface _NSCGSWindowLocallyRenderedLayerSurface : NSCGSWindowLayerSurface
{
    NSCGSWindow *_window;
    unsigned int _surfaceID;
    struct _CAView *_view;
    struct CGRect _frame;
    struct CGColorSpace *_colorSpace;
    double _scale;
    unsigned int _opaque:1;
}

+ (void)initialize;
- (BOOL)isLocallyRendered;
- (void)setLayer:(id)arg1;
- (id)layer;
- (void)setDisplayNumber:(unsigned int)arg1;
- (unsigned int)displayNumber;
- (void)setDisplayMask:(unsigned int)arg1;
- (unsigned int)displayMask;
- (void)setScale:(double)arg1;
- (double)scale;
- (void)setOpaque:(BOOL)arg1;
- (BOOL)isOpaque;
- (void)setColorSpace:(struct CGColorSpace *)arg1;
- (struct CGColorSpace *)colorSpace;
- (void)setFrame:(struct CGRect)arg1;
- (struct CGRect)frame;
- (unsigned int)surfaceID;
- (id)window;
- (void)dealloc;
- (id)initWithWindow:(id)arg1;

@end

