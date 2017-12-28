//
//  TuTaoUICommonDefines.h
//  TuTaoSDK
//
//  Created by Tm on 2017/12/20.
//  Copyright © 2017年 Tim. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import "TuTaoUIHelper.h"

#pragma mark - Clang

#define ArgumentToString(macro) #macro
#define ClangWarningConcat(warning_name) ArgumentToString(clang diagnostic ignored warning_name)

// 参数可直接传入 clang 的 warning 名，warning 列表参考：https://clang.llvm.org/docs/DiagnosticsReference.html
#define BeginIgnoreClangWarning(warningName) _Pragma("clang diagnostic push") _Pragma(ClangWarningConcat(#warningName))
#define EndIgnoreClangWarning _Pragma("clang diagnostic pop")

#define BeginIgnorePerformSelectorLeaksWarning BeginIgnoreClangWarning(-Warc-performSelector-leaks)
#define EndIgnorePerformSelectorLeaksWarning EndIgnoreClangWarning

#define BeginIgnoreAvailabilityWarning BeginIgnoreClangWarning(-Wpartial-availability)
#define EndIgnoreAvailabilityWarning EndIgnoreClangWarning

#define BeginIgnoreDeprecatedWarning BeginIgnoreClangWarning(-Wdeprecated-declarations)
#define EndIgnoreDeprecatedWarning EndIgnoreClangWarning


#pragma mark - 设备相关
// 设备类型
#define TU_IS_IPAD [TuTaoUIHelper isIPad]
#define TU_IS_IPOD [TuTaoUIHelper isIPod]
#define TU_IS_IPHONE [TuTaoUIHelper isIPhone]
#define TU_IS_IPHONEX [TuTaoUIHelper isIPhoneX]
#define TU_IS_SIMULATOR [TuTaoUIHelper isSimulator]

// 操作系统版本号，只获取第二级的版本号，例如 10.3.1 只会得到 10.3
#define TU_IOS_VERSION ([[[UIDevice currentDevice] systemVersion] doubleValue])

// 使用文件名(不带后缀名)创建一个UIImage对象，会被系统缓存，适用于大量复用的小资源图
#define UIImageMake(img) \
BeginIgnoreAvailabilityWarning \
(TU_IOS_VERSION >= 8.0 ? [UIImage imageNamed:img inBundle:nil compatibleWithTraitCollection:nil] : [UIImage imageNamed:img]) \
EndIgnoreAvailabilityWarning

// 使用文件名(不带后缀名，仅限png)创建一个UIImage对象，不会被系统缓存，用于不被复用的图片，特别是大图
#define UIImageMakeWithFile(name) UIImageMakeWithFileAndSuffix(name, @"png")
#define UIImageMakeWithFileAndSuffix(name, suffix) [UIImage imageWithContentsOfFile:[NSString stringWithFormat:@"%@/%@.%@", [[NSBundle mainBundle] resourcePath], name, suffix]]


// 字体相关创建器，包括动态字体的支持
#define UIFontMake(size) [UIFont systemFontOfSize:size]
#define UIFontBoldMake(size) [UIFont boldSystemFontOfSize:size]


#define TU_SCREEN_BOUNDS  [[UIScreen mainScreen] bounds]

// 是否横竖屏 用户界面横屏了才会返回YES
#define TU_IS_LANDSCAPE UIInterfaceOrientationIsLandscape([[UIApplication sharedApplication] statusBarOrientation])
// 无论支不支持横屏，只要设备横屏了，就会返回YES
#define TU_IS_DEVICE_LANDSCAPE UIDeviceOrientationIsLandscape([[UIDevice currentDevice] orientation])
// 屏幕宽度，会根据横竖屏的变化而变化
#define TU_WINDOW_WIDTH ([[UIScreen mainScreen] bounds].size.width)
// 屏幕宽度，跟横竖屏无关
#define TU_DEVICE_WIDTH (TU_IS_LANDSCAPE ? [[UIScreen mainScreen] bounds].size.height : [[UIScreen mainScreen] bounds].size.width)
// 屏幕高度，会根据横竖屏的变化而变化
#define TU_WINDOW_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
// 屏幕高度，跟横竖屏无关
#define TU_DEVICE_HEIGHT (TU_IS_LANDSCAPE ? [[UIScreen mainScreen] bounds].size.width : [[UIScreen mainScreen] bounds].size.height)

// 是否Retina
#define TU_IS_RETINASCREEN ([[UIScreen mainScreen] scale] >= 2.0)

//状态栏高度 returns CGRectZero if the status bar is hidden
#define kTuStatusBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height)

// 获取一像素
#define kTuPixelOne [TuTaoUIHelper pixelOne]

//scale
#define kTuScale ([[UIScreen mainScreen] scale])

// UIColor 相关的宏 更多用法见 UIColor+TuUI
#define RGB(r, g, b)     [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define RGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]

//路径
#define kTuTaoPathTemp       NSTemporaryDirectory()
#define kTuTaoPathDocument   [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define kTuTaoPathCache      [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]


#pragma mark - 方法-C对象、结构操作
CG_INLINE BOOL
TuReplaceMethod(Class _class, SEL _originSelector, SEL _newSelector) {
    Method oriMethod = class_getInstanceMethod(_class, _originSelector);
    Method newMethod = class_getInstanceMethod(_class, _newSelector);
    if (!newMethod) {
        // class 里不存在该方法的实现
        return NO;
    }
    BOOL isAddedMethod = class_addMethod(_class, _originSelector, method_getImplementation(newMethod), method_getTypeEncoding(newMethod));
    if (isAddedMethod) {
        class_replaceMethod(_class, _newSelector, method_getImplementation(oriMethod), method_getTypeEncoding(oriMethod));
    } else {
        method_exchangeImplementations(oriMethod, newMethod);
    }
    return YES;
}

