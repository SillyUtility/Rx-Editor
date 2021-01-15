//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSFavoriteColorsStore.h>

#import <AppKit/NSFavoriteColorsStoreConcreteSubclass-Protocol.h>

@class NSURL;

__attribute__((visibility("hidden")))
@interface _NSLibraryArchiveFavoriteColorsStore : NSFavoriteColorsStore <NSFavoriteColorsStoreConcreteSubclass>
{
    NSURL *_fileURL;
}

- (id)colorsFromBacking;
- (BOOL)writeColorsToBacking:(id)arg1;
- (void)postDistributedNotification;
- (void)remoteColorsDidChange:(id)arg1;
- (void)dealloc;
- (id)init;
- (id)initWithFileURL:(id)arg1;

@end

