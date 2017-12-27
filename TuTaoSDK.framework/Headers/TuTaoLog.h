//
//  TuTaoLog.h
//  TuTaoSDK
//
//  Created by Tm on 2017/12/20.
//  Copyright © 2017年 Tim. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, TuTaoLogLevel){
    //关闭输出
    TuTaoLogLevelOff       = 0,
    //仅输出错误
    TuTaoLogLevelError     = 1,
    //输出警告错误
    TuTaoLogLevelWarning   = 2,
    //输出INFO警告错误
    TuTaoLogLevelInfo      = 3,
    //输出调试信息
    TuTaoLogLevelDebug     = 4,
};


@interface TuTaoLog : NSObject

/**
 *  日志输出级别 默认TuTaoLogLevelOff
 */
@property (nonatomic, assign) TuTaoLogLevel level;

/**
 *  日志处理类
 */
+ (TuTaoLog *)sharedLogger;


/**
 *  输出日志
 *
 *  @param format 日志信息
 */
+ (void)log:(NSString *)format, ...;
+ (void)error:(NSString *)format, ...;
+ (void)warning:(NSString *)format, ...;
+ (void)info:(NSString *)format, ...;
+ (void)debug:(NSString *)format, ...;

@end


#ifndef TuTaoSDKLogDefine
#define TuTaoSDKLogDefine

#define kTLog(...) [TuTaoLog log:__VA_ARGS__]
#define kTLogError(...) [TuTaoLog error:__VA_ARGS__]
#define kTLogWarning(...) [TuTaoLog warning:__VA_ARGS__]
#define kTLogInfo(...) [TuTaoLog info:__VA_ARGS__]
#define kTLogDebug(...) [TuTaoLog debug:__VA_ARGS__]

#endif
