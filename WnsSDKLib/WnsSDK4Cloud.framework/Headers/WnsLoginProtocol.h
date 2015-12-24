//
//  WnsLoginProtocol.h
//  WnsSDK
//
//  Created by astorli on 7/14/15.
//  Copyright (c) 2015 Tencent. All rights reserved.
//

#ifndef WnsSDK_WnsLoginProtocols_h
#define WnsSDK_WnsLoginProtocols_h

#include "WnsCommonDefine.h"

#pragma mark - 相关枚举定义

typedef NS_ENUM(NSInteger, WnsSDKQuickLoginUseApp)
{
    WnsSDKQuickLoginUseAppMobileQQ = 1,     // 使用手Q快速登录
    WnsSDKQuickLoginUseAppQzone    = 3,     // 使用QZone快速登录 5.1.1.1以后版本支持
};

typedef NS_ENUM(NSInteger, WnsSDKWtloginSigType)
{
    WnsSDKWtloginSigTypeA2    = 0x40,
    WnsSDKWtloginSigTypeST    = 0x80,
    WnsSDKWtloginSigTypeSKEY  = 0x1000,
    WnsSDKWtloginSigTypeVKEY  = 0x20000,
    WnsSDKWtloginSigTypeSTWEB = 0x20,
    WnsSDKWtloginSigTypePSKEY = 0x100000,
};

@protocol WnsLoginResultDelegate;

#pragma mark - 登陆管理器的接口的协议,可以通过不同的协议访问不同管理器中的方法

@protocol WnsLoginProtocol <NSObject>
- (int)loginWithInfo:(NSDictionary *)loginInfo delegate:(id<WnsLoginResultDelegate>)delegate;

/**
 *  获取用户登陆状态
 *
 *  @note 应用启动后通过该接口获取登陆状态，若返回WnsSDKLoginStateOnline(所有必需票据本地检测有效 加密票据/鉴权票据)，不需要再调用登录接口，可以调用autoLoginWithAccount进行自动登陆;
 */
- (WnsSDKLoginState)getUserLoginState:(NSString *)uid;

/**
 *  获取当前登录账号的信息
 *
 *  @param type 登录成功或设置登录账号后才可以取到信息
 *
 *  @return 对应的登陆信息,如果没有则为nil
 */
- (id)getLoginInfo:(WnsSDKLoginInfoType)type;

/**
 *  重置登陆状态,登录流程中途取消时需要调用，用于清除内部状态
 */
- (void)resetLogin;

/**
 *  @brief 清除缓存的用户信息
 */
- (void)clearLoginInfo:(NSString *)uid;

/**
 *  登出
 */
- (void)logout;

@end

@protocol WnsAutoLoginProtocol <NSObject>
- (int)autoLoginWithAccount:(NSString *)account;
@end

#pragma mark - 登陆结果的委托

@protocol WnsLoginResultDelegate <NSObject>
@optional
- (void)loginSucceed:(WnsSDKLoginType)accType resInfo:(NSDictionary *)resInfo;
- (void)loginFailed:(NSDictionary *)info reqInfo:(NSDictionary *)reqInfo;

- (void)logoutSuccess;
- (void)logoutFail:(NSDictionary *)info;
@end

#endif
