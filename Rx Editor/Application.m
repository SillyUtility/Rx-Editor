//
//  Application.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/16/21.
//  Copyright © 2021 Silly Utility LLC. All rights reserved.
//

#import <ScriptingBridge/ScriptingBridge.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <Carbon/Carbon.h>
#import <SillyLog/SillyLog.h>

#import "RXESDefParser.h"
#import "RXEScriptableApp.h"
#import "RXEScriptSuite.h"
#import "RXEScriptClass.h"
#import "RXEScriptCommand.h"
#import "RXEScriptTypes.h"

#import "RXERuntimeController.h"
#import "RXERuntimeObject.h"
#import "Application.h"

@implementation Application {
    id _app;
    NSBundle *_bundle;
    RXEScriptableApp *_scriptableApp;
}

- initWithIdentifier:(NSString *)ident
{
    NSURL *url;
    OSAError err;
    CFDataRef scriptingDefinitionData;
    Class AppClass;

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

    SLYTrace(@"currentContext %@", JSContext.currentContext);
    AppClass = [RXERuntimeController
        exportScriptableApp:_scriptableApp
        appInstance:self
        context:JSContext.currentContext
    ];

    self = [[AppClass alloc] initWithBridgeObject:_app];
    SLYTrace(@"%@.version = %@", self, [self valueForKey:@"version"]);

    return self;
}

@end
