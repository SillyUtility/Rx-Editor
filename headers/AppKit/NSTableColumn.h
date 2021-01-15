//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCoding-Protocol.h>
#import <AppKit/NSUserInterfaceItemIdentification-Protocol.h>

@class NSCell, NSSortDescriptor, NSString, NSTableHeaderCell, NSTableView;

@interface NSTableColumn : NSObject <NSCoding, NSUserInterfaceItemIdentification>
{
    NSTableView *_tableView;
    id _identifier;
    double _width;
    double _minWidth;
    double _maxWidth;
    NSCell *_headerCell;
    NSCell *_dataCell;
    struct __colFlags {
        unsigned int oldIsResizable:1;
        unsigned int isEditable:1;
        unsigned int resizedPostingDisableCount:8;
        unsigned int canUseReorderResizeImageCache:1;
        unsigned int userResizingAllowed:1;
        unsigned int autoResizingAllowed:1;
        unsigned int hidden:1;
        unsigned int isOutlineTableColumn:1;
        unsigned int RESERVED:17;
    } _cFlags;
    id _tcAuxiliaryStorage;
}

- (void).cxx_destruct;
@property(copy) NSString *headerToolTip;
- (id)_bindingAdaptor;
- (void)_setBindingAdaptor:(id)arg1;
- (void)sizeToFit;
@property(copy) NSString *title;
@property(getter=isEditable) BOOL editable;
- (BOOL)isResizable;
- (void)setResizable:(BOOL)arg1;
@property unsigned long long resizingMask;
- (id)dataCellForRow:(long long)arg1;
- (id)dataCell;
- (void)setDataCell:(id)arg1;
- (void)_updateDataCellControlView;
- (void)_updateHeaderCellControlView;
@property(retain) NSTableHeaderCell *headerCell;
@property double maxWidth;
@property double minWidth;
- (double)_outlineIndetantionSafeMinWidth;
@property double width;
@property(copy) NSString *identifier;
@property(copy) NSSortDescriptor *sortDescriptorPrototype;
- (void)_setIsOutlineTableColumn:(BOOL)arg1;
- (BOOL)_isOutlineTableColumn;
@property __weak NSTableView *tableView;
- (BOOL)_canUseReorderResizeImageCache;
- (void)_setCanUseReorderResizeImageCache:(BOOL)arg1;
- (id)_reorderResizeImageCache;
- (void)_setReorderResizeImageCache:(id)arg1;
@property(getter=isHidden) BOOL hidden;
- (void)_finishedMakingConnections;
- (id)description;
- (id)initWithCoder:(id)arg1;
- (void)_old_initWithCoder_NSTableColumn:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)_old_encodeWithCoder_NSTableColumn:(id)arg1;
- (void)dealloc;
- (id)init;
- (id)initWithIdentifier:(id)arg1;
- (void)_postColumnDidResizeNotificationWithOldWidth:(long long)arg1;
- (BOOL)_resizePostingDisabled;
- (void)_enableResizedPosting;
- (void)_disableResizedPosting;
- (void)_setCachedPosition:(CDStruct_6b6ad735)arg1;
- (CDStruct_6b6ad735)_cachedPosition;
- (void)setUserInterfaceItemIdentifier:(id)arg1;
- (id)userInterfaceItemIdentifier;
- (BOOL)accessibilityShouldUseUniqueId;
- (id)accessibilityArrayAttributeValues:(id)arg1 index:(unsigned long long)arg2 maxCount:(unsigned long long)arg3;
- (unsigned long long)accessibilityArrayAttributeCount:(id)arg1;
- (id)accessibilityFocusedUIElement;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (BOOL)accessibilityIsIgnored;
- (void)accessibilityPerformAction:(id)arg1;
- (id)accessibilityActionDescription:(id)arg1;
- (id)accessibilityActionNames;
- (void)accessibilitySetValue:(id)arg1 forAttribute:(id)arg2;
- (BOOL)accessibilityIsAttributeSettable:(id)arg1;
- (id)accessibilityAttributeValue:(id)arg1;
- (BOOL)accessibilityIsIndexAttributeSettable;
- (id)accessibilityIndexAttribute;
- (BOOL)accessibilityIsHeaderAttributeSettable;
- (id)accessibilityHeaderAttribute;
- (void)accessibilitySetSelectedAttribute:(id)arg1;
- (BOOL)accessibilityIsSelectedAttributeSettable;
- (BOOL)_canDeselect:(long long)arg1;
- (id)accessibilitySelectedAttribute;
- (void)accessibilitySetSizeAttribute:(id)arg1;
- (BOOL)accessibilityIsSizeAttributeSettable;
- (id)accessibilitySizeAttribute;
- (BOOL)accessibilityIsPositionAttributeSettable;
- (id)accessibilityPositionAttribute;
- (BOOL)accessibilityIsTopLevelUIElementAttributeSettable;
- (id)accessibilityTopLevelUIElementAttribute;
- (BOOL)accessibilityIsWindowAttributeSettable;
- (id)accessibilityWindowAttribute;
- (BOOL)accessibilityIsVisibleRowsAttributeSettable;
- (id)accessibilityVisibleRowsAttribute;
- (BOOL)accessibilityIsRowsAttributeSettable;
- (id)accessibilityRowsAttribute;
- (id)_accessibilityRowsInRange:(struct _NSRange)arg1;
- (BOOL)accessibilityIsParentAttributeSettable;
- (id)accessibilityParentAttribute;
- (BOOL)accessibilityIsRoleDescriptionAttributeSettable;
- (id)accessibilityRoleDescriptionAttribute;
- (BOOL)accessibilityIsRoleAttributeSettable;
- (id)accessibilityRoleAttribute;
- (id)accessibilityAttributeNames;

@end

