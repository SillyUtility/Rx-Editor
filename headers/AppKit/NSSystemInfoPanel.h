//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSTextViewDelegate-Protocol.h>

@class NSImageView, NSLayoutConstraint, NSMutableDictionary, NSPanel, NSScrollView, NSString, NSTextField, NSTextView;

@interface NSSystemInfoPanel : NSObject <NSTextViewDelegate>
{
    NSScrollView *creditScrollView;
    NSPanel *infoPanel;
    NSImageView *appIconView;
    NSTextField *appNameField;
    NSTextView *creditView;
    NSTextView *copyrightView;
    NSTextField *copyrightField;
    NSScrollView *copyrightScrollView;
    NSTextField *versionField;
    NSLayoutConstraint *creditScrollViewWidthConstraint;
    NSMutableDictionary *_optionsDictionary;
}

+ (void)updateOptionsWithVersion:(id)arg1;
+ (void)updateOptionsWithMarketingVersion:(id)arg1;
+ (void)updateOptionsWithCredits:(id)arg1;
+ (void)updateOptionsWithCopyright:(id)arg1;
+ (void)updateOptionsWithApplicationName:(id)arg1;
+ (void)updateOptionsWithApplicationIcon:(id)arg1;
+ (void)updateOptions:(id)arg1;
+ (id)sharedInfoPanel;
@property NSLayoutConstraint *creditScrollViewWidthConstraint; // @synthesize creditScrollViewWidthConstraint;
@property NSScrollView *copyrightScrollView; // @synthesize copyrightScrollView;
@property NSTextField *copyrightField; // @synthesize copyrightField;
@property NSTextField *versionField; // @synthesize versionField;
@property NSTextView *copyrightView; // @synthesize copyrightView;
@property NSTextView *creditView; // @synthesize creditView;
@property NSTextField *appNameField; // @synthesize appNameField;
@property NSImageView *appIconView; // @synthesize appIconView;
@property(retain) NSPanel *infoPanel; // @synthesize infoPanel;
@property(retain) NSScrollView *creditScrollView; // @synthesize creditScrollView;
- (BOOL)textView:(id)arg1 clickedOnLink:(id)arg2 atIndex:(unsigned long long)arg3;
- (void)windowWillClose:(id)arg1;
- (void)sizeCopyrightView;
- (void)sizeCreditsView;
- (id)versionString;
- (id)credits;
- (id)copyright;
- (id)backgroundImage;
- (id)applicationName;
- (id)applicationIcon;
- (void)updateNib;
- (void)unloadNib:(BOOL)arg1;
- (void)loadNib;
- (void)setOptionsDictionary:(id)arg1;
- (void)showInfoPanel:(id)arg1;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

