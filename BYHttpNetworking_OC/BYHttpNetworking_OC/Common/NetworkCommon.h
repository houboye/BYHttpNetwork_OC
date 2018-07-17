//
//  NetworkCommon.h
//  BYHttpNetworking_OC
//
//  Created by 侯博野 on 2018/7/1.
//  Copyright © 2018 satelens. All rights reserved.
//

#ifndef NetworkCommon_h
#define NetworkCommon_h

///< 参数检查
typedef NS_ENUM(NSUInteger, ParamtersJudgeCode) {
    RequestUrlNil          = 11,
    ParamtersObjectNil     = 12,
    UploadPictureDataNil   = 13,
    UploadPictureKeyNil    = 14,
    UploadFailed           = 15,
    RequestFailed          = 16,
};

///< HTTP Request method.
typedef NS_ENUM(NSInteger, RequestMethod) {
    RequestMethodGET = 0,
    RequestMethodPOST,
    RequestMethodPUT,
    RequestMethodDELETE
};

///< Request serializer type.
typedef NS_ENUM(NSInteger, RequestSerializerType) {
    RequestSerializerTypeHTTP = 0,
    RequestSerializerTypeJSON
};

///< Response serializer type, which determines response serialization process and
///  the type of `responseObject`.
typedef NS_ENUM(NSInteger, ResponseSerializerType) {
    ResponseSerializerTypeHTTP = 0, ///< NSData
    ResponseSerializerTypeJSON, ///< JSON
    ResponseSerializerTypeXMLParser ///< NSXMLParser
};

#endif /* NetworkCommon_h */
