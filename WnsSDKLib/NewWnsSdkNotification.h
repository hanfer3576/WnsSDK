//
//  WnsNotification.h
//  Wns SDK
//
//  Created by Wenbin on 12-7-30.
//  Copyright (c) 2012年 Tencent. All rights reserved.
//

#ifndef TestWnsSDK4_WnsNotification_h
#define TestWnsSDK4_WnsNotification_h

//全局通知定义

#define kLoginStateChanged      @"LoginStateChanged"
#define kWnsNotAvailable        @"WnsNotAvailable"
#define kWnsNeedRelogin         @"WnsNeedRelogin"
#define kWtloginStateChanged    @"WtloginStateChanged"
#define kWtloginKeyChanged      @"WtloginKeyChanged"
#define kWnsConnectionStatus    @"WnsConnectionStatus"
#define kWnsNetReachableNotify   @"kWnsNetReachableNotify"

#define kWnsUinNotInWhiteList       @"WnsUinNotInWhiteList"  //Uin不在白名单

#define  WNS_OPESSEION_FAILEVENT    @"OpenSessionFailEvent"
#define  WNS_UPLOADLOG_EVENT        @"WnsUploadLogEvent"
#define  WNS_UPLOADLOGFILE_EVENT    @"WnsUploadLogFileEvent"
#define  WNS_LOGIN_FAILEVENT        @"LoginFailEvent"

#define  WNS_UPLOGFILE_TITLE    @"UpLogFileTitle"
#define  WNS_UPLOGFILE_BODY     @"UpLogFileBody"

#define kExchangeSigSuccess     @"ExchangeSigSuccess"
#define kExchangeSigFailed      @"ExchangeSigFailed"

#define kWnsNeedWifiAuth            @"WnsNeedWifiAuth"

#define kWnsNeedReloginErrorTitle   @"kWnsNeedReloginErrorTitle"
#define kWnsNeedReloginErrorSummary @"kWnsNeedReloginErrorSummary"
#endif
