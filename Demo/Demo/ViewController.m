//
//  ViewController.m
//  Demo
//
//  Created by Tm on 2017/12/26.
//  Copyright © 2017年 Tim. All rights reserved.
//

#import "ViewController.h"
#import "TuTaoExample.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    TuTaoExample *vc = [[TuTaoExample alloc] init];
    [self pushViewController:vc animated:NO];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
