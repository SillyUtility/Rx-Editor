//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSUserNotification.h>

#import <Foundation/NSSecureCoding-Protocol.h>

@class NSArray, NSData, NSDate, NSDateComponents, NSString, NSTimeZone, NSURL, NSUserNotificationAction;

__attribute__((visibility("hidden")))
@interface _NSConcreteUserNotification : NSUserNotification <NSSecureCoding>
{
    NSString *_title;
    NSString *_subtitle;
    NSString *_dateString;
    NSString *_informativeText;
    NSString *_actionButtonTitle;
    NSString *_otherButtonTitle;
    NSString *_soundName;
    NSString *_identifier;
    NSString *_proxyIdentifier;
    NSString *_responsePlaceholder;
    NSURL *_imageURL;
    NSData *_secureEncodedUserInfo;
    NSData *_encodedResponse;
    NSDate *_deliveryDate;
    NSTimeZone *_deliveryTimeZone;
    NSDateComponents *_deliveryRepeatInterval;
    NSDateComponents *_deliveryExpiration;
    NSDateComponents *_duration;
    NSDate *_eventDate;
    NSData *_contentImageData;
    NSData *_identityImageData;
    NSUserNotificationAction *_additionalActivationAction;
    unsigned long long _identityImageStyle;
    NSArray *_additionalActions;
    double _snoozeInterval;
    double _snoozedDate;
    NSArray *_alternateActionButtonTitles;
    unsigned long long _alternateActionIndex;
    NSArray *_peopleIdentifiers;
    NSDate *_actualDeliveryDate;
    id _storageID;
    unsigned long long _style;
    unsigned long long _displayStyle;
    long long _activationType;
    long long _badgeCount;
    BOOL _hasActionButton;
    BOOL _presented;
    BOOL _snoozed;
    BOOL _remote;
    BOOL _clearable;
    BOOL _allDayEvent;
    BOOL _actionButtonIsSnooze;
    BOOL _dismissAfterDuration;
    BOOL _persistent;
    BOOL _poofsOnCancel;
    BOOL _ignoresDoNotDisturb;
    BOOL _hasReplyButton;
    BOOL _showsButtons;
    BOOL _lockscreenOnly;
    BOOL _substitutesEmojiInResponse;
    BOOL _hasAttachment;
    BOOL _alwaysShowAlternateActionMenu;
}

+ (BOOL)supportsSecureCoding;
- (id)additionalActions;
- (id)additionalActivationAction;
- (void)set_alwaysShowAlternateActionMenu:(BOOL)arg1;
- (BOOL)_alwaysShowAlternateActionMenu;
- (void)set_hasAttachment:(BOOL)arg1;
- (BOOL)_hasAttachment;
- (void)set_substitutesEmojiInResponse:(BOOL)arg1;
- (BOOL)_substitutesEmojiInResponse;
- (void)set_lockscreenOnly:(BOOL)arg1;
- (BOOL)_lockscreenOnly;
- (void)set_showsButtons:(BOOL)arg1;
- (BOOL)_showsButtons;
- (unsigned long long)_alternateActionIndex;
- (void)set_alternateActionButtonTitles:(id)arg1;
- (id)_alternateActionButtonTitles;
- (void)setResponsePlaceholder:(id)arg1;
- (id)responsePlaceholder;
- (void)set_identityImageStyle:(unsigned long long)arg1;
- (unsigned long long)_identityImageStyle;
- (void)set_ignoresDoNotDisturb:(BOOL)arg1;
- (BOOL)_ignoresDoNotDisturb;
- (void)set_poofsOnCancel:(BOOL)arg1;
- (BOOL)_poofsOnCancel;
- (void)set_persistent:(BOOL)arg1;
- (BOOL)_persistent;
- (void)set_dismissAfterDuration:(BOOL)arg1;
- (BOOL)_dismissAfterDuration;
- (void)set_actionButtonIsSnooze:(BOOL)arg1;
- (BOOL)_actionButtonIsSnooze;
- (void)set_allDayEvent:(BOOL)arg1;
- (BOOL)_isAllDayEvent;
- (void)set_deliveryExpiration:(id)arg1;
- (id)_deliveryExpiration;
- (void)set_dateString:(id)arg1;
- (id)_dateString;
- (void)set_eventDate:(id)arg1;
- (id)_eventDate;
- (void)set_badgeCount:(long long)arg1;
- (long long)_badgeCount;
- (double)_snoozedDate;
- (double)_snoozeInterval;
- (BOOL)_snoozed;
- (void)set_displayStyle:(unsigned long long)arg1;
- (unsigned long long)_displayStyle;
- (void)set_style:(unsigned long long)arg1;
- (unsigned long long)_style;
- (BOOL)isRemote;
- (void)set_clearable:(BOOL)arg1;
- (BOOL)_clearable;
- (void)set_storageID:(id)arg1;
- (id)_storageID;
- (void)setDuration:(id)arg1;
- (id)duration;
- (long long)activationType;
- (BOOL)isPresented;
- (id)actualDeliveryDate;
- (id)deliveryRepeatInterval;
- (void)setDeliveryTimeZone:(id)arg1;
- (id)deliveryTimeZone;
- (void)setDeliveryDate:(id)arg1;
- (id)deliveryDate;
- (id)_imageURL;
- (void)set_proxyIdentifier:(id)arg1;
- (id)_proxyIdentifier;
- (void)setIdentifier:(id)arg1;
- (id)identifier;
- (void)setSoundName:(id)arg1;
- (id)soundName;
- (void)setHasReplyButton:(BOOL)arg1;
- (BOOL)hasReplyButton;
- (void)setHasActionButton:(BOOL)arg1;
- (BOOL)hasActionButton;
- (id)informativeText;
- (id)subtitle;
- (id)title;
- (id)description;
- (id)_nextFireDate;
- (unsigned long long)hash;
- (void)setPeopleIdentifiers:(id)arg1;
- (id)peopleIdentifiers;
- (void)setAdditionalActions:(id)arg1;
- (void)_setAdditionalActivationAction:(id)arg1;
- (void)_setAlternateActionIndex:(unsigned long long)arg1;
- (BOOL)_areIdentifiersEqual:(id)arg1;
- (void)set_contentImageData:(id)arg1;
- (id)_contentImageData;
- (BOOL)_hasContentImage;
- (id)contentImage;
- (void)setContentImage:(id)arg1;
- (BOOL)_identityImageHasBorder;
- (void)set_identityImageHasBorder:(BOOL)arg1;
- (void)_setActivationType:(long long)arg1;
- (void)_setSnoozedDate:(double)arg1;
- (void)_setSnoozeInterval:(double)arg1;
- (void)_setSnoozed:(BOOL)arg1;
- (void)setRemote:(BOOL)arg1;
- (void)_setPresented:(BOOL)arg1;
- (void)_setActualDeliveryDate:(id)arg1;
- (void)setDeliveryRepeatInterval:(id)arg1;
- (void)_setResponse:(id)arg1;
- (id)response;
- (void)set_identityImageData:(id)arg1;
- (id)_identityImageData;
- (id)_identityImage;
- (void)set_identityImage:(id)arg1;
- (void)_setIdentityImage:(id)arg1 withIdentifier:(id)arg2;
- (id)_secureEncodedUserInfo;
- (void)_setEncodedUserInfo:(id)arg1;
- (void)setUserInfo:(id)arg1;
- (id)userInfo;
- (void)set_imageURL:(id)arg1;
- (void)setOtherButtonTitle:(id)arg1;
- (id)otherButtonTitle;
- (void)setActionButtonTitle:(id)arg1;
- (id)actionButtonTitle;
- (void)setInformativeText:(id)arg1;
- (void)setSubtitle:(id)arg1;
- (void)setTitle:(id)arg1;
- (void)set_subtitle:(id)arg1;
- (BOOL)_isRemote;
- (id)_subtitle;
- (void)dealloc;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;

@end

