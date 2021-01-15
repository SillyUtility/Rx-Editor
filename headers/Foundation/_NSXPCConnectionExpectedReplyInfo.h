//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSBlock, NSDictionary, NSXPCInterface;

__attribute__((visibility("hidden")))
@interface _NSXPCConnectionExpectedReplyInfo : NSObject
{
    NSBlock *_replyBlock;
    CDUnknownBlockType _errorBlock;
    CDUnknownBlockType _cleanupBlock;
    SEL _selector;
    NSXPCInterface *_interface;
    NSDictionary *_userInfo;
    unsigned long long _proxyNumber;
}

@property unsigned long long proxyNumber; // @synthesize proxyNumber=_proxyNumber;
@property(retain) NSDictionary *userInfo; // @synthesize userInfo=_userInfo;
@property(retain) NSXPCInterface *interface; // @synthesize interface=_interface;
@property(copy) CDUnknownBlockType cleanupBlock; // @synthesize cleanupBlock=_cleanupBlock;
@property(copy) CDUnknownBlockType errorBlock; // @synthesize errorBlock=_errorBlock;
@property(copy) NSBlock *replyBlock; // @synthesize replyBlock=_replyBlock;
@property SEL selector; // @synthesize selector=_selector;
- (void)dealloc;

@end

