//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <AppKit/NSObject-Protocol.h>

@class NSString, NSTouchBar, NSTouchBarItem;

@protocol NSTouchBarDelegate <NSObject>

@optional
- (NSTouchBarItem *)touchBar:(NSTouchBar *)arg1 makeItemForIdentifier:(NSString *)arg2;
@end

