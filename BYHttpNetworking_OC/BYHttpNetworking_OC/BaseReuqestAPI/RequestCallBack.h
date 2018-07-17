//
//  RequestCallBack.h
//  BYHttpNetworking_OC
//
//  Created by 侯博野 on 2018/7/1.
//  Copyright © 2018 satelens. All rights reserved.
//

#import <Foundation/Foundation.h>
@class BaseRequest;

@protocol AFMultipartFormData;

typedef void(^AFConstructingBodyBlock)(id<AFMultipartFormData> data);
typedef void(^AFURLSessionTaskProgressBlock)(NSProgress *progress);


/*!
 *   AFN 请求封装的Block回调
 */
typedef void(^RequestSuccessBlock)(NSInteger errCode, NSDictionary *responseDict, id model);
typedef void(^RequestFailureBlock)(NSError *error);


/*!
 *   AFN 请求封装的代理回调
 */
@protocol BaseRequestDelegate <NSObject>

@optional
/**
 *   请求结束
 *   @param returnData 返回的数据
 */
- (void)requestDidFinishLoadingWithData:(id)returnData errCode:(NSInteger)errCode;

/**
 *   请求失败
 *   @param error 失败的 error
 */
- (void)requestDidFailWithError:(NSError *)error;

/**
 *   网络请求项即将被移除掉
 *   @param item 网络请求项
 */
- (void)requestWillDealloc:(BaseRequest *)item;
@end
