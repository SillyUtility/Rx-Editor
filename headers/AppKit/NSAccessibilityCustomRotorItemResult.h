//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSString;
@protocol NSAccessibilityElement, NSSecureCoding><NSObject;

@interface NSAccessibilityCustomRotorItemResult : NSObject
{
    id <NSAccessibilityElement> _targetElement;
    struct _NSRange _targetRange;
    NSString *_customLabel;
    id <NSSecureCoding><NSObject> _itemLoadingToken;
}

- (void).cxx_destruct;
@property(readonly) id <NSSecureCoding><NSObject> itemLoadingToken; // @synthesize itemLoadingToken=_itemLoadingToken;
@property(copy) NSString *customLabel; // @synthesize customLabel=_customLabel;
@property struct _NSRange targetRange; // @synthesize targetRange=_targetRange;
- (id)description;
@property(readonly) __weak id <NSAccessibilityElement> targetElement;
- (void)dealloc;
- (id)initWithItemLoadingToken:(id)arg1 customLabel:(id)arg2;
- (id)initWithTargetElement:(id)arg1;

@end

