//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCopying-Protocol.h>

@class NSString;

@interface _NSDatePickerCellSubfield : NSObject <NSCopying>
{
    int _element;
    struct CGRect _frame;
    NSString *_dateFormat;
    NSString *_stringValue;
}

@property(copy) NSString *stringValue;
@property(readonly) NSString *dateFormat;
@property(readonly) struct CGRect frame;
@property(readonly) int element;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)initWithElement:(int)arg1 frame:(struct CGRect)arg2 dateFormat:(id)arg3 stringValue:(id)arg4;

@end

