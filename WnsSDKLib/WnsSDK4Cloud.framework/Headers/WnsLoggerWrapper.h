//
//  WnsLoggerWrapper.h
//  WnsSDK
//
//  Created by astorli on 7/13/15.
//  Copyright (c) 2015 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "WnsCommonDefine.h"

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_TRACE(...)   \
[[WnsLoggerWrapper sharedInstance] log:WnsSDKLogLevelTrace file:__FILENAME__ func:__FUNCTION__ line:__LINE__ module:@"WNS" fmt:__VA_ARGS__]

#define LOG_DEBUG(...)   \
[[WnsLoggerWrapper sharedInstance] log:WnsSDKLogLevelDebug file:__FILENAME__ func:__FUNCTION__ line:__LINE__ module:@"WNS" fmt:__VA_ARGS__]

#define LOG_INFO(...)    \
[[WnsLoggerWrapper sharedInstance] log:WnsSDKLogLevelInfo file:__FILENAME__ func:__FUNCTION__ line:__LINE__ module:@"WNS" fmt:__VA_ARGS__]

#define LOG_WARN(...)    \
[[WnsLoggerWrapper sharedInstance] log:WnsSDKLogLevelWarn file:__FILENAME__ func:__FUNCTION__ line:__LINE__ module:@"WNS" fmt:__VA_ARGS__]

#define LOG_ERROR(...)   \
[[WnsLoggerWrapper sharedInstance] log:WnsSDKLogLevelError file:__FILENAME__ func:__FUNCTION__ line:__LINE__ module:@"WNS" fmt:__VA_ARGS__]

#define LLOG_DEBUG(...)   \
[[WnsLoggerWrapper sharedInstance] log:WnsSDKLogLevelDebug file:__FILENAME__ func:__FUNCTION__ line:__LINE__ module:@"WNS" fmt:__VA_ARGS__]




@interface WnsLoggerWrapper : NSObject

+ (instancetype)sharedInstance;

- (void)log:(NSInteger)level file:(const char *)file func:(const char *)func line:(int)line module:(NSString*)module fmt:(NSString *)fmt, ...;

- (void)log:(NSInteger)level file:(const char *)file func:(const char *)func line:(int)line EFDict:(NSDictionary *)extDict msg:(NSString *)fmt, ...;

- (void)log:(NSInteger)level file:(const char *)file func:(const char *)func line:(int)line module:(NSString*)module EFDict:(NSDictionary *)extDict msg:(NSString *)fmt, ...;
@end
