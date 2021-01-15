//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSPopUpButton, NSRulerView, NSTextField, NSWindow;

__attribute__((visibility("hidden")))
@interface NSRulerViewAccessibilityPanelController : NSObject
{
    NSWindow *_accessibilityPanel;
    NSTextField *_valueField;
    NSPopUpButton *_markerTypeButton;
    NSRulerView *_rulerView;
}

@property(retain, setter=_setAccessibilityPanel:) NSWindow *_accessibilityPanel; // @synthesize _accessibilityPanel;
- (void)_cancelAddMarker:(id)arg1;
- (void)_addMarker:(id)arg1;
- (id)_markerTypeButton;
- (id)_valueField;
- (void)dealloc;
- (id)initWithRulerView:(id)arg1;
- (void)set_accessibilityPanel:(id)arg1;

@end

