//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSLocking-Protocol.h>

@class NSOpenGLPixelFormat, NSView;

@interface NSOpenGLContext : NSObject <NSLocking>
{
    NSView *_view;
    struct _CGLContextObject *_CGLContext;
}

+ (void)clearCurrentContext;
+ (void)setCurrentContext:(id)arg1;
+ (id)currentContext;
+ (void)initialize;
+ (id)openGLContextWithCGLContextObj:(struct _CGLContextObject *)arg1;
- (void).cxx_destruct;
@property(readonly) struct _CGLContextObject *CGLContextObj;
- (BOOL)texImageIOSurface:(id)arg1 target:(unsigned int)arg2 internalFormat:(unsigned int)arg3 width:(int)arg4 height:(int)arg5 format:(unsigned int)arg6 type:(unsigned int)arg7 plane:(unsigned int)arg8;
- (void)createTexture:(unsigned int)arg1 fromView:(id)arg2 internalFormat:(unsigned int)arg3;
@property int currentVirtualScreen;
- (void)getValues:(int *)arg1 forParameter:(long long)arg2;
- (void)setValues:(const int *)arg1 forParameter:(long long)arg2;
- (void)setFullScreen;
- (void)setOffScreen:(void *)arg1 width:(int)arg2 height:(int)arg3 rowbytes:(int)arg4;
- (void)_viewDidChangeGeometryInWindow:(id)arg1;
- (void)_surfaceDidComeBack:(id)arg1;
- (void)_surfaceWillGoAway:(id)arg1;
@property __weak NSView *view;
- (void)update;
- (void)clearDrawable;
- (void)flushBuffer;
- (void)copyAttributesFromContext:(id)arg1 withMask:(unsigned int)arg2;
- (void)makeCurrentContext;
- (void)dealloc;
- (void)unlock;
- (void)lock;
@property(readonly) NSOpenGLPixelFormat *pixelFormat;
- (id)initWithCGLContextObj:(struct _CGLContextObject *)arg1;
- (id)initWithFormat:(id)arg1 shareContext:(id)arg2;
- (void)_updateOpenGLViewport;
@property(readonly) BOOL hasDefaultFramebuffer;
@property(readonly) struct CGSize defaultFramebufferDimensions;
- (void)setTextureImageToPixelBuffer:(id)arg1 colorBuffer:(unsigned int)arg2;
- (int)pixelBufferMipMapLevel;
- (unsigned int)pixelBufferCubeMapFace;
- (id)pixelBuffer;
- (void)setPixelBuffer:(id)arg1 cubeMapFace:(unsigned int)arg2 mipMapLevel:(int)arg3 currentVirtualScreen:(int)arg4;

@end

