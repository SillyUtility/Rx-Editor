//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSCGSWindowSurface.h>

__attribute__((visibility("hidden")))
@interface NSCGSWindowOpenGLSurface : NSCGSWindowSurface
{
}

- (void)detachCGLContext:(struct _CGLContextObject *)arg1;
- (void)attachCGLContext:(struct _CGLContextObject *)arg1;

// Remaining properties
@property struct CGColorSpace *colorSpace; // @dynamic colorSpace;
@property(getter=isOpaque) BOOL opaque; // @dynamic opaque;
@property double scale; // @dynamic scale;

@end

