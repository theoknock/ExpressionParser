//
//  ViewController.m
//  ToneBarrier
//
//  Created by James Bush on 6/30/20.
//

#import "ViewController.h"
#include "score.h"
#include "split.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self args];
}

- (void)args
{
    char expression[] = "%time * %frequency * %amplitude";
    unsigned int args_count = count_args(expression);
    char ** args = parse_args(expression, args_count);

    for (int i = 0; i < args_count; i++)
    {
        printf("Array item: [%s]\n", args[i]);
    }
}

@end
