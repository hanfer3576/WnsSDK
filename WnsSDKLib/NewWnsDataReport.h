//
//  NewWnsDataReport.h
//  WnsSDK
//
//  Created by best1a on 9/28/15.
//  Copyright © 2015 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NewWnsDataReport : NSObject

+ (instancetype)sharedInstance;

//设置固定上报信息，信息组织成NSDictionary，包括上面键值所包含的信息
- (void)setCommonData:(NSDictionary *)commonData;

//上报数据
- (void)reportData:(NSString *)cmd              //命令字
               ret:(int)ret                     //返回码
               uin:(int64_t)uin                 //帐号
            tmcost:(int)tmcost                  //总耗时
           reqsize:(int)reqszie                 //发包大小
           rspsize:(int)rspsize                 //回包大小
        sdkversion:(NSString *)sdkversion       //sdk版本
               seq:(NSString *)seq              //请求序列号
          serverip:(NSString *)serverip         //请求ip
              port:(int)port                    //请求端口
            detail:(NSString *)detail           //详情
             dtype:(int)dtype
          odetails:(NSString*)odetails;

@end
