//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSString, NSViewController;

@interface NSPDFPanel : NSObject
{
    NSViewController *_accessoryController;
    long long _options;
    NSString *_defaultFileName;
    id _panel;
    id _private;
}

+ (id)panel;
@property long long options; // @synthesize options=_options;
@property(retain) NSViewController *accessoryController; // @synthesize accessoryController=_accessoryController;
- (void)beginSheetWithPDFInfo:(id)arg1 modalForWindow:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (void)_setOKButtonDisabled:(BOOL)arg1;
- (BOOL)_okButtonDisabled;
- (void)_setPanel:(id)arg1;
- (id)_panel;
- (void)_setPrintInfo:(id)arg1;
- (id)_printInfo;
- (void)dealloc;
@property(copy) NSString *defaultFileName;

@end

