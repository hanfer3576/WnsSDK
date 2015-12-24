//
//  WnsBizDelegate.h
//  Wns 的业务回调协议声明
//
//  Created by Wenbin on 12-7-4.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QzoneWnsDefine.h"

@class NewWnsBizRecvData;


#pragma mark - 业务请求透传回调

/***********************************************************************/
// Wns 的业务请求透传回调事件
//
/***********************************************************************/
@protocol NewWnsTransferDelegate <NSObject>

//数据透传成功，收到数据
- (void)didReceviedData:(NewWnsBizRecvData*)data;

//数据透传成功，收到数据, 同时有上面和这个回调时, 只会调用这个
- (void)didReceviedData:(NewWnsBizRecvData*)data errorInfo:(NSDictionary *)info;

//数据透传失败
- (void)didSendDataFail:(NSDictionary *)info seqno:(id)seqno;

//数据透传处理超时
- (void)didSendDataTimeout:(id)seqno;

//发送状态通知
- (void)didSendDataStatus:(id)status seqno:(id)seqno;

//是否重传请求
- (BOOL)didRetry:(NSDictionary *)info seqno:(id)seqno;

@end

#pragma mark - Push回调

/***********************************************************************/
// Wns 的push接收回调事件
//
/***********************************************************************/
@protocol WnsPushDelegate <NSObject>

- (void)didPushArrived:(NSData *)data;

@end

#pragma mark - Token设置回调

/***********************************************************************/
// Wns 的设置Device Token回调
//
/***********************************************************************/
@protocol WnsDeviceTokenDelegate<NSObject>

- (void)didSetDeviceToken:(BOOL)setOk;

@end

#pragma mark - 配置回调
/***********************************************************************/
// Wns 的配置回调
//
/***********************************************************************/
@protocol WnsConfigDelegate<NSObject>

/*! @brief 取配置成功的回调
 *
 * @note 需要把config转成map<string,vector<char> >*的类型，vector<char>里为一个wup::UniAttribute<>
 *       业务需要解出里边一个个键值对，解析完后需要析构掉config
 */
- (void)didGetConfigSuccess:(id)config;

- (void)didGetConfigFail:(NSString *)cookie info:(NSDictionary *)info;

- (void)didGetConfigDataSuccess:(NSDictionary *)config;

@optional
//业务提供需要解的key，由wns解出键值对  不实现则返回所有的key
- (NSArray *)extendDataKeys;

- (NSArray *)extendDataSubKeysForKey:(NSString *)key;

@end

#pragma mark - 心跳回调

/***********************************************************************/
// Wns 的配置回调
//
/***********************************************************************/
@protocol WnsHeartBeatDelegate <NSObject>
@optional

- (void)didHeartBeatEvent;

@end

