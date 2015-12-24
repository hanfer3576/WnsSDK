//
//  WnsSdkHelper.h
//  WnsSDK
//
//  Created by Wenbin on 12-7-4.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#ifndef __WnsSDK__NewWnsSdkHelper__
#define __WnsSDK__NewWnsSdkHelper__

#import <Foundation/Foundation.h>

#import "NewWnsSdkNotification.h"
#import "NewWnsLoginDelegate.h"
#import "NewWnsBizDelegate.h"
#import "NewWnsBizData.h"
#import "WnsCommonDefine.h"
#import "QzoneWnsDefine.h"

@class WloginSdk_v2;

#pragma mark - NewWnsSdkHelper (WNS SDK主接口定义)

/***********************************************************************/
// WnsSdkHelper
//
/***********************************************************************/

@interface NewWnsSdkHelper : NSObject
{
    
}


#pragma mark 基础接口

/*! @brief WnsSdkHelper 的单例
 *
 */

+ (NewWnsSdkHelper *)sharedInstance;

/*! @brief 设置APP信息
 *
 * @note 需要在使用其他接口之前调用
 * @param appId, 业务在WNS注册的业务ID
 * @param appName, 业务在WNS注册的业务名称
 * @param appVersion, 业务版本号
 * @param qua, 业务版本的QUA
 * @param releaseVersion, 发布版本号
 * @return
 */

//- (void)setAppInfo:(int)appId appName:(NSString *)appName appVersion:(NSString *)appVersion qua:(NSString *)qua releaseVersion:(NSString *)releaseVersion;

/*! @brief 设置app信息的新接口
 */
- (void)setAppInfo:(WnsAppInfo*)appInfo;

/*! @brief 从WNS获取一个全局唯一的请求序列号
 *
 * @return 返回生成的新seqno
 */

//+ (long)generateSeqNo;

#pragma mark 登录接口

- (WloginSdk_v2 *)getWtloginSdk;

/*! @brief 设置当前登录帐号（用于不需要调用登录时  wns层不再保存上次登录帐号，依赖于上层传入）
 *
 *  @note 不需要登录时必须调用这个接口设置帐号
 */
- (void)setLoginAccount:(NSString *)account;
- (void)setCurUid:(NSString *)uid;

- (int)loginWithInfo:(NSDictionary *)loginInfo Delegate:(id<NewWnsLoginDelegate>)delegate;

/*! @brief 用密码md5登录
 *
 */
- (int)loginWithPasswordMD5:(NSString *)account passwordMD5:(NSData *)passwordMD5 forceVerifyPwd:(BOOL)forceVerifyPwd delegate:(id<NewWnsLoginDelegate>)delegate;

/**
 *  添加skey域名,在登陆前调用
 *
 *  @param domain 域名,不含前面的http://
 */
- (BOOL)addSKeyDomain:(NSString *)domain;

/*! @brief 获得对应域名的pskey或者super skey,元素类型为WnsMemSig
 *
 *  @note 登录流程后调用
 */
- (NSArray *)getSKeyByDomain:(NSString *)domain;

/*! @brief 重置登录
 *
 *  @note 登录流程中途取消时需要调用，用于清除内部状态
 */
- (void)resetLogin;

/*! @brief 刷新验证码
 *
 */
- (void)refreshVerifyCode;

/*! @brief 提交验证码
 *
 */
- (void)submitVerifyCode:(NSString *)userInput;

/*! @brief 退出登录
 *
 */
- (void)logout;

/*! @brief 清除票据信息
 *
 */
- (void)clearUserLoginData:(NSString *)account;

/*! @brief 票据是否有效
 *
 */
- (BOOL)isSigValid:(NewWnsSigType)sigType uid:(NSString *)uid;

/*! @brief 设置拉取头像的类别
 *
 *  @note 只对wtlogin登录方式有效
 *  @param wFaceImgType取值范围为1~5，如果请求包中取值非法，则server端默认返回cImgType=1 对应的头像url。
 *          取值和分辨率关系如下：
 *          40*40静态   = 1
 *          40*40动态gif = 2
 *          100*100   = 3 <不区分动静态>
 *          140*140   = 4 <不区分动静态>
 *          高清原图  = 5 <不区分动静态>
 */
-(void)setFaceImgType:(uint16_t)wFaceImgType;

/*! @brief 获取票据
 *
 */
- (NSData *)getSigByType:(AllSigType)sigType;


/*! @brief 续票
 *
 *  @note A2未过期期间可以调用这个接口刷新所有票据
 */
- (void)renewAllSig;
//@param sigmap：支持eSigType类型参数或
- (void)renewSig:(uint32_t)sigmap;


/*! @brief 取当前登录的account
 *
 */
- (NSString *)getCurrentAccount;

/*! @brief 用户是否已经成功登陆
 *
 *  @note 应用启动后可以通过该接口判断是否成功登录，若返回yes(所有必需票据本地检测有效 A2/B2)，不需要再调用登录接口
 */
- (BOOL)isUserLogin:(NSString *)account;

/*! @brief 获取已登录过的用户的信息
 *
 * @note 
 * @param dwBitmap:支持eSigType类型参数或 eg:WnsSigType_SKEY | WnsSigType_VKEY
 * @return 返回字典结构类似：{"uin1":{"uin":"uin1", "account":"account1", "VKEY":"vkey1", **}, **}
 */
//- (NSDictionary *)getAllUserLoginInfo:(uint32_t)dwBitmap;

/*! @brief 获取当前登录账号的信息
 *
 *  @note 登录成功或设置登录账号后才可以取到信息
 */
- (id)getLoginResInfoKey:(WnsSDKLoginInfoType)type;

/*! @brief 从wtlogin获取记住密码接口, 上次登录用户
 *
 *  @note 不包括快速登录和sso登录
 */
- (NSString *)lastWtLoginUser;

/*! @brief 设置当前登录账户类型,设置后将会清除上一种类型的登录状态
 *
 * @note 必须在登录,透传前调用
 */
- (void)setLoginAccType:(WnsSDKLoginType)loginAccType;

/*! @brief 获取用户登陆状态
 *
 *  @note 应用启动后通过该接口获取登陆状态，若返回WnsLoginStateOnline(所有必需票据本地检测有效 加密票据/鉴权票据)，不需要再调用登录接口，需要调用setCurUid设置账号;
 */
- (WnsSDKLoginState)getUserLoginState:(NSString *)uid;

#pragma mark 透传接口

/*! @brief 透传发送业务请求数据
 *
 * @param bizData 见WnsBizSendData定义
 * @return 返回标识请求的SeqNo
 */
- (int)sendBizData:(NewWnsBizSendData *)bizData;

/*! @brief 取消指定的业务请求
 *
 * @param seqNo 指定业务请求的序列号
 */
- (void)cancelRequest:(int)seqNo;

#pragma mark Push接口

/*! @brief 离线Push设置
 *
 * @param deviceToken 苹果设备的device token
 * @param enablePush 是否接受push, YES表示接受，NO表示不接受
 * @param disableDetail push时是否展示详情, YES表示展示，NO表示不展示
 * @param pushTemplate iOS8 push category, 允许nil
 * @param delegate WnsDeviceTokenDelegate对象, 用于处理push设置的回调
 * @return
 */
-(void)setDeviceToken:(NSString *)deviceToken
           enablePush:(BOOL)enablePush
        disableDetail:(BOOL)disableDetail
         pushTemplate:(NSString *)pushTemplate
             delegate:(id<WnsDeviceTokenDelegate>)delegate;

-(void)setDeviceToken:(NSString *)deviceToken
           enablePush:(BOOL)enablePush
        disableDetail:(BOOL)disableDetail
                scene:(WnsSDKPushRegisterScene)scene
         pushTemplate:(NSString *)pushTemplate
             delegate:(id<WnsDeviceTokenDelegate>)delegate;

- (void)cancelDeviceTokenReq;

/*! @brief 注册push通知
 *
 * @param delegate WnsPushDelegate对象，用来接收push触发的消息
 * @param remove NO表示注册，YES表示移除注册
 * @return
 */

- (void)registerPushReceiver:(id<WnsPushDelegate>)delegate remove:(BOOL)remove;

#pragma mark log接口

/*! @brief 设置log级别,数值越大越详细
 *
 * @param level 见QZLogLevel定义
 * @return
 */

- (void)setLogLevel:(int)level;

/*! @brief 设置wtlogin的日志级别
 *
 */
- (void)setWloginLogLevel:(int)level;

/*! @brief 强制日志刷新写回
 * @note 建议在检测到程序即将退出时调用一下
 */
- (void)flushLog;

/*! @brief 主动上报本地的log
 *
 */
//- (void)uploadLog:(uint64_t)uin;

/*! @brief 主动上报本地的log
 *
 */
- (void)uploadLogWithConfig:(NSDictionary *)config;

- (NSString *)showLogFile;

- (NSMutableArray *)showAllLogFileName;

- (NSString *)showLogCachePath;

#pragma mark 配置接口

/*! @brief 拉取配置
 *
 */
- (void)getConfig:(id<WnsConfigDelegate>)delegate;

/*! @brief 设置Wns Config的delegate
 *
 */
- (void)regWnsConfigDelegate:(id<WnsConfigDelegate>)delegate;

/*! @brief 设置本地保存的cookie
 *
 */
- (void)setConfigCookie:(NSString*)cookie;

#pragma mark 开发环境设置

/*! @brief 设置开发环境，设置是否仅使用HTTP协议
 *
 * @param useTestIp YES使用开发环境IP，NO使用外网环境
 * @param testIp 开发环境IP，在useTestIp为YES时有效
 * @param httpOnly YES使用强制WNS透传数据时使用HTTP协议，NO不强制
 *
 * @note 设置完开发环境和协议，须调用resetWnsConnection接口
 */
- (void)setTestIp:(BOOL)useTestIp testIp:(NSString *)testIp port:(ushort)port httpOnly:(BOOL)httpOnly;

/*! @brief 设置开发环境IP
 *
 * @param useTestIp YES使用开发环境IP，NO使用外网环境
 * @param testIp 开发环境IP，在useTestIp为YES时有效
 */
-(void)setTestIp:(BOOL)useTestIp testIp:(NSString *)testIp port:(ushort)port;

/*! @brief 设置是否仅使用HTTP协议
 *
 * @param httpOnly YES使用强制WNS透传数据时使用HTTP协议，NO不强制
 */
- (void)setHttpOnly:(BOOL)only;

///*! @brief 设置Location IP
// *
// */
//- (void)setLocationIp:(NSString *)testIp;

/*! @brief 设置wtlogin的测试服务器
 *
 */
- (void)setWtloginServer:(NSString *)address port:(int)port;

/*! @brief 记日志
 *
 *  @param module 模块区分，日志里展示为[M:module]
 *  @param extDict 日志里展示为[key:value]...
 */
- (void)log:(int)level file:(const char *)file func:(const char *)func line:(int)line module:(NSString*)module EFDict:(NSDictionary *)extDict msg:(NSString *)fmt, ...;

- (void)log:(int)level file:(const char *)file func:(const char *)func line:(int)line module:(NSString*)module EFDict:(NSDictionary *)extDict fullmsg:(NSString *)fullmsg;

#pragma mark 统计上报

/*! @brief 上报数据(按配置值来采样)
 *  @param 传参:请求命令字，详细返回码，用户uin，耗时（ms），请求包大小，应答包大小，序列号
 */
- (void)reportData:(NSString *)cmd
               ret:(NSInteger)ret
               uin:(int64_t)uin
            tmcost:(NSInteger)tmcost
           reqsize:(NSInteger)reqszie
           rspsize:(NSInteger)rspsize
        sdkversion:(NSString *)sdkversion
               seq:(NSString *)seq
          serverip:(NSString *)serverip
              port:(NSInteger)port
            detail:(NSString *)detail
             dtype:(NSInteger)dtype
          odetails:(NSString*)odetails
      busiserverip:(NSString *)busiserverip;

/*! @brief 上报数据(全量)
 *  @param 传参:请求命令字，详细返回码，用户uin，耗时（ms），请求包大小，应答包大小，序列号
 */
- (void)reportDataAll:(NSString *)cmd
                  ret:(NSInteger)ret
                  uin:(int64_t)uin
               tmcost:(NSInteger)tmcost
              reqsize:(NSInteger)reqszie
              rspsize:(NSInteger)rspsize
           sdkversion:(NSString *)sdkversion
                  seq:(NSString *)seq
             serverip:(NSString *)serverip
                 port:(NSInteger)port
               detail:(NSString *)detail
                dtype:(NSInteger)dtype
             odetails:(NSString*)odetails
         busiserverip:(NSString *)busiserverip;

/*! @brief 上报H5数据(按配置值来采样)
 *  @param 传参:url，详细返回码，用户uin，耗时（ms)，详情
 */
- (void)reportH5Data:(NSString *)url
               ret:(int)ret
               uin:(int64_t)uin
            tmcost:(int)tmcost
            detail:(NSString *)detail;

/*! @brief 上报H5数据(全量)
 *  @param 传参:url，详细返回码，用户uin，耗时（ms)，详情
 */
- (void)reportH5DataAll:(NSString *)url
                  ret:(int)ret
                  uin:(int64_t)uin
               tmcost:(int)tmcost
               detail:(NSString *)detail;

#pragma mark wns网络连接

/*! @brief 开始启动wns连接
 *
 */
- (void)startWnsConnection;

/*! @brief 重置wns连接
 *
 * @param reconnect YES先关掉现有WNS连接再重新连接，NO只关掉现有WNS连接
 */
- (void)resetWnsConnection:(BOOL)reconnect;

/*! @brief ip测速
 *
 */
- (void)ipSpeedTest:(int32_t)succInterval failInterval:(int32_t)failInterval;

/*! @brief 图片视频等大数据上传开始时，通知WNS
 *
 */
- (void)startTransferData;

/*! @brief 图片视频等大数据上传停止或完成时，通知WNS
 *
 */
- (void)stopTransferData;

/*! @brief 获取当前wifi的运营商信息
 *
 * @note 不保证一定能取到，取不到则返回未知类型
 * @return 返回值见WnsCarrierType定义
 */
- (WnsSDKCarrierType)getWnsCarrierType;

/*! @brief 根据指定的wifi bssid, 获取此wifi所属的运营商信息
 *
 * @note 不保证一定能取到，取不到则返回未知类型
 * @return 返回值见WnsCarrierType定义
 */
- (WnsSDKCarrierType)getWifiCarrierType:(NSString *)bssid;

#pragma mark 其他

/*! @brief 设置设备信息
 *
 */
-(void)setDeviceInfo:(NSString *)deviceInfo;

/*! @brief 设置程序状态
 *
 */
- (void)setApplicationState:(WnsApplicationState)state;

///*! @brief 注册心跳回调
// *
// */
//- (void)registerHeartBeatDelegate:(id<WnsHeartBeatDelegate>)delegate;

/*! @brief 获取指定seqno请求的处理信息
 *
 * @param seqNo     请求的seqno
 * @param tlvIndex  如果是请求的tlv模式，tlvindex为分片index, 否则填0
 * @return 返回字典中各键的含义:
 command             (NSString类型)
 uin                 (NSNumber类型,转成long long)
 costtime            (NSNumber类型,转成float)        //从发送到请求完成的时间
 requestsize         (NSNumber类型,转成int)          //请求包大小
 responsesize        (NSNumber类型,转成int)          //回包大小
 ip                  (NSString类型 ip地址)           //发往哪个IP
 port                (NSNumber类型,转成int，端口)     //发往哪个端口
 sendtime            (NSNumber类型,转成float)        //发送时间
 recvtime            (NSNumber类型,转成float)        //接收时间
 queuetime           (NSNumber类型,转成float)        //排队时间
 totalnetworktime    (NSNumber类型,转成float)        //总的网络上的消耗时间
 totaltime           (NSNumber类型,转成float)        //请求从入队到收到完成的总时间
 */

-(NSDictionary * )getRequestInfo:(long)seqNo tlvIndex:(int)tlvIndex;

/*! @brief 获取网络异常时需要诊断的IP列表
 *
 */
- (NSArray *)getDetectIPArray;

/*! @brief 获取mms默认值
 *
 */
-(int)getSocketMaxSeg1;
-(int)getSocketMaxSeg2;
-(int)getSocketMaxSeg3;

- (void)notifyReceiveSilentPush;

- (void)setCommonReportInfo:(NSDictionary *)info;

+ (void)synchronizeLoginInfoToOldFormat;

#pragma mark - quickLogin

/*! @brief 通过wns登录态获取票据,需要wns有登录态且不处于登录登出换票流程中
 *
 */
- (BOOL)canQuickLogin;

- (void)quickLogin:(void(^)(NSURL*))block
          DstAppid:(uint32_t)dwDstAppid
       DstSubAppid:(uint32_t)dwDstSubAppid
DstSourceApplication:(NSString *)DstSourceApplication
         DstScheme:(NSString *)DstScheme
      LoginTimeout:(NSTimeInterval)timeout
LoginTimeoutScheme:(NSString *)timeoutScheme;


/*! @brief 是否可以通过手Q/微信获取票据
 *
 *  @param scheme 本app的URL Scheme
 *  @return
 */
-(BOOL)canQuickLoginWithAPP:(NSString *)scheme;

/*! @brief 通过手Q/微信获取票据
 *
 *  @param scheme 本app的URL Scheme
 *  @return YES-不表示快速登录成功完成了，仅表示满足快速登录的条件，且开始了快速登录的流程
 *          NO-失败（因为不满足快速登录的条件）
 */
-(BOOL)quickLogin:(NSString *)scheme useApp:(NEWWNS_QUICKLOGIN_USEAPP)useApp;

/*! @brief 处理快速登录结果，需要wns不处于登录登出换票流程中
 *
 *  @param url 快速登录处理方传给发起方的url
 *  @return WNS_SDK_SUCCESS-不表示登录成功完成了，仅表示满足登录的条件，且开始了登录的流程，登录结果通过WnsLoginDelegate回调
 */
- (int)quickLoginWithAPP:(NSURL *)url delegate:(id)delegate;

-(NSDictionary*)getQuickLoginAdUrl:(NSString *)userAccount andBundleID:(NSString*)bundleID;

/*! @brief 票据
 *
 * @note 请注意一定要区分于SKEY
 */
- (NSData *)getSTKey;

//**********************************
#pragma mark Deprecated

/*! @brief 是否需要清空缓存
 必须在启动时执行，在显示内容之前
 */
-(BOOL)needClearCacheWhenLauch;

/*! @brief 增加crash次数计数
 */
-(void)incCrashCount;

-(BOOL)connectionAvailable;

#pragma mark - wifi auth
- (void)startWifiAuth;
@end

#endif //__WNSSDKHELPER_H__
