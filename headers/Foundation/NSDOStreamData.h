//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSMutableData.h>

__attribute__((visibility("hidden")))
@interface NSDOStreamData : NSMutableData
{
    id refObject;
    struct {
        id data;
        char *datap;
        char *limitp;
        char *startp;
        id callback;
        char datapVM;
    } stream;
}

- (unsigned long long)length;
- (void *)mutableBytes;
- (const void *)bytes;
- (void)finalize;
- (void)dealloc;
- (id)init;

@end

