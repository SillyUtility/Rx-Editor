//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSArrayChange.h>

__attribute__((visibility("hidden")))
@interface NSConcreteArrayChange : NSArrayChange
{
    unsigned long long _changeType;
    unsigned long long _sourceIndex;
    unsigned long long _destinationIndex;
    id _value;
}

- (id)value;
- (unsigned long long)destinationIndex;
- (unsigned long long)sourceIndex;
- (unsigned long long)changeType;
- (void)dealloc;
- (id)initWithType:(unsigned long long)arg1 sourceIndex:(unsigned long long)arg2 destinationIndex:(unsigned long long)arg3 value:(id)arg4;

@end

