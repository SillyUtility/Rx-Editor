//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCoding-Protocol.h>
#import <AppKit/NSCopying-Protocol.h>

@class NSImage;

__attribute__((visibility("hidden")))
@interface _NSButtonImage : NSObject <NSCopying, NSCoding>
{
    NSImage *image;
    BOOL useDisabledEffect;
    BOOL useHighlightEffect;
}

+ (id)image:(id)arg1;
+ (void)initialize;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;

@end

