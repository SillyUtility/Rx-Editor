//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSRegularExpression;

__attribute__((visibility("hidden")))
@interface _NSImageTypeData : NSObject
{
    NSArray *imageTypes;
    NSArray *imageFileTypes;
    NSArray *imagePasteboardTypes;
    NSRegularExpression *namedImageSuffixExpression;
    NSArray *imageUnfilteredTypes;
    NSArray *imageUnfilteredFileTypes;
    NSArray *imageUnfilteredPasteboardTypes;
    NSRegularExpression *namedImageUnfilteredSuffixExpression;
}

+ (void)initialize;
- (id)namedImageUnfilteredSuffixExpression;
- (id)namedImageSuffixExpression;
- (id)imageUnfilteredPasteboardTypes;
- (id)imageUnfilteredFileTypes;
- (id)imageUnfilteredTypes;
- (id)imagePasteboardTypes;
- (id)imageFileTypes;
- (id)imageTypes;
- (void)dealloc;

@end

