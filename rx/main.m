//
//  main.m
//  rx
//
//  Interactive Rx interpreter for the CLI and Emacs comint-mode.
//
//  Created by Eddie Hillenbrand on 3/9/22.
//  Copyright © 2022 Silly Utility LLC. All rights reserved.
//

#import <AppKit/AppKit.h>

#define SLY_AUTORELEASEPOOL_BEGIN @autoreleasepool {
#define SLY_AUTORELEASEPOOL_END }

int main(int argc, const char * argv[]) {
    SLY_AUTORELEASEPOOL_BEGIN

    NSURL *url;
    url = [NSWorkspace.sharedWorkspace
        URLForApplicationWithBundleIdentifier:@"com.apple.Finder"];
    NSLog(@"Hello %@", url);

    SLY_AUTORELEASEPOOL_END
    return 0;
}
