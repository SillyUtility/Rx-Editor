//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <Foundation/NSCoding-Protocol.h>
#import <Foundation/NSCopying-Protocol.h>

@class NSLayoutDimension, NSLayoutPoint, NSLayoutXAxisAnchor, NSLayoutYAxisAnchor, NSString;

@interface NSLayoutRect : NSObject <NSCopying, NSCoding>
{
    NSLayoutXAxisAnchor *_leadingAnchor;
    NSLayoutYAxisAnchor *_topAnchor;
    NSLayoutDimension *_heightAnchor;
    NSLayoutDimension *_widthAnchor;
    NSString *_name;
    id _reserved1;
}

+ (id)layoutRectWithCenterLayoutPoint:(id)arg1 widthAnchor:(id)arg2 heightAnchor:(id)arg3;
+ (id)layoutRectWithCenterXAnchor:(id)arg1 centerYAnchor:(id)arg2 widthAnchor:(id)arg3 heightAnchor:(id)arg4;
+ (id)layoutRectWithLeadingAnchor:(id)arg1 topAnchor:(id)arg2 trailingAnchor:(id)arg3 bottomAnchor:(id)arg4;
+ (id)layoutRectWithLeadingAnchor:(id)arg1 topAnchor:(id)arg2 widthAnchor:(id)arg3 heightAnchor:(id)arg4;
- (id)constraintsContainingWithinLayoutRect:(id)arg1;
- (id)constraintsEqualToLayoutRect:(id)arg1;
- (id)layoutRectBySlicingWithProportion:(double)arg1 fromEdge:(long long)arg2;
- (id)layoutRectBySlicingWithDimension:(id)arg1 fromEdge:(long long)arg2;
- (id)layoutRectBySlicingWithDistance:(double)arg1 fromEdge:(long long)arg2;
- (id)_rectangleBySlicingWithDimension:(id)arg1 plusConstant:(double)arg2 fromEdge:(long long)arg3;
- (id)layoutRectByInsettingTopWithDimension:(id)arg1 leadingWithDimension:(id)arg2 bottomWithDimension:(id)arg3 trailingWithDimension:(id)arg4;
- (id)layoutRectByInsettingTop:(double)arg1 leading:(double)arg2 bottom:(double)arg3 trailing:(double)arg4;
@property(readonly, copy) NSLayoutPoint *centerLayoutPoint;
@property(readonly, copy) NSLayoutDimension *heightAnchor;
@property(readonly, copy) NSLayoutDimension *widthAnchor;
@property(readonly, copy) NSLayoutXAxisAnchor *trailingAnchor;
@property(readonly, copy) NSLayoutXAxisAnchor *centerXAnchor;
@property(readonly, copy) NSLayoutXAxisAnchor *leadingAnchor;
@property(readonly, copy) NSLayoutYAxisAnchor *bottomAnchor;
@property(readonly, copy) NSLayoutYAxisAnchor *centerYAnchor;
@property(readonly, copy) NSLayoutYAxisAnchor *topAnchor;
- (id)_equationDescriptionInParent;
- (id)debugDescription;
- (id)description;
- (BOOL)isEqualToRectangle:(id)arg1;
- (BOOL)isEqual:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithLeadingAnchor:(id)arg1 topAnchor:(id)arg2 widthAnchor:(id)arg3 heightAnchor:(id)arg4 name:(id)arg5;
- (id)initWithLeadingAnchor:(id)arg1 topAnchor:(id)arg2 widthAnchor:(id)arg3 heightAnchor:(id)arg4;
- (id)observableValueInItem:(id)arg1;
- (struct CGRect)valueInItem:(id)arg1;
- (id)layoutRectWithName:(id)arg1;
- (BOOL)nsli_isLegalConstraintItem;
- (id)nsli_superitem;
- (id)ruleContainingLayoutRect:(id)arg1;
- (id)ruleEqualToLayoutRect:(id)arg1;

@end

