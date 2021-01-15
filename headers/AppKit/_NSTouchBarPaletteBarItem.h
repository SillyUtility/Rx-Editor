//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCopying-Protocol.h>

@class NSImage, NSString, NSTouchBarItem;

__attribute__((visibility("hidden")))
@interface _NSTouchBarPaletteBarItem : NSObject <NSCopying>
{
    NSImage *_itemSnapshot;
    NSString *_itemIdentifier;
    NSTouchBarItem *_representedItem;
    long long _customizability;
    NSString *_disabledContainingGroupIdentifier;
    struct CGSize _minSize;
    struct CGSize _preferredSize;
    struct CGSize _maxSize;
    BOOL _hasCachedMinMaxSize;
}

+ (id)paletteItemForBarItem:(id)arg1 customizability:(long long)arg2;
@property(copy) NSString *disabledContainingGroupIdentifier; // @synthesize disabledContainingGroupIdentifier=_disabledContainingGroupIdentifier;
@property(readonly) long long customizability; // @synthesize customizability=_customizability;
@property(readonly) NSTouchBarItem *representedItem; // @synthesize representedItem=_representedItem;
@property(readonly, copy) NSString *itemIdentifier; // @synthesize itemIdentifier=_itemIdentifier;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (struct CGSize)maxSize;
- (struct CGSize)preferredSize;
- (struct CGSize)minSize;
- (void)_updateMinMaxSizeIfNeeded;
- (id)itemSnapshotWithSize:(struct CGSize)arg1;
- (id)currentItemSnapshot;
- (void)dealloc;

@end

