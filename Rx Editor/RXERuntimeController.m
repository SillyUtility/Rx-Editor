//
//  RXERuntimeController.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 2/2/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <JavaScriptCore/JavaScriptCore.h>
#import <SillyLog/SillyLog.h>
#import "RXERuntimeController.h"
#import "RXEScriptableApp.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"
#import "Application.h"

@implementation RXERuntimeController {
    JSContext *_context;
}

- init
{
    SLYTraceCall();

    if (!(self = [super init]))
        return self;

    _context = [[JSContext alloc] init];
    [self exportFundamentalClasses];

    return self;
}

- (JSContext *)JSContext
{
    return _context;
}

- (void)exportFundamentalClasses
{
    _context[@"Application"] = Application.class;
}

+ (void)exportScriptableApp:(RXEScriptableApp *)sapp
    appInstance:(Application *)app
    context:(JSContext *)ctx
{
    SLYTrace(@"_scriptableApp %@", sapp);
    SLYTrace(@"_scriptableApp.suites %@", sapp.suites);
    for (id suite in sapp.suites)
        SLYTrace(@" classes %@", [suite classes]);
}

@end
