//
//  AppDelegate.h
//  NativeDisplayBrightness
//
//  Created by Benno Krauss on 19.10.16.
//  Copyright © 2016 Benno Krauss. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "Config.h"
#import "CBBlueLightClient.h"

@class BrightnessViewController;
@class ColorTemperatureViewController;

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    NSDictionary *keys;
}

@property (strong) NSStatusItem *statusBarIcon;
@property (strong) NSMenu *statusBarMenu;
@property (strong) BrightnessViewController *brightnessView;

@property (strong) CBBlueLightClient *blueLight;
@property (strong) ColorTemperatureViewController *colorTemperatureView;
@property (strong) NSMenuItem *colorTemperatureMenu;

//runtime variables
@property (assign) int currentBrightness;
@property (assign) BOOL supportsBlueLightReduction;

//Settings values
@property (nonatomic, assign) BOOL multiMonitor;
@property (nonatomic, assign) BOOL smoothStep;
@property (nonatomic, assign) BOOL showBrightness;
@property (nonatomic, assign) int maxBrightness;

@property (nonatomic, strong) NSString *increaseBrightnessKeyCode;
@property (nonatomic, strong) NSString *decreaseBrightnessKeyCode;

@property (nonatomic, assign) BOOL adjustColorTemperature;
@property (nonatomic, assign) float colorTemperatureLimit;

@property (nonatomic, strong) NSString *colorTemperatureLessWarmKeyCode;
@property (nonatomic, strong) NSString *colorTemperatureMoreWarmKeyCode;

+(BOOL)loadSavedBrightness:(uint*) savedBrightness forDisplayID:(CGDirectDisplayID) displayID;

+(void)changeMainScreenBrightness:(int) newBrightness;
+(void)changeMainScreenBrightnessWithStep:(int) deltaInSubsteps;

+(void)changeScreenColorTemperature:(float) colorTemperature;
+(void)changeScreenColorTemperatureStep:(float) colorTemperatureStep;

@end

