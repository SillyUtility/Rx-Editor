//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSObject-Protocol.h>

@class NSTouchBarColorPickerSlider;

@protocol NSTouchBarColorPickerSliderMinimizationDelegate <NSObject>
- (void)colorPickerSliderCompletedInteraction:(NSTouchBarColorPickerSlider *)arg1;
- (BOOL)colorPickerSliderWantsToBeUnminimized:(NSTouchBarColorPickerSlider *)arg1 completionHandler:(void (^)(void))arg2;
@end

