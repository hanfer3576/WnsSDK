//
//  WnsWtLoginProtocol.h
//  WnsSDK
//
//  Created by astorli on 7/17/15.
//  Copyright (c) 2015 Tencent. All rights reserved.
//

#ifndef WnsSDK_WnsWtLoginProtocol_h
#define WnsSDK_WnsWtLoginProtocol_h

#import "WnsLoginProtocol.h"

typedef NS_ENUM(NSUInteger, WnsWtLoginSigType)
{
    WnsWtLoginSigTypeA2    = 0x40,
    WnsWtLoginSigTypeST    = 0x80,
    WnsWtLoginSigTypeSKEY  = 0x1000,
    WnsWtLoginSigTypeVKEY  = 0x20000,
    WnsWtLoginSigTypeSTWEB = 0x20,
};

@class WloginSdk_v2;

@protocol WnsWtLoginProtocol <WnsLoginProtocol, WnsAutoLoginProtocol>

- (WloginSdk_v2 *)getWtloginSdk;

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

/**
 *  刷新验证码
 */
- (void)refreshVerifyCode;

/**
 *  提交验证码
 *
 *  @param verifyCode 对应的验证码
 *
 *  @return 本地函数执行是否成功,不过此接口会有网络操作,不能确定最终是否成功
 */
- (int)submitVerifyCode:(NSString *)verifyCode;

/**
 *  刷新wtlogin票据，仅在当前有登录账号且没有在进行其它登录操作时才有效
 *
 *  @param sigBitmap 支持WnsWtLoginSigType类型参数或
 *
 *  @return 本地函数执行是否成功,不过此接口会有网络操作,不能确定最终是否成功
 */
- (int)refreshWloginSig:(NSUInteger)sigBitmap;

/**
 *  获取已登录过的用户的信息
 *
 * @param dwBitmap:支持WnsWtLoginSigType类型参数或 eg: WnsWtLoginSigTypeSKEY | WnsWtLoginSigTypeVKEY
 *
 * @return 返回字典结构类似：{"uin1":{"uin":"uin1", "account":"account1", "VKEY":"vkey1", **}, **}
 */
- (NSDictionary *)getAllUserLoginInfo:(NSUInteger)dwBitmap;

/**
 *  从wtlogin获取上次登录用户
 *
 *  @note 不包括快速登录和sso登录
 */
- (NSString *)lastLoginUser;

/**
 *  判断票据是否有效,该接口不能用于判断WnsSDKWtloginSigTypeST是否有效
 *
 *  @param sigType WnsSDKWtloginSigType
 *  @param account 用户账户
 *
 *  @return 票据是否有效
 */
- (BOOL)isSigValid:(WnsSDKWtloginSigType)sigType account:(NSString *)account;

/**
 *  设置拉取头像的类别
 *
 *  @param wFaceImgType取值范围为1~5，如果请求包中取值非法，则server端默认返回cImgType=1 对应的头像url。
 *          取值和分辨率关系如下：
 *          40*40静态   = 1
 *          40*40动态gif = 2
 *          100*100   = 3 <不区分动静态>
 *          140*140   = 4 <不区分动静态>
 *          高清原图  = 5 <不区分动静态>
 */
- (void)setFaceImgType:(uint16_t)wFaceImgType;

////////////////////////////////////////////////
// 以下是快速登陆调用方(微云,电台,K歌等)需要使用的函数
////////////////////////////////////////////////

/**
 *  判断是否可以使用快速登陆,快速登陆发起方调用的第①步
 *
 *  @return 是否可以使用快速登陆
 */
- (BOOL)canQuickLoginWithScheme:(NSString *)scheme;

/**
 *  使用指定的scheme进行快速登陆, 快速登陆发起方的第②步
 *
 *  @param scheme 从快速登陆实现方(手Q/空间)进行返回时用的scheme
 *  @param useApp 选择使用哪个快速登陆实现方(手Q/空间)
 *
 *  @return  YES                             不表示快速登录成功完成了，仅表示满足快速登录的条件，且开始了快速登录的流程
 *           NO                              失败（因为不满足快速登录的条件）
 */
- (BOOL)quickLoginWithScheme:(NSString *)scheme useApp:(WnsSDKQuickLoginUseApp)useApp;

/**
 *  使用指定的信息进行快速登陆, 快速登陆发起方的第③步
 *
 *  @param loginInfo 登陆信息, 必须得有WnsLoginInfoTypeQuickLoginUrl类型的信息
 *  @param delegate  登陆结果回调
 *
 *  @return 登陆过程是否成功,但不代表最后的结果
 */
- (int)quickLoginWithAPP:(NSDictionary *)loginInfo delegate:(id)delegate;

/**
 * 构造业务快速登录页面的广告图片
 * userAccount 手Q当前登录帐号
 * bundleID    跳转目标APP的bundle id
 * 返回三个信息：
 * IconUrl: "http://imgcache.qq.com/wtlogin/app/com/tencent/mqq/icon.png"
 * AdImgUrl: "http://imgcache.qq.com/wtlogin/app/com/tencent/mqq/ad_img.png"
 * ProfileUrl "http://imgcache.qq.com/wtlogin/test/com/tencent/mqq/profile.js"
 */
- (NSDictionary *)getQuickLoginAdUrl:(NSString *)userAccount andBundleID:(NSString*)bundleID;

////////////////////////////////////////////////
// 以下是快速登陆实现方(比如QQ空间)需要使用的函数
////////////////////////////////////////////////

/**
 *  当前状态是否可以让别人通过本app快速登陆
 */
- (BOOL)canQuickLogin;

/**
 *  "主动"快速登陆(比如微云呼起空间进行快速登陆,空间调用此函数重新呼起微云,或者是空间主动打开水印相机的场景)
 */
- (int)quickLogin:(void(^)(NSURL*))block
         DstAppid:(uint32_t)dwDstAppid
      DstSubAppid:(uint32_t)dwDstSubAppid
DstSourceApplication:(NSString *)DstSourceApplication
        DstScheme:(NSString *)DstScheme
     LoginTimeout:(NSTimeInterval)timeout
LoginTimeoutScheme:(NSString *)timeoutScheme;
@end

@protocol WnsWtLoginResultDelegate <WnsLoginResultDelegate>
@optional
//需要用户输入密码才能登录
- (void)inputPassword;

//需要输入验证码
- (void)needVerifyCode:(NSData *)verifyCode andWording:(NSDictionary *)wordingDic;
@end

@class WloginUserInfo;

@interface WnsWtLoginUserInfo : NSObject <NSCopying, NSCoding>

@property(nonatomic, assign)    uint32_t dwUserUin;             //用户QQ号码
@property(nonatomic, copy)      NSString *sUserMainAccount;     //主显帐号
@property(nonatomic, assign)    uint16_t wFaceId;               //头像id，使用逻辑可以登录oidb.server.com上查看
@property(nonatomic, assign)    uint8_t cAge;                   //年龄
@property(nonatomic, assign)    uint8_t cGender;                //性别，0 未知， 1 男， 2 女
@property(nonatomic, copy)      NSString *sNickName;            //昵称

@property (nonatomic, copy) NSString *sFaceUrl;
@property (nonatomic, retain) NSData *quickLoginData;

- (id)initWithWtloginUserInfo:(WloginUserInfo *)wtloginUserInfo;

@end

#endif
