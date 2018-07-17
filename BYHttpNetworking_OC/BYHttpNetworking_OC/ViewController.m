//
//  ViewController.m
//  BYHttpNetworking_OC
//
//  Created by 侯博野 on 2018/7/1.
//  Copyright © 2018 satelens. All rights reserved.
//

#import "ViewController.h"
#import "ManagerTest.h"
#import "TestGetRequest.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    [ManagerTest testUrl];
    TestGetRequest *req = [TestGetRequest requestWithSuccessBlock:^(NSInteger errCode, NSDictionary *responseDict, id model) {
        NSLog(@"%@", responseDict);
    } failureBlock:^(NSError *error) {
        NSLog(@"%@", error);
    }];
    [req startRequest];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
