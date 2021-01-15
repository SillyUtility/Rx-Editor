//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <Foundation/NSLayoutRule-Protocol.h>

@class NSLayoutRect, NSString;

@interface NSLayoutRectRule : NSObject <NSLayoutRule>
{
    NSLayoutRect *_firstLayoutRect;
    NSLayoutRect *_secondLayoutRect;
    long long _relation;
}

@property long long relation; // @synthesize relation=_relation;
@property(readonly, copy) NSLayoutRect *secondLayoutRect; // @synthesize secondLayoutRect=_secondLayoutRect;
@property(readonly, copy) NSLayoutRect *firstLayoutRect; // @synthesize firstLayoutRect=_firstLayoutRect;
@property(readonly, copy) NSString *ruleDescription;
@property(readonly, copy) NSString *description;
- (id)makeChildRules;
@property(readonly, copy) NSString *identifier;
- (BOOL)isEqual:(id)arg1;
@property(readonly) unsigned long long hash;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)initWithFirstLayoutRect:(id)arg1 secondLayoutRect:(id)arg2 relation:(long long)arg3;
- (id)initWithFirstLayoutRect:(id)arg1 secondLayoutRect:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end

