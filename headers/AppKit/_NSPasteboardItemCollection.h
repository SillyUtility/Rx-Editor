//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMapTable;

__attribute__((visibility("hidden")))
@interface _NSPasteboardItemCollection : NSObject
{
    NSMapTable *_sparsePasteboardItems;
    long long _cachedItemGenerationCount;
}

- (id)pasteboardItemsWithItemCount:(unsigned long long)arg1 pasteboard:(id)arg2 generationCount:(long long)arg3;
- (id)pasteboardItemAtIndex:(unsigned long long)arg1 pasteboard:(id)arg2 generationCount:(long long)arg3;
- (void)addPasteboardItem:(id)arg1 atIndex:(unsigned long long)arg2 generationCount:(long long)arg3;
- (void)dealloc;
- (id)init;

@end

