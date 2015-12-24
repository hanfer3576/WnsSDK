//
//  WnsOAuthLoginProtocol.h
//  WnsSDK
//
//  Created by astorli on 7/17/15.
//  Copyright (c) 2015 Tencent. All rights reserved.
//

#ifndef WnsSDK_WnsOAuthLoginProtocol_h
#define WnsSDK_WnsOAuthLoginProtocol_h

#import "WnsLoginProtocol.h"

@protocol WnsOAuthLoginProtocol <WnsLoginProtocol, WnsAutoLoginProtocol>

/**
 *  注册成功后设置uid
 *
 *  @note 注册成功后必须调用且只能用于注册成功，否则wns不会缓存票据信息
 */
- (void)setOAuthProfileUid:(NSString *)uid;
@end

#endif
