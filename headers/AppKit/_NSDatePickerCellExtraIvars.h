//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSButtonCell, NSColor, NSDate, NSDateComponents, NSNumberFormatter, NSTimer, _NSDatePickerArrowCell;

__attribute__((visibility("hidden")))
@interface _NSDatePickerCellExtraIvars : NSObject
{
    _NSDatePickerArrowCell *_arrowLeftCell;
    _NSDatePickerArrowCell *_arrowRightCell;
    NSButtonCell *_returnToHomeMonthButtonCell;
    NSDateComponents *_calendarDisplayedMonthDateComponents;
    NSColor *_disabledTextColor;
    NSNumberFormatter *_numberFormatter;
    NSTimer *_changeMonthTimer;
    NSDate *_lastFireDateForChangeMonthTimer;
}

- (void)dealloc;
- (void)setDisabledTextColor:(id)arg1;
- (id)disabledTextColor;
- (oneway void)releaseCalendarSpecificResources;
- (id)calendarDisplayedMonthDateComponents;
- (id)returnToHomeMonthButtonCellForDatePickerCell:(id)arg1;
- (id)arrowRightCellForDatePickerCell:(id)arg1;
- (id)arrowLeftCellForDatePickerCell:(id)arg1;

@end

