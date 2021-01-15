//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSMutableData.h>

__attribute__((visibility("hidden")))
@interface NSConcreteMutableData : NSMutableData
{
    unsigned int _reserved:1;
    unsigned int _needToZero:1;
    unsigned int _hasVM:1;
    unsigned int _retainCount:29;
    unsigned long long _length;
    unsigned long long _capacity;
    void *_bytes;
}

- (BOOL)_providesConcreteBacking;
- (void)dealloc;
- (id)initWithBytes:(void *)arg1 length:(unsigned long long)arg2 copy:(BOOL)arg3 deallocator:(CDUnknownBlockType)arg4;
- (id)initWithCapacity:(unsigned long long)arg1;
- (id)initWithLength:(unsigned long long)arg1;
- (id)init;
- (void)resetBytesInRange:(struct _NSRange)arg1;
- (void)replaceBytesInRange:(struct _NSRange)arg1 withBytes:(const void *)arg2;
- (void)increaseLengthBy:(unsigned long long)arg1;
- (void)appendData:(id)arg1;
- (void)appendBytes:(const void *)arg1 length:(unsigned long long)arg2;
- (void)setLength:(unsigned long long)arg1;
- (BOOL)_canUseRealloc;
- (void)_freeBytes;
- (void *)mutableBytes;
- (const void *)bytes;
- (unsigned long long)length;

@end

