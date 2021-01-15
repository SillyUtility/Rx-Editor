//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <QuartzCore/CAOpenGLLayer.h>

@class NSOpenGLContext, NSOpenGLPixelFormat, NSView;

@interface NSOpenGLLayer : CAOpenGLLayer
{
}

+ (id)defaultValueForKey:(id)arg1;
- (void)didChangeValueForKey:(id)arg1;
- (void)willChangeValueForKey:(id)arg1;
- (void)_NS_invalidateSuggestedContentsScale;
- (void)display;
- (void)drawInCGLContext:(struct _CGLContextObject *)arg1 pixelFormat:(struct _CGLPixelFormatObject *)arg2 forLayerTime:(double)arg3 displayTime:(const CDStruct_e50ab651 *)arg4;
- (BOOL)canDrawInCGLContext:(struct _CGLContextObject *)arg1 pixelFormat:(struct _CGLPixelFormatObject *)arg2 forLayerTime:(double)arg3 displayTime:(const CDStruct_e50ab651 *)arg4;
- (oneway void)releaseCGLContext:(struct _CGLContextObject *)arg1;
- (struct _CGLContextObject *)copyCGLContextForPixelFormat:(struct _CGLPixelFormatObject *)arg1;
- (oneway void)releaseCGLPixelFormat:(struct _CGLPixelFormatObject *)arg1;
- (struct _CGLPixelFormatObject *)copyCGLPixelFormatForDisplayMask:(unsigned int)arg1;
- (void)drawInOpenGLContext:(id)arg1 pixelFormat:(id)arg2 forLayerTime:(double)arg3 displayTime:(const CDStruct_e50ab651 *)arg4;
- (BOOL)canDrawInOpenGLContext:(id)arg1 pixelFormat:(id)arg2 forLayerTime:(double)arg3 displayTime:(const CDStruct_e50ab651 *)arg4;
- (id)openGLContextForPixelFormat:(id)arg1;
- (void)drawInContext:(struct CGContext *)arg1;
- (id)openGLPixelFormatForDisplayMask:(unsigned int)arg1;
@property __weak NSView *view;
- (void)_appkitViewBackingLayerUniqueMethod;

// Remaining properties
@property(retain) NSOpenGLContext *openGLContext; // @dynamic openGLContext;
@property(retain) NSOpenGLPixelFormat *openGLPixelFormat; // @dynamic openGLPixelFormat;

@end

