//
//  BaseRequest.h
//  BYHttpNetworking_OC
//
//  Created by 侯博野 on 2018/7/1.
//  Copyright © 2018 satelens. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetworkCommon.h"
#import "RequestCallBack.h"

extern NSString * const NetworkDomain; ///< 请求网络域名,即你后台服务器的域名,譬如：https://www.baidu.com，后面不拼接任何路径参数的，这样子的就不是域名https://www.baidu.com/info

@interface BaseRequest : NSObject

@property (nonatomic, weak) id<BaseRequestDelegate> delegate;

@property (nonatomic, copy) AFConstructingBodyBlock constructingBodyBlock;
@property (nonatomic, copy) AFURLSessionTaskProgressBlock resumableDownloadProgressBlock;
@property (nonatomic, copy) AFURLSessionTaskProgressBlock uploadProgressBlock;

@property (nonatomic, copy) RequestSuccessBlock successBlock;
@property (nonatomic, copy) RequestFailureBlock failureBlock;

- (instancetype)initWithSuccessBlock:(RequestSuccessBlock)successBlock
                        failureBlock:(RequestFailureBlock)failureBlock;
+ (instancetype)requestWithSuccessBlock:(RequestSuccessBlock)successBlock
                           failureBlock:(RequestFailureBlock)failureBlock;

- (void)startCompletionBlockWithSuccess:(RequestSuccessBlock)success
                                failure:(RequestFailureBlock)failure;

/**
 带进度的图片上传
 
 @param success 成功回调
 @param failure 失败回调
 @param uploadProgress 进度回调
 */
- (void)startUploadTaskWithSuccess:(RequestSuccessBlock)success
                           failure:(RequestFailureBlock)failure
                    uploadProgress:(AFURLSessionTaskProgressBlock)uploadProgress;

/**
 * @brief 公共方法，开始请求，不管是使用 block 回调还是 delegate 回调，都要调用此方法
 */
- (void)startRequest;

/**
 * @brief 请求参数，即URL入参
 *
 * @warning 必须重写
 */
- (NSDictionary *)requestArguments;

/**
 * @brief 请求URL路径
 *
 * @warning 必须重写
 */
- (NSString *)requestURLPath;

/**
 * @brief 请求方式 GET or POST
 *
 * @warning 按需重写
 */
- (RequestMethod)requestMethod; ///< 默认 GET 请求

/**
 * @brief 请求序列类型
 *
 * @warning 按需重写
 */
- (RequestSerializerType)requestSerializerType;

/**
 * @brief 响应序列类型
 *
 * @warning 按需重写
 */
- (ResponseSerializerType)responseSerializerType;

/**
 * @brief 设置请求头
 *
 * @warning 按需重写
 */
- (NSDictionary<NSString *, NSString *> *)requestHeaderFieldValueDictionary; ///< Additional HTTP request header field. HTTP 请求头配置，按需重写

/**
 * 处理请求返回的数据，字典转模型，利用 Mantle
 *
 * @param data 需要的数据
 * @param resCode 后台返回的错误码（代表各种情况）
 */
- (void)handleData:(id)data errCode:(NSInteger)resCode;

@end
