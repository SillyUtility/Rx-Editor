//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

#import <AppKit/NSTouchBarColorListPickerContainerView-Protocol.h>

@class CABackdropLayer, CALayer, NSString;

__attribute__((visibility("hidden")))
@interface NSTouchBarColorListPickerBlurContainerView : NSView <NSTouchBarColorListPickerContainerView>
{
    CABackdropLayer *_backdropLayer;
    CALayer *_topCropLayer;
    CALayer *_bottomCropLayer;
    CALayer *_rightCropLayer;
    CALayer *_leftCropLayer;
    CALayer *_underContentCoverView;
    NSView *_contentView;
    BOOL _active;
}

@property BOOL active; // @synthesize active=_active;
- (BOOL)wantsLayer;
- (struct CGAffineTransform)_contentAffineTransform;
@property(retain) NSView *contentView; // @synthesize contentView=_contentView;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (BOOL)_shouldDoLayerPerformanceUpdates;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

