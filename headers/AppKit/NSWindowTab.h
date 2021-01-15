//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSAttributedString, NSImage, NSString, NSTabBarItem, NSView, NSWindow;

@interface NSWindowTab : NSObject
{
    NSString *_title;
    NSAttributedString *_attributedTitle;
    NSString *_toolTip;
    NSImage *_image;
    NSView *_accessoryView;
    NSTabBarItem *_tabBarItem;
    NSWindow *_window;
    BOOL _showIcon;
}

- (void).cxx_destruct;
@property __weak NSWindow *window; // @synthesize window=_window;
@property(readonly) NSTabBarItem *tabBarItem;
@property(copy) NSAttributedString *attributedTitle;
@property BOOL showIcon;
@property(copy) NSImage *image;
@property(retain) NSView *accessoryView;
@property(copy) NSString *toolTip;
@property(copy) NSString *title;

@end

