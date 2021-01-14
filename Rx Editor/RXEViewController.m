//
//  RXEViewController.m
//  Rx Editor
//
//  Created by Eddie Hillenbrand on 1/9/21.
//


#import <ScriptingBridge/ScriptingBridge.h>
#import <OSAKit/OSAKit.h>
#import <objc/runtime.h>

#import "RXEViewController.h"

@interface RXEViewController ()
@property (strong) IBOutlet OSAScriptController *scriptController;
@property (unsafe_unretained) IBOutlet OSAScriptView *scriptView;
@property (unsafe_unretained) IBOutlet NSTextView *resultsView;
@end

@implementation RXEViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    // Do any additional setup after loading the view.
}


- (void)setRepresentedObject:(id)representedObject
{
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
