//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSImage, NSString, NSURL;
@protocol NSSharingServiceDelegate;

@interface NSSharingService : NSObject
{
    id _reserved;
}

+ (void)_addRecentEmailServiceToDefaultsWithSubject:(id)arg1 recipients:(id)arg2;
+ (id)sharingServicesForAttributedString:(id)arg1 range:(struct _NSRange)arg2 mask:(unsigned long long)arg3;
+ (id)sharingServicesForItems:(id)arg1;
+ (void)getSharingServicesForItems:(id)arg1 completion:(CDUnknownBlockType)arg2;
+ (id)sharingServicesForItems:(id)arg1 mask:(unsigned long long)arg2;
+ (void)getSharingServicesForItems:(id)arg1 mask:(unsigned long long)arg2 completion:(CDUnknownBlockType)arg3;
+ (id)_filteredSharingServices:(id)arg1 forCloudSharingWithItems:(id)arg2;
+ (id)_urlFromItem:(id)arg1;
+ (id)sharingServiceNamed:(id)arg1;
+ (void)getSharingServiceNamed:(id)arg1 completion:(CDUnknownBlockType)arg2;
+ (void)_getSharingServiceNamed:(id)arg1 allowInactive:(BOOL)arg2 completion:(CDUnknownBlockType)arg3;
+ (id)_sharingServiceNamed:(id)arg1 allowInactive:(BOOL)arg2;
+ (BOOL)_usesItemProvider;
+ (Class)_SHKSharingServicePickerClass;
+ (Class)_SHKSharingServiceClass;
+ (void)_loadShareKit;
+ (id)_cloudSharingErrorClasses;
- (id)_touchBarImage;
- (BOOL)_blocksActionWhenModal:(SEL)arg1;
- (id)_preProcessingJavaScriptURL;
@property(readonly, copy) NSArray *attachmentFileURLs;
@property(readonly, copy) NSString *accountName;
@property(readonly, copy) NSURL *permanentLink;
@property(readonly, copy) NSString *messageBody;
@property(copy) NSString *subject;
@property(copy) NSArray *recipients;
@property(copy) NSString *menuItemTitle;
- (void)setParameterValue:(id)arg1 forKey:(id)arg2;
- (void)setParameters:(id)arg1;
- (id)parameters;
- (void)setEnabled:(BOOL)arg1;
- (BOOL)isEnabled;
@property(readonly) NSImage *alternateImage;
@property(readonly) NSImage *image;
- (void)setSubtitle:(id)arg1;
- (id)subtitle;
@property(readonly, copy) NSString *title;
- (id)name;
- (id)shkSharingService;
- (void)setShkSharingService:(id)arg1;
@property __weak id <NSSharingServiceDelegate> delegate;
- (long long)type;
- (void)dismissWithCompletion:(CDUnknownBlockType)arg1;
- (void)performWithItems:(id)arg1;
- (BOOL)canPerformWithItems:(id)arg1;
- (void)dealloc;
- (id)initWithTitle:(id)arg1 image:(id)arg2 alternateImage:(id)arg3 handler:(CDUnknownBlockType)arg4;
- (id)initWithName:(id)arg1 title:(id)arg2 image:(id)arg3 alternateImage:(id)arg4 type:(long long)arg5 handler:(CDUnknownBlockType)arg6;
- (id)init;
- (void)_commonInit;
- (void)_setInitialServiceState:(id)arg1;
- (id)_savedServiceState;
- (void)_setHeaderIcon:(id)arg1;
- (void)_setFolderSubitemName:(id)arg1;
- (void)_setRootFolderTitle:(id)arg1;
- (void)_setSecondaryCheckboxState:(long long)arg1;
- (void)_setSecondaryCheckboxTitle:(id)arg1;
- (void)_setPrimaryCheckboxState:(long long)arg1;
- (void)_setPrimaryCheckboxTitle:(id)arg1;
- (void)_setParticipantDetails:(id)arg1;
- (void)_setSharingApplicationURL:(id)arg1;
- (void)_setApplicationIcon:(id)arg1;
- (void)_setLocalizedPasswordActionTitle:(id)arg1;
- (void)_setIsAddPeopleService:(BOOL)arg1;

@end

