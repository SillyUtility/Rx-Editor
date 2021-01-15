//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSSecureCoding-Protocol.h>

@class CKShareParticipant, NSColor, NSString;

@interface _NSCloudSharingParticipantDetails : NSObject <NSSecureCoding>
{
    CKShareParticipant *_participant;
    NSString *_detailText;
    NSColor *_participantColor;
}

+ (BOOL)supportsSecureCoding;
@property(copy) NSColor *participantColor; // @synthesize participantColor=_participantColor;
@property(readonly, copy) NSString *detailText; // @synthesize detailText=_detailText;
@property(readonly) CKShareParticipant *participant; // @synthesize participant=_participant;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;
- (id)initWithParticipant:(id)arg1 detailText:(id)arg2;

@end

