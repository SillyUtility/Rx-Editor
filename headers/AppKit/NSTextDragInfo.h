//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSView, NSViewWindowBackingStoreBuffer;

__attribute__((visibility("hidden")))
@interface NSTextDragInfo : NSObject
{
    struct CGRect indicatorViewRect;
    BOOL savedImageValid;
    NSViewWindowBackingStoreBuffer *cacheFromUnderIndicator;
    BOOL draggingLinkedFile;
    NSView *dragAnimationOverlay;
}

@property(nonatomic) NSView *dragAnimationOverlay; // @synthesize dragAnimationOverlay;
@property(nonatomic, getter=isDraggingLinkedFile) BOOL draggingLinkedFile; // @synthesize draggingLinkedFile;
@property(nonatomic, getter=isSavedImageValid) BOOL savedImageValid; // @synthesize savedImageValid;
@property(retain, nonatomic) NSViewWindowBackingStoreBuffer *cacheFromUnderIndicator; // @synthesize cacheFromUnderIndicator;
@property(nonatomic) struct CGRect indicatorViewRect; // @synthesize indicatorViewRect;
- (void)dealloc;

@end

