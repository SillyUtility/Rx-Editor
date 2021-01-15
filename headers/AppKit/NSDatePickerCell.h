//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSActionCell.h>

@class NSCalendar, NSColor, NSDate, NSLocale, NSTimeZone;
@protocol NSDatePickerCellDelegate;

@interface NSDatePickerCell : NSActionCell
{
    double _timeInterval;
    NSDate *_minDate;
    NSDate *_maxDate;
    struct __dateCellFlags {
        unsigned int elements:16;
        unsigned int controlStyle:3;
        unsigned int controlMode:2;
        unsigned int trackingHand:2;
        unsigned int reserved2:4;
        unsigned int drawsBackground:1;
        unsigned int digitsEntered:2;
        unsigned int forcesLeadingZeroes:1;
        unsigned int wrapsDateComponentArithmetic:1;
    } _dcFlags;
    id <NSDatePickerCellDelegate> _delegate;
    NSCalendar *_calendar;
    NSLocale *_locale;
    NSTimeZone *_timeZone;
    NSColor *_backgroundColor;
    NSColor *_textColor;
    BOOL _force24Hr;
    int _indexOfSelectedSubfield;
    id _reserved1;
    id _reserved2;
    id _reserved3;
    id _reserved4;
}

+ (id)_sharedDateFormatter;
+ (void)initialize;
+ (id)_calendarWeekDayHeaderFont;
+ (double)_calendarHeaderFontSize;
+ (id)_calendarHeaderFontOfSize:(double)arg1;
+ (id)_calendarHeaderFont;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (BOOL)keyDown:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (void)stopTracking:(struct CGPoint)arg1 at:(struct CGPoint)arg2 inView:(id)arg3 mouseIsUp:(BOOL)arg4;
- (BOOL)continueTracking:(struct CGPoint)arg1 at:(struct CGPoint)arg2 inView:(id)arg3;
- (BOOL)startTrackingAt:(struct CGPoint)arg1 inView:(id)arg2;
- (BOOL)trackMouse:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 untilMouseUp:(BOOL)arg4;
- (unsigned long long)hitTestForEvent:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (void)drawFocusRingMaskWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (struct CGRect)focusRingMaskBoundsForFrame:(struct CGRect)arg1 inView:(id)arg2;
- (struct CGSize)cellSize;
@property __weak id <NSDatePickerCellDelegate> delegate;
@property(copy) NSDate *maxDate;
@property(copy) NSDate *minDate;
@property double timeInterval;
@property(copy) NSDate *dateValue;
- (void)setObjectValue:(id)arg1;
@property(copy) NSTimeZone *timeZone;
@property(copy) NSLocale *locale;
@property(copy) NSCalendar *calendar;
@property unsigned long long datePickerElements;
@property unsigned long long datePickerMode;
- (id)_defaultFont;
- (void)setFont:(id)arg1;
@property(copy) NSColor *textColor;
@property(copy) NSColor *backgroundColor;
@property BOOL drawsBackground;
@property unsigned long long datePickerStyle;
- (void)setEnabled:(BOOL)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)initTextCell:(id)arg1;
- (id)init;
- (void)_setWrapsDateComponentArithmetic:(BOOL)arg1;
- (BOOL)_wrapsDateComponentArithmetic;
- (void)_setForcesLeadingZeroes:(BOOL)arg1;
- (BOOL)_forcesLeadingZeroes;
- (void)_setDisabledTextColor:(id)arg1;
- (id)_disabledTextColor;
- (id)_constrainDateValue:(id)arg1 timeInterval:(double *)arg2;
- (void)_finishPendingEdit;
- (BOOL)_constrainAndSetDateValue:(id)arg1 timeInterval:(double)arg2 sendActionIfChanged:(BOOL)arg3 beepIfNoChange:(BOOL)arg4 returnCalendarToHomeMonth:(BOOL)arg5 preserveFractionalSeconds:(BOOL)arg6;
- (void)_toggleAMPM;
- (void)_adjustDatePickerElement:(int)arg1 by:(long long)arg2 returnCalendarToHomeMonth:(BOOL)arg3;
- (long long)_digitForLocalizedDigitCharacter:(unsigned short)arg1;
- (struct _NSRange)_rangeOfDaysForMonth:(long long)arg1 year:(long long)arg2;
- (BOOL)_localeIsRTL;
- (id)_effectiveLocale;
- (id)_effectiveCalendar;
- (long long)_dayOfWeekForDate:(id)arg1;
- (BOOL)_dateIsAM:(id)arg1;
- (id)_dateFromComponents:(id)arg1;
- (id)_componentsOfInterestToDatePickerFromDate:(id)arg1;
- (void)_clampDayToValidRangeInDateComponents:(id)arg1;
- (id)_adjustDate:(id)arg1 byEras:(long long)arg2 years:(long long)arg3 months:(long long)arg4 days:(long long)arg5 hours:(long long)arg6 minutes:(long long)arg7 seconds:(long long)arg8;
- (id)_numberFormatter;
- (void)_invalidateDateFormatter;
- (id)_dateFormatter;
- (id)_calenderWeekdayHeaderTextColorBasedOnEnabledState;
- (id)_calenderHeaderTextColorBasedOnEnabledState;
- (id)_textColorBasedOnEnabledState;
- (BOOL)_fixUpDatePickerElementFlags;
- (BOOL)_allocateDatePickerCellExtraIvars;
- (void)_unregisterForDatePreferencesChanges;
- (void)_registerForDatePreferencesChanges;
- (void)_datePreferencesDidChange:(id)arg1;
- (void)_stepperCellValueChanged:(id)arg1;
- (id)_stepperCell;
- (id)_stepper;
- (void)_setStepper:(id)arg1;
- (BOOL)_selectSubfieldWithElement:(int)arg1;
- (int)_selectedSubfieldElement;
- (id)_selectedSubfield;
- (void)_selectLastSubfield;
- (void)_selectFirstSubfield;
- (void)_selectPreviousSubfield;
- (void)_selectNextSubfield;
- (void)_notifyDelegateIndexOfSelectedSubfieldDidChange;
- (void)_setForce24Hr:(BOOL)arg1;
- (void)_setPM:(BOOL)arg1;
- (void)_insertDigit:(long long)arg1;
- (void)_cancelSubfieldFieldChanges;
- (void)_commitSubfieldFieldChanges;
- (void)_deleteDigit;
- (void)_cancelUserEditTimer;
- (void)_resetUserEditTimer;
- (void)_userEditExpired:(id)arg1;
- (void)_incrementSelectedSubfield;
- (void)_decrementSelectedSubfield;
- (BOOL)_processKeyDownCharacters:(id)arg1;
- (BOOL)_textFieldWithStepperKeyDown:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (BOOL)_textFieldWithStepperTrackMouse:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 untilMouseUp:(BOOL)arg4;
- (long long)_indexOfSelectedSubfield;
- (BOOL)_isLastSubfieldSelected;
- (BOOL)_isFirstSubfieldSelected;
- (int)_elementAtSubfieldIndex:(unsigned long long)arg1;
- (id)_subfields;
- (void)_updateSubfieldStringsForDateChange;
- (id)_stringForDatePickerElement:(int)arg1 usingDateFormat:(id)arg2;
- (void)_makeSubfieldsWithHandler:(CDUnknownBlockType)arg1;
- (id)_dateFormatByForcing24HourModeFromFormatString:(id)arg1;
- (id)_concoctUnholyAbominationOfADateFormatThatMakesAMockeryOfLocalization;
- (void)_addSubfieldForElement:(int)arg1 withDateFormat:(id)arg2 referenceStrings:(id)arg3;
- (void)_addStaticSubfieldWithString:(id)arg1;
- (void)_addEditableSubfieldForElement:(int)arg1 dateFormat:(id)arg2;
- (id)_referenceDatesForElement:(int)arg1;
- (void)_createSubfields;
- (struct CGRect)_subfieldsFrameAccountingForTextAreaFrameInBounds;
- (struct CGRect)_subfieldsFrame;
- (double)_subfieldOffsetForTextAreaFrame:(struct CGRect)arg1;
- (struct CGSize)_textFieldCellSize;
- (struct CGSize)_textFieldWithStepperCellSize;
- (long long)_indexOfSubfieldAtPoint:(struct CGPoint)arg1 inTextAreaFrame:(struct CGRect)arg2;
- (void)_getTextAreaFrame:(struct CGRect *)arg1 stepperCellFrame:(struct CGRect *)arg2 forDatePickerCellFrame:(struct CGRect)arg3;
- (double)_stepperCellTopAndBottomTrim;
- (struct CGSize)_desiredTextAreaSize;
- (long long)_textFieldAlignment;
- (BOOL)_stepperIsRTL;
- (BOOL)_shouldShowFocusRingInView:(id)arg1;
- (BOOL)_hasFocusRingInView:(id)arg1;
- (void)_drawTextFieldWithStepperWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)_drawThemeBezelWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (struct NSEdgeInsets)_contentInsetsForThemeBezelWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (struct NSEdgeInsets)_alignmentRectInsetsForThemeBezelWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (id)_coreUIDrawOptionsForThemeBezelWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (unsigned long long)_hitTestTextFieldWithStepper:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (void)_clockAndCalendarTakeDisplayedMonthFromTodaysDate;
- (void)_clockAndCalendarTakeDisplayedMonthFromDateValue;
- (void)_clockAndCalendarReturnToHomeMonth:(id)arg1;
- (void)_clockAndCalendarRightArrowClicked:(id)arg1;
- (void)_clockAndCalendarLeftArrowClicked:(id)arg1;
- (void)_clockAndCalendarAdvanceMonth;
- (void)_clockAndCalendarRetreatMonth;
- (BOOL)_clockAndCalendarIsTargetMonthLeapMonth:(id)arg1 offset:(long long)arg2;
- (id)_clockAndCalendarReturnToHomeMonthButtonCell;
- (id)_clockAndCalendarAdvanceMonthCell;
- (id)_clockAndCalendarRetreatMonthCell;
- (BOOL)_clockAndCalendarKeyDown:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (void)_autoAdvanceCalendar:(id)arg1;
- (void)_clockAndCalendarStopTracking:(struct CGPoint)arg1 at:(struct CGPoint)arg2 inView:(id)arg3 mouseIsUp:(BOOL)arg4;
- (BOOL)_clockAndCalendarContinueTracking:(struct CGPoint)arg1 at:(struct CGPoint)arg2 inView:(id)arg3;
- (BOOL)_clockAndCalendarStartTrackingAt:(struct CGPoint)arg1 inView:(id)arg2;
- (id)_calendarDateComponentsForPoint:(struct CGPoint)arg1 inCalendarRect:(struct CGRect)arg2;
- (BOOL)_clockAndCalendarTrackMouse:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 untilMouseUp:(BOOL)arg4;
- (void)_clockAndCalendarGetClockFrame:(struct CGRect *)arg1 calendarFrame:(struct CGRect *)arg2 retreatMonthCellFrame:(struct CGRect *)arg3 advanceMonthCellFrame:(struct CGRect *)arg4 returnToHomeMonthButtonCellFrame:(struct CGRect *)arg5 forDatePickerCellFrame:(struct CGRect)arg6;
- (struct CGRect)_calendarDaysFrameForDatePickerCellFrame:(struct CGRect)arg1;
- (struct CGSize)_clockAndCalendarCellSize;
- (void)_drawClockAndCalendarWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (unsigned long long)_hitTestClockAndCalendar:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (void)_clockAndCalendarFillDayCell:(long long)arg1 withColor:(id)arg2 inFrame:(struct CGRect)arg3 inView:(id)arg4;
- (void)_clockAndCalendarFillDayCellRange:(struct _NSRange)arg1 withColor:(id)arg2 inFrame:(struct CGRect)arg3 inView:(id)arg4;
- (id)_calendarContentAttributedStringWithSelectedDayCells:(struct _NSRange)arg1;
- (BOOL)_calendarIsRTL;
- (id)_calendarDayNamesStringForFirstWeekday:(long long)arg1;
- (struct _NSRange)_calendarRangeOfSelectedDaysForDisplayedMonthOffset:(long long)arg1;
- (struct _NSRange)_calendarRangeOfAllDaysForDisplayedMonth;
- (struct _NSRange)_calendarRangeOfAllDaysForDisplayedMonthOffset:(long long)arg1;
- (long long)_calendarFirstWeekday;
- (id)_calendarFirstDayOfDisplayedMonthDateComponents;
- (id)_calendarDateComponentsOfFirstDayOfDisplayedMonthOffset:(long long)arg1;
- (BOOL)_analogClockTrackMouse:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 untilMouseUp:(BOOL)arg4;
- (void)_drawAnalogClockWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (id)_formatGregorianYearWithDate:(id)arg1;
- (BOOL)_useChineseSetting;
- (BOOL)accessibilityIsDateTimeComponentsAttributeSettable;
- (id)accessibilityDateTimeComponentsAttribute;
- (BOOL)accessibilityIsMaxValueAttributeSettable;
- (id)accessibilityMaxValueAttribute;
- (BOOL)accessibilityIsMinValueAttributeSettable;
- (id)accessibilityMinValueAttribute;
- (void)accessibilitySetValueAttribute:(id)arg1;
- (BOOL)accessibilityIsValueAttributeSettable;
- (id)accessibilityValueAttribute;
- (id)accessibilityRoleAttribute;
- (id)accessibilityAttributeNames;

@end

