//
//  TuTaoDeviceInfoTypes_iOS.h
//  TuTaoDeviceInfo
//
//  Created by Luka Mirosevic on 14/03/2013.
//  Copyright (c) 2013 Goonbee. All rights reserved.
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

typedef NS_ENUM(NSInteger, TuTaoDeviceModel) {
    TuTaoDeviceModelUnknown = 0,
    TuTaoDeviceModelSimulatoriPhone,
    TuTaoDeviceModelSimulatoriPad,
    TuTaoDeviceModeliPhone1,
    TuTaoDeviceModeliPhone3G,
    TuTaoDeviceModeliPhone3GS,
    TuTaoDeviceModeliPhone4,
    TuTaoDeviceModeliPhone4S,
    TuTaoDeviceModeliPhone5,
    TuTaoDeviceModeliPhone5c,
    TuTaoDeviceModeliPhone5s,
    TuTaoDeviceModeliPhoneSE,
    TuTaoDeviceModeliPhone6,
    TuTaoDeviceModeliPhone6Plus,
    TuTaoDeviceModeliPhone6s,
    TuTaoDeviceModeliPhone6sPlus,
    TuTaoDeviceModeliPhone7,
    TuTaoDeviceModeliPhone7Plus,
    TuTaoDeviceModeliPhone8,
    TuTaoDeviceModeliPhone8Plus,
    TuTaoDeviceModeliPhoneX,
    TuTaoDeviceModeliPad1,
    TuTaoDeviceModeliPad2,
    TuTaoDeviceModeliPad3,
    TuTaoDeviceModeliPad4,
    TuTaoDeviceModeliPadMini1,
    TuTaoDeviceModeliPadMini2,
    TuTaoDeviceModeliPadMini3,
    TuTaoDeviceModeliPadMini4,
    TuTaoDeviceModeliPadAir1,
    TuTaoDeviceModeliPadAir2,
    TuTaoDeviceModeliPadPro9p7Inch,
    TuTaoDeviceModeliPadPro10p5Inch,
    TuTaoDeviceModeliPadPro12p9Inch,
    TuTaoDeviceModeliPadPro10p5Inch2,
    TuTaoDeviceModeliPadPro12p9Inch2,
    TuTaoDeviceModeliPad5,
    TuTaoDeviceModeliPod1,
    TuTaoDeviceModeliPod2,
    TuTaoDeviceModeliPod3,
    TuTaoDeviceModeliPod4,
    TuTaoDeviceModeliPod5,
    TuTaoDeviceModeliPod6,
};

typedef NS_ENUM(NSInteger, TuTaoDeviceDisplay) {
    TuTaoDeviceDisplayUnknown = 0,
    TuTaoDeviceDisplay3p5Inch,
    TuTaoDeviceDisplay4Inch,
    TuTaoDeviceDisplay4p7Inch,
    TuTaoDeviceDisplay5p5Inch,
    TuTaoDeviceDisplay5p8Inch,
    TuTaoDeviceDisplay7p9Inch,
    TuTaoDeviceDisplay9p7Inch,
	TuTaoDeviceDisplay10p5Inch,
    TuTaoDeviceDisplay12p9Inch,
};

typedef struct {
    /**
     The display of this device.
     
     Returns TuTaoDeviceDisplayUnknown on the simulator.
     */
    TuTaoDeviceDisplay                                     display;
    
    /**
     The display's pixel density in ppi (pixels per inch).
     
     Returns 0 on the simulator.
     */
    CGFloat                                             pixelsPerInch;
} TuTaoDisplayInfo;

/**
 Makes a TuTaoDisplayInfo struct.
 */
inline static TuTaoDisplayInfo TuTaoDisplayInfoMake(TuTaoDeviceDisplay display, CGFloat pixelsPerInch) {
    return (TuTaoDisplayInfo){display, pixelsPerInch};
};
