//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSPortNameServer.h>

@interface NSMessagePortNameServer : NSPortNameServer
{
}

+ (id)sharedInstance;
- (BOOL)removePortForName:(id)arg1;
- (BOOL)registerPort:(id)arg1 name:(id)arg2;
- (id)portForName:(id)arg1 host:(id)arg2;
- (id)portForName:(id)arg1;

@end

