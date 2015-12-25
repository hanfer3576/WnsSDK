//
//  WnsWidLoginProtocol.h
//  WnsSDK
//
//  Created by astorli on 7/17/15.
//  Copyright (c) 2015 Tencent. All rights reserved.
//

#ifndef WnsSDK_WnsWidLoginProtocol_h
#define WnsSDK_WnsWidLoginProtocol_h

#import "WnsLoginProtocol.h"

@protocol WnsWidLoginProtocol <WnsLoginProtocol>
- (void)bind:(NSString *)uid completion:(void(^)(NSError *error))completion;
- (void)unbind:(NSString *)uid completion:(void(^)(NSError *error))completion;
- (int64_t)wid;
@end

#endif
