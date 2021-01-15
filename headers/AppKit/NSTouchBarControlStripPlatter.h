//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSView.h>

#import <AppKit/NSCollectionViewElement-Protocol.h>

@class NSColor, NSString;

@interface NSTouchBarControlStripPlatter : NSView <NSCollectionViewElement>
{
    double _cornerRadius;
    NSColor *_platterColor;
}

+ (id)keyPathsForValuesInvalidatingDisplay;
@property double cornerRadius; // @synthesize cornerRadius=_cornerRadius;
- (BOOL)wantsUpdateLayer;
- (void)updateLayer;
- (void)drawRect:(struct CGRect)arg1;
@property(copy) NSColor *platterColor;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (BOOL)_shouldDoLayerPerformanceUpdates;
- (void)prepareForReuse;
- (void)applyLayoutAttributes:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(copy) NSString *identifier;
@property(readonly) Class superclass;

@end

