//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSObject-Protocol.h>

@class NSFindPattern;
@protocol NSFindPatternField;

@protocol NSFindPatternManager <NSObject>
- (id <NSFindPatternField>)replaceFieldForField:(id <NSFindPatternField>)arg1;
- (id <NSFindPatternField>)findFieldForField:(id <NSFindPatternField>)arg1;

@optional
- (BOOL)supportsPatterns;
- (void)findPatternField:(id <NSFindPatternField>)arg1 findPatternDoubleClicked:(NSFindPattern *)arg2;
@end

