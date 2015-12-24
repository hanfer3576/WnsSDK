//
//  WnsBizData
//  WnsBizSendData      - 业务透传给SDK请求的发包数据
//  WnsBizRecvData      - SDK透传给业务请求的回包数据
//
//  Created by allenlin on 2013-03.
//  Copyright (c) 2013年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QzoneWnsDefine.h"
//#import "WnsDefine.h"

@protocol NewWnsTransferDelegate;

#pragma mark - WnsRetryInfo

#define WNS_BIZ_RETRY_COUNT_DEFAULT 1

@interface NewWnsBizRetryInfo : NSObject<NSCoding>
{
    UInt8       _flag;
    UInt16      _retryCount;
    SInt64      _pkgId;
    NSString    *_detail;
}

@property(nonatomic, assign)    UInt8       flag;
@property(nonatomic, assign)    UInt16      retryCount;
@property(nonatomic, assign)    SInt64      pkgId;
@property(nonatomic, strong)    NSString    *detail;

+ (id)infoWith:(UInt8)flag rcount:(UInt16)rcount pkgid:(SInt64)pkgid detail:(NSString *)detail;

@end

#pragma mark - WnsBizSendData

@interface NewWnsBizSendData : NSObject

@property(nonatomic, strong) NSData*            data;
@property(nonatomic, strong) NSString*          command;
@property(nonatomic, assign) NSUInteger         timeout;
//@property(nonatomic, weak) id<NewWnsTransferDelegate>                 bizDelegate; 共存两套SDK时,需要暂时把属性改为strong
@property(nonatomic, strong) id<NewWnsTransferDelegate>                 bizDelegate;
@property(nonatomic, assign) BOOL               canRecvTLV;
@property(nonatomic, strong) NewWnsBizRetryInfo*   retryInfo;
@property(nonatomic, assign) NSUInteger         retryCnt;
@property(nonatomic, assign) NewWnsReqPriority        priority;
@property(nonatomic, assign)  BOOL               busiBufUpFlag;                         // 上行包是否加压
@property(nonatomic, assign)  BOOL               busiBufDownFlag;                       // 是否支持下行包加压


+ (id)dataWith:(NSData*)data command:(NSString*)command timeout:(NSUInteger)timeout delegate:(id)delegate;
+ (id)dataWith:(NSData*)data command:(NSString*)command timeout:(NSUInteger)timeout delegate:(id)delegate priority:(NewWnsReqPriority)priority;

@end

#pragma mark - WnsBizRecvData

@interface NewWnsBizRecvData : NSObject

@property(nonatomic, strong) NSData*            data;
@property(nonatomic, assign) long               seqno;
@property(nonatomic, assign) BOOL               isTlvMode;
@property(nonatomic, assign) BOOL               isFirst;            //仅TLV mode有效
@property(nonatomic, assign) BOOL               isFinish;           //仅TLV mode有效
@property(nonatomic, assign) int                tlvIndex;           // tlv分片从1开始
@property(nonatomic, strong) NSString*          webappIp;           // 该请求对应的webapp server的ip
@property(nonatomic, assign) int                webappChangeTime;   // 该请求对应的webapp server的变更时间

+ (id)dataWithBytes:(NSData*)data seqno:(long)seqno isTlvMode:(BOOL)isTlvMode isFirst:(BOOL)isFirst isFinish:(BOOL)isFinish webappIp:(NSString *)webappIp webappChangeTime:(int)webappChangeTime;

@end

