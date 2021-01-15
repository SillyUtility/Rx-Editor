//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSMutableArray, NSMutableString, OSAScriptView;

@interface OSAScriptAssistantDataSource : NSObject
{
    OSAScriptView *_scriptView;
    NSMutableArray *_strategies;
    NSArray *_items;
    NSMutableString *_infoString;
    struct _NSRange _lastParseRange;
}

+ (id)smallKeywordImage;
+ (id)smallLocalImage;
+ (id)smallEventImage;
+ (id)smallCommandImage;
+ (id)smallTerminologyImage;
+ (id)smallEnumImage;
+ (id)smallPropertyImage;
+ (id)smallGlobalImage;
+ (id)smallScriptImage;
+ (id)keywordImage;
+ (id)localImage;
+ (id)eventImage;
+ (id)commandImage;
+ (id)terminologyImage;
+ (id)enumImage;
+ (id)propertyImage;
+ (id)globalImage;
+ (id)scriptImage;
- (BOOL)isPopupTrigger:(unsigned short)arg1;
- (long long)count;
- (void)updateList;
- (BOOL)shouldUpdateList;
- (void)purgeList;
- (void)setLastParseRange:(struct _NSRange)arg1;
- (struct _NSRange)lastParseRange;
- (void)setInfoString:(id)arg1;
- (id)infoString;
- (void)setItems:(id)arg1;
- (id)items;
- (void)setStrategies:(id)arg1;
- (id)strategies;
- (void)setScriptView:(id)arg1;
- (id)scriptView;
- (void)dealloc;
- (id)initWithScriptView:(id)arg1;

@end

