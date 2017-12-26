//
//  UIImageView+TuProgress.h
//  TuTaoSDK
//
//  Created by Tm on 2017/12/22.
//  Copyright © 2017年 Tim. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TuCircleProgressIndicator : UIView

@property (nonatomic, assign) float progressValue;
@property (nonatomic, strong) UIColor *strokeProgressColor;
@property (nonatomic, strong) UIColor *strokeRemainingColor;
@property (nonatomic, assign) CGFloat strokeWidthRatio;
@property (nonatomic, assign) CGFloat strokeWidth;
@property (nonatomic, assign) CGFloat minimumSize;

@end


@interface UIImageView (TuProgress)

//0.0 and 1.0
@property (nonatomic, readonly) TuCircleProgressIndicator *progressIndicatorView;

- (void)tu_setImageWithURL:(NSString *)url;
- (void)tu_setImageWithURL:(NSString *)url completed:(void (^) (UIImage *image , NSError *error))completed;

@end
