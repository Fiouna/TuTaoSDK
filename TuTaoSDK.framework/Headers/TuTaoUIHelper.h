//
//  TuTaoUIHelper.h
//  TuTaoSDK
//
//  Created by Tm on 2017/12/20.
//  Copyright © 2017年 Tim. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define kTuTaoUI   [TuTaoUIHelper sharedInstance]

NS_ASSUME_NONNULL_BEGIN
@interface TuTaoUIHelper : NSObject

#pragma mark - 新增UI属性 尺寸已根据横竖屏适配
//状态栏高度 如果隐藏则返回0
@property (nonatomic, readonly) CGFloat statusBarHeight;
//非iPhoneX 则返回 UIEdgeInsetsZero
@property (nonatomic, readonly) UIEdgeInsets safeAreaInsets;
//默认为44 如果是在iPhoneX上面则会加上safeArea的上部距离
@property (nonatomic, readonly) CGFloat navigationBarHeight;
//默认为49 如果是在iPhoneX上面则会加上safeArea的底部距离
@property (nonatomic, readonly) CGFloat tabBarHeight;
//默认为0 一般用于BarButtonItem 在iPhoneX上面会加上状态栏高度
@property (nonatomic, readonly) CGFloat itemOriginY;

+ (instancetype _Nonnull)sharedInstance;

@end


@interface TuTaoUIHelper (UIGraphic)

/// 获取一像素的大小
+ (CGFloat)pixelOne;

/// 判断size是否超出范围
+ (void)inspectContextSize:(CGSize)size;

/// context是否合法
+ (void)inspectContextIfInvalidatedInDebugMode:(CGContextRef _Nonnull)context;
+ (BOOL)inspectContextIfInvalidatedInReleaseMode:(CGContextRef _Nonnull)context;

@end


@interface TuTaoUIHelper (Device)

+ (BOOL)isIPad;
+ (BOOL)isIPod;
+ (BOOL)isIPhone;

// 为了模拟器能够调试UI，这里不区分模拟器和真机状态
+ (BOOL)isIPhoneX;

+ (BOOL)isSimulator;

// 用于获取 iPhoneX 安全区域的 insets
+ (UIEdgeInsets)safeAreaInsetsForIPhoneX;

@end

@interface TuTaoUIHelper (UIApplication)
/**
 *  更改状态栏内容颜色
 *
 *  @warning 需在项目的 Info.plist 文件内设置字段 “View controller-based status bar appearance” 的值为 NO 才能生效，如果不设置，或者值为 YES，则请通过系统的 - UIViewController preferredStatusBarStyle 方法来修改
 */
+ (void)renderStatusBarStyleDark;
+ (void)renderStatusBarStyleLight;

/**
 * 把App的主要window置灰，用于浮层弹出时，请注意要在适当时机调用`resetDimmedApplicationWindow`恢复到正常状态
 */
+ (void)dimmedApplicationWindow;

/**
 * 恢复对App的主要window的置灰操作，与`dimmedApplicationWindow`成对调用
 */
+ (void)resetDimmedApplicationWindow;

@end
NS_ASSUME_NONNULL_END
