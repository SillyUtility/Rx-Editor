//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/_NSTouchBarItemLayoutWrapper-Protocol.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface NSTouchBarCustomizationPreviewSectionLayoutItemDescription : NSObject <_NSTouchBarItemLayoutWrapper>
{
    struct CGSize _minSize;
    struct CGSize _preferredSize;
    struct CGSize _maxSize;
    struct CGSize _contentClippingSize;
    struct CGSize _backupDragSize;
    BOOL _isStacked;
    BOOL _isCentered;
    BOOL _isSpace;
    BOOL _requiresTrueCenterLayout;
    long long _priorityIndex;
    unsigned long long _itemPosition;
    BOOL _isEditable;
    long long _itemState;
    BOOL _showsAppState;
    struct CGPoint _dragPosition;
    struct CGPoint _dragAnchorPoint;
}

@property BOOL requiresTrueCenterLayout; // @synthesize requiresTrueCenterLayout=_requiresTrueCenterLayout;
@property struct CGSize backupDragSize; // @synthesize backupDragSize=_backupDragSize;
@property unsigned long long itemPosition; // @synthesize itemPosition=_itemPosition;
@property long long priorityIndex; // @synthesize priorityIndex=_priorityIndex;
@property BOOL showsAppState; // @synthesize showsAppState=_showsAppState;
@property long long itemState; // @synthesize itemState=_itemState;
@property(getter=isEditable) BOOL editable; // @synthesize editable=_isEditable;
@property(getter=isStacked) BOOL stacked; // @synthesize stacked=_isStacked;
@property struct CGPoint dragAnchorPoint; // @synthesize dragAnchorPoint=_dragAnchorPoint;
@property struct CGPoint dragPosition; // @synthesize dragPosition=_dragPosition;
@property(getter=isCentered) BOOL centered; // @synthesize centered=_isCentered;
@property BOOL isSpace; // @synthesize isSpace=_isSpace;
@property struct CGSize contentClippingSize; // @synthesize contentClippingSize=_contentClippingSize;
@property struct CGSize maxSize; // @synthesize maxSize=_maxSize;
@property struct CGSize preferredSize; // @synthesize preferredSize=_preferredSize;
@property struct CGSize minSize; // @synthesize minSize=_minSize;
@property(readonly, copy) NSString *description;
@property(readonly, getter=isDragging) BOOL dragging;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) BOOL participatesInOverflow;
@property(readonly) double preferredTrailingPosition;
@property(readonly) double preferredZOrder;
@property(readonly) Class superclass;

@end

