//
//  TuTaoDeviceViewController.m
//  Demo
//
//  Created by Tm on 2017/12/26.
//  Copyright © 2017年 Tim. All rights reserved.
//

#import "TuTaoDeviceViewController.h"
#import <TuTaoSDK/UIColor+TuUI.h>
#import <TuTaoSDK/TuTaoDeviceInfo.h>
#import <TuTaoSDK/TuTaoUITextView.h>
#import <TuTaoSDK/TuTaoUICommonDefines.h>

@interface TuTaoDeviceViewController ()

@property (nonatomic, strong) TuTaoUITextView *textView;

@end

@implementation TuTaoDeviceViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = UIColorMakeWithHex(@"#3AC063");
    
    self.textView = [[TuTaoUITextView alloc] initWithFrame:CGRectMake(0, 0, <#CGFloat width#>, <#CGFloat height#>)]
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
