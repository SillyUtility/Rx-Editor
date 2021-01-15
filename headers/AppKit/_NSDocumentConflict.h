//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSDocumentConflictPanelController, NSFileVersion, NSImage;

__attribute__((visibility("hidden")))
@interface _NSDocumentConflict : NSObject
{
    NSDocumentConflictPanelController *_controller;
    NSFileVersion *_version;
    BOOL _selected;
    struct __QLThumbnail *_thumbnail;
    NSImage *_thumbnailImage;
    BOOL _showName;
    BOOL _documentIsShared;
}

@property BOOL documentIsShared; // @synthesize documentIsShared=_documentIsShared;
@property BOOL showName; // @synthesize showName=_showName;
@property(copy) NSImage *thumbnail; // @synthesize thumbnail=_thumbnailImage;
@property(retain) NSFileVersion *version; // @synthesize version=_version;
@property NSDocumentConflictPanelController *controller; // @synthesize controller=_controller;
- (id)previewItemTitle;
- (id)previewItemURL;
- (void)dealloc;
- (void)startLoadingDocumentThumbnailWithSize:(struct CGSize)arg1 scaleFactor:(double)arg2 force:(BOOL)arg3;
- (id)nameAndDateText;
- (id)originText;
@property(getter=isSelected) BOOL selected;
- (BOOL)isEqual:(id)arg1;

@end

