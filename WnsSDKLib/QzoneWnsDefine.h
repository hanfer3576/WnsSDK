//
//  QzoneWnsDefine.h
//  WnsSDK
//
//  Created by jackozhang on 15/8/25.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#ifndef WnsSDK_QzoneWnsDefine_h
#define WnsSDK_QzoneWnsDefine_h


//错误信息dictionary中的key
#define  SDKCODE   "sdkcode"   //错误码(int型)
#define  SDKDESC   "sdkdesc"   //错误描述(NSString *型)
#define  WNSCODE   "wnscode"   //WNS后台返回码(int型)
#define  WNSDESC   "wnsdesc"   //WNS后台的错误描述(NSString *型)
#define  BIZCODE   "bizcode"   //业务返回码(int型)
#define  BIZDESC   "bizdesc"   //业务返回描述(NSString *)
#define  BIZTLVINDEX "biztlvindex"  //正在处理的tlv分片

//白名单限制dictionary中的key
#define  kQUA_FORBIDDEN_WNSCODE @"WNSCODE"
#define  kQUA_FORBIDDEN_ERRMSG  @"ERRMSG"
#define  kQUA_FORBIDDEN_APPURL  @"APPURL"


//请求处理状态
//typedef enum
//{
//    SendDataStatu_Waiting,      //等待中
//    SendDataStatu_Connecting,   //连接中
//    SendDataStatu_Sending,      //发送中
//    SendDataStatu_Recving,      //收取数据中
//    SendDataStatu_Finish,       //收到数据
//} eSendDataStatus;

//WNS SDK网络状态CODE
//typedef enum
//{
//    WNSSDKNetStatus_NoAvailable = 0x00, //连接不可用
//    WNSSDKNetStatus_RecvNormal,         //接受数据完成
//    WNSSDKNetStatus_Available,          //收取中
//    WNSSDKNetStatus_Connecting          //连接中
//} WNSSDKNetStatus;

//SDK 返回码
//typedef enum
//{
//    WNSSDK_SUCCESS                     = 0,
//    
//    //WTLOGIN错误base
//    WNSSDK_WTLOGIN_BASE                = -300,  //wtlogin错误基数,wtogin的报告值都从这里往上加，因wtlgin的错误值都在0~255间，因此小于-300都属于wtlogin的值
//    
//    //一般错误:10000开始
//    WNSSDK_TIMEOUT                     = -601, //超时
//    WNSSDK_NO_NETWORK                  = -602, //网络不可用
//    WNSSDK_NEED_LOGIN                  = -603, //需要登录
//    WNSSDK_NETWORK_ERROR               = -605, //网络错误
//    WNSSDK_CONN_TIMEOUT                = -620,  //连接超时
//    WNSSDK_SEND_TIMEOUT                = -621,  //发送超时
//    WNSSDK_RECV_TIMEOUT                = -622,  //接收超时
//    WNSSDK_SESSION_FAIL_1              = -631,  //连接session失败(前台)
//    WNSSDK_SESSION_FAIL_2              = -632,  //连接session失败(后台)
//    
//    //WTLOGIN错误:11000开始
//    WNSSDK_WTLOGIN_PASSWORD            = -703, //密码错误
//    WNSSDK_WTLOGIN_NETWORK             = -704, //网络错误
//    WNSSDK_WTLOGIN_INTERNAL            = -705, //wtlogin内部错误
//    
//    WNSSDK_WNS_NO_BUSIDATA             = -807,  //业务无数据返回
//    WNSSDK_WNS_DISCONNECT              = -808,    //发送成功，连接断掉
//    WNSSDK_WNS_REQUEST_CANCEL          = -809, //外部业务请求被取消
//    WNSSDK_WNS_ACCDIS_CODE_RETRYNOW    = -810,  //告知客户端马上重试(acc&&dispatch)
//    WNSSDK_WEBAPP_CODE_NO_OVERLOAD     = -812,// 告诉客户端后端过载
//    WNSSDK_WNS_TLV_DECRYPT_FAIL        = -813,  //TLV解密失败
//    
//    WNSSDK_WNS_WEBAPP_CODE_NORETRY     = -5069,  //告知客户端不要重试了 （3.6版本使用-811）
//} WNS_SDK_CODE;


//拉取配置的场景
//typedef enum {
//    Config_SceneAppRun,            //APP启动
//    Config_SceneAppActivate,       //APP激活
//    Config_SceneTimeout,           //定时触发
//    Config_SceneNetworkChanged     //网络变化
//}CONFIG_SCENE;

// 应用程序状态
typedef enum {
    WnsApplicationState_Foreground = 0,        // 前台
    WnsApplicationState_Background,            // 后台
    WnsApplicationState_Suspend,               // 挂起
    WnsApplicationState_SuspendToFore,         // 挂起之后回到前台
    WnsApplicationState_WnsStop                // Wns内部停止，也不再去连接等
} WnsApplicationState;


//票据类型,传给renewSig函数用，可以多个一起或
typedef enum
{
    NewWnsSigType_A2       = 0x40,
    NewWnsSigType_ST       = 0x80,
    NewWnsSigType_SKEY     = 0x1000,
    NewWnsSigType_VKEY     = 0x20000,
    NewWnsSigType_PSKEY    = 0x100000,
} NewWnsSigType;

typedef enum
{
    SigType_A2       = 0x40,
    SigType_ST       = 0x80,
    SigType_SKEY     = 0x1000,
    SigType_VKEY     = 0x20000,
    SigType_B2       = 0x13,
    SigType_B2Key    = 0x14,
    SigType_EncA2    = 0x15
}AllSigType;



//请求的优先级
typedef enum
{
    NewWnsReqPriority_L1 = 1, //highest
    NewWnsReqPriority_L2,
    NewWnsReqPriority_L3,
    NewWnsReqPriority_L4,
    NewWnsReqPriority_L5
} NewWnsReqPriority;


typedef enum{
    NEWWNS_QUICKLOGIN_USE_MOBILEQQ = 1,  //使用手Q快速登录
    NEWWNS_QUICKLOGIN_USE_WEIXIN   = 2,  //使用微信快速登录
} NEWWNS_QUICKLOGIN_USEAPP;

typedef enum
{
    NewWnsLoginRes_LoginAccType,
    NewWnsLoginRes_Uid,
    NewWnsLoginRes_IsRegister,
    NewWnsLoginRes_B2,
    NewWnsLoginRes_B2Key,
    NewWnsLoginRes_Openid,
    NewWnsLoginRes_RefreshToken,
    NewWnsLoginRes_ExpireTime,
    NewWnsLoginRes_GenerateTime,
    NewWnsLoginRes_QmfToken,
    NewWnsLoginRes_Extra = 10,          //登录时的业务数据，wns只做透传，不缓存
    NewWnsLoginRes_LoginUserInfo = 11,  //从wtlogin获取的账号信息
    NewWnsLoginRes_A2      = 0x40,
    NewWnsLoginRes_ST      = 0x80,
    NewWnsLoginRes_SKEY    = 0x1000,
    NewWnsLoginRes_VKEY    = 0x20000,
    NewWnsLoginRes_STWEB   = 0x20,
    NewWnsLoginRes_STKey   = 0x100,
    NewWnsLoginRes_EncA2,
    NewWnsLoginRes_ErrorInfo,          //登录成功时返回errorInfo，业务可以处理特殊的bizcode(只随成功回调返回)
    NewWnsLoginRes_AnonymousUid        //匿名id，业务可以不关心
} NewWnsLoginResType;

#endif
