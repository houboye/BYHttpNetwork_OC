//
//  TestGetRequest.m
//  BYHttpNetworking_OC
//
//  Created by 侯博野 on 2018/7/17.
//  Copyright © 2018 satelens. All rights reserved.
//

#import "TestGetRequest.h"

@implementation TestGetRequest


- (RequestMethod)requestMethod {
    return RequestMethodGET;
}

- (NSString *)requestURLPath {
    return @"/get";
}

- (NSDictionary *)requestArguments {
    return nil;
}

- (void)handleData:(id)data errCode:(NSInteger)errCode {
    NSDictionary *dict = (NSDictionary *)data;
    
    if (errCode == 0) {
        ///< 方式1：block 回调
        if (self.successBlock) {
            self.successBlock(errCode, dict, dict);
        }
        
        ///< 方式2：代理回调
        if (self.delegate && [self.delegate respondsToSelector:@selector(requestDidFinishLoadingWithData:errCode:)]) {
            [self.delegate requestDidFinishLoadingWithData:dict errCode:errCode];
        }
    }
    else {
        ///< block 回调
        if (self.successBlock) {
            self.successBlock(errCode, dict, nil);
        }
        
        ///< 代理回调
        if (self.delegate && [self.delegate respondsToSelector:@selector(requestDidFinishLoadingWithData:errCode:)]) {
            [self.delegate requestDidFinishLoadingWithData:data errCode:errCode];
        }
    }
}

@end
