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

#import "RXESDefParser.h"
#import "RXEScriptableApp.h"

#import "Application.h"

@implementation Application {
    id _app;
    NSBundle *_bundle;
    RXEScriptableApp *_scriptableApp;
}

- (instancetype)initWithIdentifier:(NSString *)ident
{
    NSURL *url;
    OSAError err;
    CFDataRef scriptingDefinitionData;

    SLYTraceCall();

    if (!(self = [super init]))
        return self;

    url = [NSWorkspace.sharedWorkspace
        URLForApplicationWithBundleIdentifier:ident];
    _bundle = [NSBundle bundleWithURL:url];
    if (!_bundle) {
        SLYError(@"Application %@ not found", ident);
        return nil;
    }
    _name = _bundle.infoDictionary[(__bridge NSString *)kCFBundleNameKey];

    _app = [SBApplication applicationWithBundleIdentifier:ident];
    if (!_app) {
        SLYError(@"Application %@ not scriptable", ident);
        return nil;
    }

    err = OSACopyScriptingDefinitionFromURL(
        (__bridge CFURLRef)_bundle.bundleURL,
        0,
        &scriptingDefinitionData
    );
    if (err != noErr) {
        SLYError(@"Unable to read scripting definition for %@ ", ident);
        return nil;
    }

    _scriptableApp = [[RXEScriptableApp alloc]
        initWithName:_name
        scriptingDefinition:scriptingDefinitionData
    ];

    [self exportScriptableAttributes];

    return self;
}

- (void)exportScriptableAttributes
{
    SLYTrace(@"_scriptableApp %@", _scriptableApp);
    SLYTrace(@"_scriptableApp.suites %@", _scriptableApp.suites);
}

@end
