//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSAccessibilityElement-Protocol.h>

@class NSAttributedString, NSString;

@protocol NSAccessibilityStaticText <NSAccessibilityElement>
- (NSString *)accessibilityValue;

@optional
- (struct _NSRange)accessibilityVisibleCharacterRange;
- (NSAttributedString *)accessibilityAttributedStringForRange:(struct _NSRange)arg1;
@end

