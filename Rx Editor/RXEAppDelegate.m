//
//  RXEAppDelegate.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/9/21.
//

#import <SillyLog/SillyLog.h>
#import "RXEAppDelegate.h"

@interface RXEAppDelegate ()

@end

@implementation RXEAppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    SLYTrace(@"dlyd framework path = %@", NSProcessInfo.processInfo.environment[@"DYLD_FRAMEWORK_PATH"]);
}


- (void)applicationWillTerminate:(NSNotification *)aNotification
{
    // Insert code here to tear down your application
}


@end
