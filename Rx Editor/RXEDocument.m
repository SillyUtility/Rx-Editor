//
//  RXEDocument.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/9/21.
//

#import <ScriptingBridge/ScriptingBridge.h>
#import <objc/runtime.h>

#import <Carbon/Carbon.h>

#import "RXEDocument.h"
#import "RXESDefParser.h"

@interface RXEDocument ()

@end

@implementation RXEDocument

- (instancetype)init
{
    self = [super init];
    if (self) {
        // Add your subclass-specific initialization here.
        id app = [SBApplication applicationWithBundleIdentifier:@"com.apple.finder"];
        NSLog(@"app %@", app);

        Class klass = object_getClass(app);
        NSLog(@"Class %@", NSStringFromClass(klass));

//        Method *methods;
//        unsigned int methodCount = 0;
//
//        methods = class_copyMethodList(klass, &methodCount);
//        NSLog(@"method count %u", methodCount);
//
//        for (int i = 0; i < methodCount; i++)
//            NSLog(@"method %s", sel_getName(method_getName(methods[i])));


//        Class *classList;
//        unsigned int classCount = 0;
//
//        classList = objc_copyClassList(&classCount);
//        for (int i = 0; i < classCount; i++)
//            NSLog(@"Class %@", NSStringFromClass(classList[i]));


        NSLog(@"app.windows %@", [app windows]);


        id app1 = [SBApplication applicationWithBundleIdentifier:@"com.apple.finder"];
        NSLog(@"app1.get %@", [app1 get]);

        NSAppleEventDescriptor *desc = [NSAppleEventDescriptor descriptorWithBundleIdentifier:@"com.apple.finder"];
        NSLog(@"appdesc %@", desc);
        NSLog(@"appdesc.numberOfItems %@", @(desc.numberOfItems));


//        NSScriptSuiteRegistry *reg = NSScriptSuiteRegistry.new;
//        [reg loadSuitesFromBundle:[NSBundle bundleWithIdentifier:@"com.apple.finder"]];
//        NSLog(@"finder suites %@", [reg suiteNames]);
//        NSLog(@"finder core suite classes %@", [reg classDescriptionsInSuite:@"NSCoreSuite"]);

        //NSLog(@"%@", NSScriptSuiteRegistry.sharedScriptSuiteRegistry.suiteNames);


        OSAError err;
        CFDataRef sdefData;
        NSBundle *bundle;

        bundle = [NSBundle bundleWithIdentifier:@"com.apple.finder"];
        err = OSACopyScriptingDefinitionFromURL((__bridge CFURLRef)bundle.bundleURL, 0, &sdefData);

        NSLog(@"data %@", (__bridge id)sdefData);

        RXESDefParser *parser = [[RXESDefParser alloc] initWithData:(__bridge id)sdefData];
        [parser parse];
    }
    return self;
}

+ (BOOL)autosavesInPlace
{
    return YES;
}


- (void)makeWindowControllers
{
    // Override to return the Storyboard file name of the document.
    [self addWindowController:[[NSStoryboard storyboardWithName:@"Main" bundle:nil] instantiateControllerWithIdentifier:@"Document Window Controller"]];
}


- (NSData *)dataOfType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to write your document to data of the specified type. If outError != NULL, ensure that you create and set an appropriate error if you return nil.
    // Alternatively, you could remove this method and override -fileWrapperOfType:error:, -writeToURL:ofType:error:, or -writeToURL:ofType:forSaveOperation:originalContentsURL:error: instead.
    [NSException raise:@"UnimplementedMethod" format:@"%@ is unimplemented", NSStringFromSelector(_cmd)];
    return nil;
}


- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to read your document from the given data of the specified type. If outError != NULL, ensure that you create and set an appropriate error if you return NO.
    // Alternatively, you could remove this method and override -readFromFileWrapper:ofType:error: or -readFromURL:ofType:error: instead.
    // If you do, you should also override -isEntireFileLoaded to return NO if the contents are lazily loaded.
    [NSException raise:@"UnimplementedMethod" format:@"%@ is unimplemented", NSStringFromSelector(_cmd)];
    return YES;
}


@end
