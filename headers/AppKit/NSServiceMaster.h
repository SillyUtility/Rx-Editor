//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <AppKit/NSServiceMasterProto-Protocol.h>

@class NSMutableDictionary;

@interface NSServiceMaster : NSObject <NSServiceMasterProto>
{
    NSMutableDictionary *_localObjects;
    id _reserved;
    struct {
        unsigned int serviceVendingIsActive:1;
        unsigned int reserved:31;
    } _serviceFlags;
}

+ (id)internalRunService:(id)arg1 pboard:(id)arg2 flags:(unsigned long long)arg3 cancelledHint:(const char *)arg4;
+ (id)copyServiceForUUID:(id)arg1;
+ (id)copyServiceForAppIdentifier:(id)arg1 messageName:(id)arg2;
+ (id)sharedServiceMaster;
- (id)objectForServicePath:(id)arg1 app:(id)arg2 doLaunch:(BOOL)arg3 limitDate:(id)arg4;
- (id)objectForServicePath:(id)arg1 app:(id)arg2 doLaunch:(BOOL)arg3 limitDate:(id)arg4 basePortName:(id)arg5;
- (id)objectForServicePath:(id)arg1;
- (id)serviceListener;
- (void)unregisterObjectWithServicePath:(id)arg1;
- (void)registerObject:(id)arg1 withServicePath:(id)arg2;
- (void)dealloc;
- (id)init;

@end

