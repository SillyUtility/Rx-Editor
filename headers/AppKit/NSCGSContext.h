//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSGraphicsContext.h>

@interface NSCGSContext : NSGraphicsContext
{
    struct CGContext *_cgsContext;
}

+ (id)graphicsContextWithAttributes:(id)arg1;
- (BOOL)isFlipped;
- (void)_releaseCIContext;
- (void)_invalidate;
- (unsigned int)windowID;
- (void *)graphicsPort;
- (struct CGContext *)_swapContextForCarbonDrawing:(struct CGContext *)arg1;
- (void)flushGraphics;
- (void)restoreGraphicsState;
- (void)saveGraphicsState;
- (void)dealloc;
- (void)setColorRenderingIntent:(long long)arg1;
- (long long)colorRenderingIntent;
- (unsigned long long)compositingOperation;
- (void)setCompositingOperation:(unsigned long long)arg1;
- (struct CGPoint)patternPhase;
- (void)setPatternPhase:(struct CGPoint)arg1;
- (unsigned long long)imageInterpolation;
- (void)setImageInterpolation:(unsigned long long)arg1;
- (BOOL)shouldAntialias;
- (void)setShouldAntialias:(BOOL)arg1;
- (struct CGSize)_alignSize:(struct CGSize)arg1 force:(BOOL)arg2;
- (struct CGPoint)_alignPoint:(struct CGPoint)arg1 force:(BOOL)arg2;
- (struct CGRect)_alignRect:(struct CGRect)arg1 force:(BOOL)arg2;
- (BOOL)_shouldEnforcePixelAlignment;
- (void)_setShouldEnforcePixelAlignment:(BOOL)arg1;
- (id)CIContext;

@end

