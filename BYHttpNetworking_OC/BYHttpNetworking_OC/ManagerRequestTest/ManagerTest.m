//
//  ManagerTest.m
//  BYHttpNetworking_OC
//
//  Created by 侯博野 on 2018/7/17.
//  Copyright © 2018 satelens. All rights reserved.
//

#import "ManagerTest.h"
#import "NetworkManager.h"

@implementation ManagerTest

+ (void)testUrl {
    
    [[NetworkManager sharedManager] GETUrl:@"https://httpbin.org/get" parameters:nil success:^(id responseObject) {
        NSLog(@"%@", responseObject);
    } failure:^(NSError *error, ParamtersJudgeCode judgeCode) {
        NSLog(@"%@----%lu", error, (unsigned long)judgeCode);
    }];
}

@end
