//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSObject-Protocol.h>

@class NSColorList, NSColorPickerSpectrumScrollerView;

@protocol NSColorPickerSpectrumScrollerViewDataSource <NSObject>
- (NSColorList *)colorListForSpectrumView:(NSColorPickerSpectrumScrollerView *)arg1;
- (long long)pageCountForSpectrumView:(NSColorPickerSpectrumScrollerView *)arg1;
- (long long)currentPageForSpectrumView:(NSColorPickerSpectrumScrollerView *)arg1;
@end

