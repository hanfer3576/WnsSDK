//
//  WnsLoginDelegate.h
//  WnsSDK
//
//  Created by Wenbin on 12-7-4.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "WnsCommonDefine.h"

//@class WloginUserInfo;
@class LoginUserInfo;
@class QzoneLoginUserInfo;

/***********************************************************************/
// Wns 的登录回调协议声明
//
/***********************************************************************/

@protocol NewWnsLoginDelegate <NSObject>
@optional

//成功登录，info里有用户信息
- (void)loginSucceed:(NSDictionary *)info account:(QzoneLoginUserInfo *)userInfo;   // 空间
- (void)loginSucceed:(WnsSDKLoginType)accType resInfo:(NSDictionary *)resInfo;      // 自研

//登录失败，info是code与desc的键值对
- (void)loginFailed:(NSDictionary *)info account:(NSString *)account;               // 空间
- (void)loginFailed:(NSDictionary *)info reqInfo:(NSDictionary *)reqInfo;           // 自研

//需要用户输入密码才能登录
- (void)inputPassword;

//需要输入验证码
- (void)needVerifyCode:(NSData *)verifyCode andWording:(NSDictionary *)wordingDic;

//A2更新的结果返回
- (void)updateA2Return:(NSDictionary *)retInfo account:(NSString *)uin;

@end




@interface QzoneLoginUserInfo : NSObject <NSCopying, NSCoding>
{
}
@property(nonatomic, assign)    uint32_t dwUserUin;             //用户QQ号码
@property(nonatomic, copy)      NSString *sUserMainAccount;     //主显帐号
@property(nonatomic, assign)    uint16_t wFaceId;               //头像id，使用逻辑可以登录oidb.server.com上查看
@property(nonatomic, assign)    uint8_t cAge;                   //年龄
@property(nonatomic, assign)    uint8_t cGender;                //性别，0 未知， 1 男， 2 女 
@property(nonatomic, copy)      NSString *sNickName;            //昵称

- (id)initWithloginUserInfo:(LoginUserInfo *)loginUserInfo;

@end


//@protocol WnsQuickLoginDelegate <NSObject>
//
//@optional
//
//- (void)quickLoginEnd:(NSURL *)url;
//
//@end

