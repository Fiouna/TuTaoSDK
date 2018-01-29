//
//  TuTaoManager.h
//  TuTaoSDK
//
//  Created by Tm on 2017/12/13.
//  Copyright © 2017年 Tim. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuTaoLog.h"

@interface TuTaoManager : NSObject

//打印SDK版本
+ (void)version;

/**
 *  初始化SDK
 *
 *  @param appkey 应用秘钥
 */
+ (void)initWithAppKey:(NSString *)appkey;

/**
 *  设置日志输出级别
 *
 *  @param level 日志输出级别 默认TuTaoLogLevelOff
 */
+ (void)setLogLevel:(TuTaoLogLevel)level;

//暂无处理事件，目前只做测试
+ (void)start;

@end
