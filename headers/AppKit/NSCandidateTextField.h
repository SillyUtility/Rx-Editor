//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSTextField.h>

@class NSColor;

__attribute__((visibility("hidden")))
@interface NSCandidateTextField : NSTextField
{
    NSColor *_candidateColor;
    BOOL _trimOnLeft;
    BOOL _trimOnRight;
}

+ (Class)cellClass;
@property BOOL trimOnRight; // @synthesize trimOnRight=_trimOnRight;
@property BOOL trimOnLeft; // @synthesize trimOnLeft=_trimOnLeft;
- (void)setSelected:(BOOL)arg1;
- (void)dealloc;
- (void)setAttributedCorrection:(id)arg1;

@end

