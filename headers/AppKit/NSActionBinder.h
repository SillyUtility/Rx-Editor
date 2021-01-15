//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSEditorBinder.h>

__attribute__((visibility("hidden")))
@interface NSActionBinder : NSEditorBinder
{
    SEL _selector;
    struct __actionBinderFlags {
        unsigned int _allSeparateArrayArgumentsBoundToIdenticalController:1;
        unsigned int _reservedActionBinder:31;
    } _actionBinderFlags;
}

+ (id)bindingCategory;
+ (id)bindingsForObject:(id)arg1;
+ (id)_enumeratedArgumentBindings:(unsigned long long)arg1;
+ (id)_targetBinding;
+ (id)_enumerationBinding;
+ (id)_pluginProtocol;
- (void)updateTableColumnDataCell:(id)arg1 forDisplayAtIndex:(unsigned long long)arg2;
- (void)updateOutlineColumnDataCell:(id)arg1 forDisplayAtIndexPath:(id)arg2;
- (void)_observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 context:(void *)arg3;
- (void)performAction:(id)arg1;
- (BOOL)_performActionWithCommitEditing;
- (void)_performActionWithCommitEditing:(id)arg1 didCommit:(BOOL)arg2 contextInfo:(id)arg3;
- (void)_executePerformAction;
- (BOOL)targetAndArgumentsAcceptableAtIndexPath:(id)arg1;
- (BOOL)targetAndArgumentsAcceptableAtIndex:(unsigned long long)arg1;
- (BOOL)targetAndArgumentsAcceptable;
- (BOOL)_targetAndArgumentsAcceptableForMode:(struct __NSKeyValueCodingControllerModeType)arg1;
- (void)_invokeSelector:(SEL)arg1 withArguments:(id)arg2 forBinding:(id)arg3;
- (BOOL)invokesSeparatelyWithArrayObjectsWithBinding:(id)arg1;
- (void)setInvokesSeparatelyWithArrayObjects:(BOOL)arg1 withBinding:(id)arg2;
- (BOOL)allowsNullArgumentWithBinding:(id)arg1;
- (void)setAllowsNullArgument:(BOOL)arg1 withBinding:(id)arg2;
- (SEL)selector;
- (void)setSelector:(SEL)arg1;
- (id)_optionsForBinding:(id)arg1 specifyOnlyIfDifferentFromDefault:(BOOL)arg2;
- (void)_setParameter:(id)arg1 forOption:(id)arg2 withBindingInfo:(id)arg3;
- (id)_referenceBinding;
- (void)removeBinding:(id)arg1;
- (BOOL)canApplyValueTransformer:(id)arg1 toBinding:(id)arg2;
- (BOOL)selectionSupportsEnabledState;
- (BOOL)bindingRunsAlerts:(id)arg1;
- (BOOL)isBindingReadOnly:(id)arg1;
- (BOOL)_targetBindingBound;
- (id)availableBindings;
- (void)_connectionWasEstablished;
- (unsigned long long)_argumentBindingCount;
- (void)_copyDetailsFromBinder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)_init;

@end

