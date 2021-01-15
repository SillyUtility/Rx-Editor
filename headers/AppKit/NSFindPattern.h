//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSCoding-Protocol.h>
#import <AppKit/NSCopying-Protocol.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface NSFindPattern : NSObject <NSCoding, NSCopying>
{
    NSString *regularExpression;
    NSString *tokenString;
    NSString *displayString;
    NSString *replacementString;
    NSString *uniqueID;
    BOOL allowsBackreferences;
    int groupID;
    int captureGroupID;
    int repeatedPatternID;
}

+ (id)placeholderFindPattern;
+ (unsigned long long)readingOptionsForType:(id)arg1 pasteboard:(id)arg2;
+ (id)readableTypesForPasteboard:(id)arg1;
@property(copy) NSString *replacementString; // @synthesize replacementString;
@property int repeatedPatternID; // @synthesize repeatedPatternID;
@property(readonly) NSString *uniqueID; // @synthesize uniqueID;
@property int captureGroupID; // @synthesize captureGroupID;
@property BOOL allowsBackreferences; // @synthesize allowsBackreferences;
@property int groupID; // @synthesize groupID;
@property(copy) NSString *tokenString; // @synthesize tokenString;
@property(copy) NSString *displayString; // @synthesize displayString;
- (id)backreferenceExpression;
- (id)replaceExpression;
@property(copy) NSString *regularExpression; // @synthesize regularExpression;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithPropertyListRepresentation:(id)arg1;
- (id)propertyListRepresentation;
- (id)writableTypesForPasteboard:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)generateNewUniqueID;
- (void)_setUniqueID:(id)arg1;
- (id)description;
- (void)dealloc;

@end

