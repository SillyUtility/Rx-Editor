//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <OSAKit/OSAScriptElement.h>

@class NSString;

@interface OSAControlElement : OSAScriptElement
{
    NSString *_controlName;
}

+ (id)elementWithName:(id)arg1 text:(id)arg2;
- (BOOL)generateIntoText:(id)arg1 indent:(unsigned int)arg2;
- (void)setControlName:(id)arg1;
- (id)controlName;
- (void)dealloc;
- (id)initWithName:(id)arg1 text:(id)arg2;
- (id)initWithName:(id)arg1;

@end

