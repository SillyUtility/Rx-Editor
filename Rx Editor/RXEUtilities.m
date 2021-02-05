//
//  RXEUtilities.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/4/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <JavaScriptCore/JavaScriptCore.h>
#import <SillyLog/SillyLog.h>

#import "RXEUtilities.h"

@implementation RXEUtilities

@end

/*
    - Ensure the first character is an ascii letter
    - Capitablize the first character of every word
    - Preserve the case of any other character
    - Remove spaces and special characters
 */
NSString *RXEClassNameFromString(NSString *str)
{
    NSMutableString *name;
    NSUInteger i;
    unichar c;
    NSCharacterSet *wsSet;
    BOOL capitalizeNext;

    name = NSMutableString.string;
    wsSet = NSCharacterSet.whitespaceAndNewlineCharacterSet;
    capitalizeNext = NO;
    str = [str
        stringByApplyingTransform:NSStringTransformToLatin
        reverse:NO
    ];

    for (i = 0; i < str.length; i++) {
        c = [str characterAtIndex:i];
        if ([wsSet characterIsMember:c]) {
            capitalizeNext = YES;
            continue;
        } else if (isalpha(c)) {
            if (name.length == 0 || capitalizeNext) {
                capitalizeNext = NO;
                c = toupper(c);
            }
        } else if (isdigit(c)) {
            if (name.length == 0)
                continue;
            capitalizeNext = NO;
        } else {
            if (name.length == 0)
                continue;
            capitalizeNext = YES;
            c = '_';
        }
        [name appendFormat:@"%c", c];
    }
    return name;
}

NSString *RXEPropertyNameFromString(NSString *str)
{
    NSString *name;
    return name;
}

NSString *RXEMethodNameFromString(NSString *str)
{
    NSString *name;
    return name;
}

Protocol *RXEExportProtocolForClassName(NSString *className)
{
    Protocol *ExportProtocol;
    Protocol *JSExportProtocol;
    const char *exportProtocolName;

    exportProtocolName = [className stringByAppendingString:@"Exports"].UTF8String;
    ExportProtocol = objc_allocateProtocol(exportProtocolName);

    JSExportProtocol = objc_getProtocol("JSExport");
    protocol_addProtocol(ExportProtocol, JSExportProtocol);

    return ExportProtocol;
}
