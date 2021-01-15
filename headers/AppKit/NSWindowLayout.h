//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCopying-Protocol.h>
#import <AppKit/NSSecureCoding-Protocol.h>

__attribute__((visibility("hidden")))
@interface NSWindowLayout : NSObject <NSCopying, NSSecureCoding>
{
    struct CGRect _windowFrame;
    struct CGRect _screenLayoutFrame;
}

+ (BOOL)supportsSecureCoding;
- (id)description;
- (void)dealloc;
- (void)adjustFrame:(struct CGRect *)arg1 forWindow:(id)arg2 onScreen:(id)arg3;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithWindowFrame:(struct CGRect)arg1 screenLayoutFrame:(struct CGRect)arg2;
- (id)initWithWindow:(id)arg1 screen:(id)arg2;

@end

