//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/NSXMLNamedNode.h>

@class NSMutableArray, NSString;

__attribute__((visibility("hidden")))
@interface NSXMLNamedFidelityNode : NSXMLNamedNode
{
    unsigned long long _fidelity;
    NSString *_whitespace;
    NSMutableArray *_ranges;
    NSMutableArray *_names;
}

- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)setNames:(id)arg1;
- (void)setRanges:(id)arg1;
- (BOOL)_setPrefix:(id)arg1;
- (void)_XMLStringWithOptions:(unsigned long long)arg1 appendingToString:(id)arg2;
- (void)addEntity:(id)arg1 index:(unsigned long long)arg2;
- (id)objectValue;
- (id)stringValue;
- (void)setStringValue:(id)arg1 resolvingEntities:(BOOL)arg2;
- (void)setWhitespace:(id)arg1;
- (unsigned long long)fidelity;
- (void)setFidelity:(unsigned long long)arg1;
- (id)initWithKind:(unsigned long long)arg1;
- (void)dealloc;

@end

