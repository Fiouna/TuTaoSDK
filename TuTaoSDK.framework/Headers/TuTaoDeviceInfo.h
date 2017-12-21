//
//  TuTaoDeviceInfo_iOS.h
//  TuTaoDeviceInfo
//
//  Created by Luka Mirosevic on 11/10/2012.
//  Copyright (c) 2013 Goonbee. All Rights Reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

/*
 项目代码来源:
 https://github.com/lmirosevic/GBDeviceInfo
 https://github.com/rebeccahughes/react-native-device-info
 */

//GB 5.1.0
//RE 0.13.0

#import "TuTaoDeviceInfo_Common.h"
#import "TuTaoDeviceInfoTypes.h"

@interface TuTaoDeviceInfo : TuTaoDeviceInfo_Common

/**
 The device version. e.g. {7, 2}.
 */
@property (assign, atomic, readonly) TuTaoDeviceVersion    deviceVersion;

/**
 The human readable name for the device, e.g. "iPhone 6".
 */
@property (strong, atomic, readonly) NSString           *modelString;

/**
 The specific device model, e.g. TuTaoDeviceModeliPhone6.
 */
@property (assign, atomic, readonly) TuTaoDeviceModel      model;

/**
 Information about the display.
 */
@property (assign, atomic, readonly) TuTaoDisplayInfo      displayInfo;

@end
