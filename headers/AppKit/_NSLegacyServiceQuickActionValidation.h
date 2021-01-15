//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/_NSQuickActionValidation-Protocol.h>

@class NSMutableSet, NSSet, NSString;
@protocol _NSQuickActionItemSource;

__attribute__((visibility("hidden")))
@interface _NSLegacyServiceQuickActionValidation : NSObject <_NSQuickActionValidation>
{
    id <_NSQuickActionItemSource> _itemSource;
    NSSet *_unvalidatedQuickActions;
    NSMutableSet *_validQuickActions;
    void *_observationInfo;
}

+ (BOOL)automaticallyNotifiesObserversOfValidQuickActions;
+ (BOOL)accessInstanceVariablesDirectly;
+ (id)validationForItemSource:(id)arg1 quickActions:(id)arg2;
- (void).cxx_destruct;
- (void)dealloc;
@property(readonly, copy) NSSet *validQuickActions;
- (void *)observationInfo;
- (void)setObservationInfo:(void *)arg1;
@property(readonly) BOOL wantsAutovalidation;
- (id)initForItemSource:(id)arg1 quickActions:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

