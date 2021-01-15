//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppleScriptKit/NSCoding-Protocol.h>

@class ASKScript, NSMutableArray, NSString;

@interface ASKScriptController : NSObject <NSCoding>
{
    NSString *_scriptName;
    ASKScript *_script;
    NSMutableArray *_eventHandlers;
}

- (id)executeAppleEvent:(id)arg1;
- (void)enableEventHandlers:(BOOL)arg1;
- (void)removeEventHandler_ask:(id)arg1;
- (void)addEventHandler_ask:(id)arg1;
- (void)setEventHandlers_ask:(id)arg1;
- (id)eventHandlers_ask;
- (void)setScript:(id)arg1;
- (id)script;
- (void)setScriptName:(id)arg1;
- (id)scriptName;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)awakeFromNib;
- (void)dealloc;
- (id)initWithScript:(id)arg1;
- (id)initWithName:(id)arg1;
- (id)init;

@end

