//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCopying-Protocol.h>

@class ISIcon, NSArray;

__attribute__((visibility("hidden")))
@interface NSImageISIconRepProvider : NSObject <NSCopying>
{
    ISIcon *_icon;
    NSArray *_representations;
}

@property(readonly) NSArray *representations;
- (id)description;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)initWithISIcon:(id)arg1;

@end

