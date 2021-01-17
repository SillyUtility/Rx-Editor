//
//  Application.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/16/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <ScriptingBridge/ScriptingBridge.h>
#import <Carbon/Carbon.h>
#import <SillyLog/SillyLog.h>

#import "Application.h"

@implementation Application {
    NSBundle *_bundle;
    id _app;
}

- (instancetype)initWithIdentifier:(NSString *)ident
{
    OSAError err;
    CFDataRef scriptingDefinitionData;

    SLYTraceCall();

    if (!(self = [super init]))
        return self;

    _app = [SBApplication applicationWithBundleIdentifier:ident];
    SLYTrace(@"_app %@ %@", ident, _app);

    _bundle = [NSBundle bundleWithIdentifier:ident];
    SLYTrace(@"bundle %@ %@", ident, _bundle);
    SLYTrace(@"infoDict %@", _bundle.infoDictionary);

    _name = _bundle.infoDictionary[(__bridge NSString *)kCFBundleNameKey];

    err = OSACopyScriptingDefinitionFromURL((__bridge CFURLRef)_bundle.bundleURL, 0, &scriptingDefinitionData);

    NSLog(@"data %@", (__bridge id)scriptingDefinitionData);


    return self;
}

@end
