//
//  TuTaoGeometry.h
//  TuTaoSDK
//
//  Created by Tm on 2017/12/25.
//  Copyright © 2017年 Tim. All rights reserved.
//

/*公式来源于
 https://github.com/mysterioustrousers/MTGeometry
 http://referencesource.microsoft.com/#WindowsBase/Base/System/Windows/Point.cs
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - Line
struct TuLine{
    CGPoint beginPoint;
    CGPoint endPoint;
};
typedef struct TuLine TuLine;

TuLine TuLineMake(CGPoint beginPoint, CGPoint endPoint);

@interface NSValue (TuLine)
+ (id)valueWithTuLine:(TuLine)line;
- (TuLine)lineValue;
@end


#pragma mark - 角度
//角度转弧度
CGFloat TuDegreeToRadian(CGFloat angle);
//弧度转角度
CGFloat TuRadianToDegree(CGFloat radians);
CGFloat TuRadianTo360Degree(CGFloat radians);

//三点之间的角度
CGFloat TuPointGetAngle(CGPoint centerPoint, CGPoint point1, CGPoint point2);

#pragma mark - CGAffineTransform
CGFloat TuAffineTransformGetAngle(CGAffineTransform t);
CGSize TuAffineTransformGetScale(CGAffineTransform t);

#pragma mark - CGPoint
CGFloat TuPointGetDistance(CGPoint point1, CGPoint point2);
CGPoint TuPointGetMidPoint(CGPoint point1, CGPoint point2);
//两点之间，相距point1的距离，如果两点相同，则返回p1
CGPoint TuPointWithDistance(CGPoint point1, CGPoint point2, CGFloat distance);
//两条线相交的点
CGPoint TuPointOfIntersect(TuLine line1, TuLine line2);
CGFloat TuPointGetDistanceOfPoint(CGPoint point, TuLine line);
//points 为 CGPointValue
CGPoint TuPointCentroidOfPoints(NSArray *points);
CGPoint TuPointGetNearPoint(CGPoint basePoint, NSArray *points);

CGPoint TuPointRotate(CGPoint basePoint, CGPoint point, CGFloat angle);

CGPoint TuPointFlipHorizontal(CGPoint point, CGRect outerRect);
CGPoint TuPointFlipVertical(CGPoint point, CGRect outerRect);

CGPoint TuPointAspectFill(CGPoint point, CGSize destSize, CGRect sourceRect);

CGPoint TuPointSub(CGPoint point1, CGPoint point2);
//同TuPointOffset
CGPoint TuPointAdd(CGPoint point1, CGPoint point2);

//point.x+dx point.y+dy
CGPoint TuPointOffset(CGPoint point, CGFloat dx, CGFloat dy);
//point.x*sx point.y*sy
CGPoint TuPointScale(CGPoint point, CGFloat sx, CGFloat sy);

CGPoint TuPointAverage(CGPoint point1, CGPoint point2);

//翻转坐标
CGPoint TuPointFlip(CGPoint point);

#pragma mark - CGRect
CGRect TuRectFromPoint(CGPoint startPoint, CGPoint endPoint);

CGRect TuRectScale(CGRect rect, CGFloat sx, CGFloat sy);
CGRect TuRectScaleOrigin(CGRect rect, CGFloat sx, CGFloat sy);
CGRect TuRectScaleSize(CGRect rect, CGFloat sx, CGFloat sy);


#pragma mark - CGSize
CGSize TuSizeScale(CGSize size, CGFloat sx, CGFloat sy);
CGSize TuSizeFitInSize(CGSize sourceSize, CGSize destSize);
CGSize TuSizeGetScale(CGSize size1, CGSize size2);



#pragma mark - PicYoung 
//获取镜像点之后的中心， 中心点，移动点，目标点
CGPoint TuPointGetFlipCenter(CGPoint centerPoint, CGPoint point1, CGPoint point2);
//Rotate
//模式二角度函数
CGFloat MTwoAngle(NSInteger index, CGFloat angle);
CGFloat MTRotationAngle(NSInteger index, CGFloat angle);
//比例
CGSize Fisize(CGFloat size, NSInteger index, NSInteger originIndex);
//间距
CGFloat TTFibonacciDefaultDistanceBetwee(CGFloat size, NSInteger index);
//模式一、二、三起始位置
CGPoint TYImageStartPoint(NSUInteger modeIndex, CGFloat startAngle,
                          CGFloat distanceBetweenPopouts, CGFloat distanceFromCenter,
                          NSInteger index);
//模式二两边位置
CGPoint TYImageModeTwoPoint(NSInteger index, CGPoint p, CGPoint itemCenter);




