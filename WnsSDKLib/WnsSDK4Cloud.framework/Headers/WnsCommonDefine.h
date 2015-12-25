//
//  WnsCommonDefine.h
//  WnsSDK
//
//  Created by best1a on 8/31/15.
//  Copyright (c) 2015 Tencent. All rights reserved.
//

#ifndef WnsSDK_WnsCommonDefine_h
#define WnsSDK_WnsCommonDefine_h

#pragma mark - 相关枚举定义

// WnsSDK通道状态
typedef NS_ENUM(NSInteger, WnsSDKStatus) {
    WnsSDKStatusDisconnected    = 0,    //WnsSDK通道不可用
    WnsSDKStatusConnecting      = 1,    //WnsSDK通道建立中 过程包括网络连接、握手包(Handshake)、加密包(B2)
    WnsSDKStatusConnected       = 2,    //WnsSDK通道建立成功
};

// LOG等级
typedef NS_ENUM(NSInteger, WnsSDKLogLevel) {
    WnsSDKLogLevelDisabled      = -1,
    WnsSDKLogLevelError         = 0,
    WnsSDKLogLevelWarn          = 1,
    WnsSDKLogLevelInfo          = 2,
    WnsSDKLogLevelDebug         = 3,
    WnsSDKLogLevelTrace         = 4,
    WnsSDKLogLevelMax           = 5,
};

// 运营商类型
typedef NS_ENUM(NSInteger, WnsSDKCarrierType) {
    WnsSDKCarrierTypeUnknown        = 0,
    WnsSDKCarrierTypeMobile         = 1,
    WnsSDKCarrierTypeUnicom         = 2,
    WnsSDKCarrierTypeTelecom        = 3,
    WnsSDKCarrierTypeTietong        = 4
};

// APP类型
typedef NS_ENUM(NSInteger, WnsSDKAppType) {
    WnsSDKAppTypeQzone              = 0,    // qzone
    WnsSDKAppTypeInner              = 1,    // sng内部应用
    WnsSDKAppTypeQQMusic            = 2,    // QQ音乐
    WnsSDKAppTypeThirdParty         = 3     // 第三方开发商使用
};

typedef NS_ENUM(NSInteger, WnsSDKLoginType) {
    WnsSDKLoginTypeNoAuth      = 0,
    WnsSDKLoginTypeWtlogin     = 1,
    WnsSDKLoginTypeOAuthWeChat = 2,
    WnsSDKLoginTypeOAuthQQ     = 3,
    WnsSDKLoginTypeAnonymous   = 4,
    WnsSDKLoginTypeWid         = 5,
};

typedef NS_ENUM(NSInteger, WnsSDKLoginState)
{
    WnsSDKLoginStateOffline,       // 没有登录
    WnsSDKLoginStateOnline,        // 登录成功
    WnsSDKLoginStateLogining,      // 登录中
    WnsSDKLoginStateLogouting,     // 登出中
    WnsSDKLoginStateTokenExpired,  // 本地票据过期
    WnsSDKLoginStateNonlogin       // 无登录态透传
};

typedef NS_ENUM(NSInteger, WnsSDKLoginInfoType)
{
    WnsSDKLoginInfoTypeLoginType              = 0,// WnsLoginType
    WnsSDKLoginInfoTypeLoginState             = 1,// WnsLoginState
    WnsSDKLoginInfoTypeUin                    = 2,// uin
    WnsSDKLoginInfoTypeUid                    = 3,// user id
    WnsSDKLoginInfoTypeSuid                   = 4,// 设备id
    WnsSDKLoginInfoTypePwd                    = 5,//NSString or NSData(md5), wtlogin
    WnsSDKLoginInfoTypeIsMd5                  = 6,//BOOL, wtlogin
    WnsSDKLoginInfoTypeRememberPwd            = 7,//BOOL, wtlogin
    WnsSDKLoginInfoTypeAutoLogin              = 8,//BOOL, wtlogin
    WnsSDKLoginInfoTypeForceVerifyPwd         = 9,//BOOL, wtlogin
    WnsSDKLoginInfoTypeBitmap                 = 10,//uint32_t  eSigType, 指定获取的wtlogin票据类型
    WnsSDKLoginInfoTypeQuickLoginUrl          = 11,//NSURL, wtlogin
    WnsSDKLoginInfoTypeAccount                = 12,//NSString, wtlogin user account, such as qq, phone number, email
    WnsSDKLoginInfoTypeCode                   = 13,//NSString, wechat oauth
    WnsSDKLoginInfoTypeOpenid                 = 14,//NSString, qq oauth
    WnsSDKLoginInfoTypeRefreshToken           = 15,//NSString, qq oauth
    WnsSDKLoginInfoTypeRefreshTokenGenDate    = 16,//NSDate, qq oauth
    WnsSDKLoginInfoTypeRefreshTokenExpireDate = 17,//NSDate, qq oauth
    WnsSDKLoginInfoTypeIsRegister             = 18,//uint32_t
    WnsSDKLoginInfoTypeExtra                  = 19,//NSData, 业务数据，wns只做透传
    WnsSDKLoginInfoTypeQmfToken               = 20,
    WnsSDKLoginInfoTypeLoginUserInfo          = 21,//从wtlogin获取的账号信息
    WnsSDKLoginInfoTypeA2                     = 22,
    WnsSDKLoginInfoTypeST                     = 23,
    WnsSDKLoginInfoTypeSKEY                   = 24,
    WnsSDKLoginInfoTypeVKEY                   = 25,
    WnsSDKLoginInfoTypeSTWEB                  = 26,
    WnsSDKLoginInfoTypeSTKey                  = 27,
    WnsSDKLoginInfoTypeEncA2                  = 28,
    WnsSDKLoginInfoTypeB2                     = 29,
    WnsSDKLoginInfoTypeB2Key                  = 30,
    WnsSDKLoginInfoTypeTinyIDA2               = 31,
    
    // UserInfo
    //    WnsSDKLoginInfoTypeUserInfoNickname,
    //    WnsSDKLoginInfoTypeUserInfoSex,
    //    WnsSDKLoginInfoTypeUserInfoCountry,
    //    WnsSDKLoginInfoTypeUserInfoProvince,
    //    WnsSDKLoginInfoTypeUserInfoCity,
    //    WnsSDKLoginInfoTypeUserInfoLogo,
    //    WnsSDKLoginInfoTypeUserInfoIsClosed,
};

//push注册场景
typedef enum {
    WnsSDKPushRegisterSceneUnknown = 0,         //未知
    WnsSDKPushRegisterSceneLogin,               //登录
    WnsSDKPushRegisterSceneParameterChanged,    //参数变化
    WnsSDKPushRegisterSceneQuickLogin           //快速登录
} WnsSDKPushRegisterScene;

#pragma mark - 结构参数定义

@interface WnsAppInfo : NSObject
@property(nonatomic, assign)    NSInteger   appId;
@property(nonatomic, retain)    NSString    *appName;
@property(nonatomic, retain)    NSString    *appVersion;
@property(nonatomic, retain)    NSString    *qua;
@property(nonatomic, retain)    NSString    *releaseVersion;
@property(nonatomic, retain)    NSString    *deviceInfo;
@property(nonatomic, assign)    WnsSDKAppType   appType;
@end

#endif
