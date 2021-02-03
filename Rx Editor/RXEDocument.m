//
//  RXEDocument.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/9/21.
//

#import <ScriptingBridge/ScriptingBridge.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <Carbon/Carbon.h>
#import <objc/runtime.h>
#import <SillyLog/SillyLog.h>

#import "RXEDocument.h"
#import "RXESDefParser.h"
#import "RXERuntimeController.h"

#import "Application.h"

@interface RXEDocument ()

@end

@implementation RXEDocument {
    RXERuntimeController *_runtimeController;
}

- init
{
    SLYTraceCall();

    if (!(self = [super init]))
        return self;

    _runtimeController = [[RXERuntimeController alloc] init];
    _runtimeController.JSContext.name = @"RXEDocument Context";

    return self;
}

+ (BOOL)autosavesInPlace
{
    return YES;
}


- (void)makeWindowControllers
{
    // Override to return the Storyboard file name of the document.
    [self addWindowController:[[NSStoryboard storyboardWithName:@"Main" bundle:nil]
        instantiateControllerWithIdentifier:@"Document Window Controller"]];
}


- (NSData *)dataOfType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to write your document to data of the
    // specified type. If outError != NULL, ensure that you create and
    // set an appropriate error if you return nil.

    // Alternatively, you could remove this method and override
    // -fileWrapperOfType:error:, -writeToURL:ofType:error:, or
    // -writeToURL:ofType:forSaveOperation:originalContentsURL:error:
    // instead.
    [NSException raise:@"UnimplementedMethod"
        format:@"%@ is unimplemented", NSStringFromSelector(_cmd)];

    return nil;
}


- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to read your document from the given data of
    // the specified type. If outError != NULL, ensure that you create
    // and set an appropriate error if you return NO.

    // Alternatively, you could remove this method and override
    // -readFromFileWrapper:ofType:error: or
    // -readFromURL:ofType:error: instead.

    // If you do, you should also override -isEntireFileLoaded to
    // return NO if the contents are lazily loaded.
    [NSException raise:@"UnimplementedMethod"
        format:@"%@ is unimplemented", NSStringFromSelector(_cmd)];

    return YES;
}


@end
