#include "light_ctrl.h"
#include "config.h"

// 骨架：WS2812 用 Adafruit NeoPixel/FastLED，逻辑待 M1 填充
void LightCtrl::begin() {
  // TODO M1: 初始化 NeoPixel；注意 3.3V→5V 电平转换
}

void LightCtrl::update(uint32_t now) {
  (void)now;
  // TODO: 处理呼吸/渐变/日出曲线（用 millis，不用 delay）
}

void LightCtrl::setMode(int mode)      { _mode = mode; }
void LightCtrl::setBrightness(int lvl) { _brightness = lvl; }
void LightCtrl::startSunrise()         { _sunrise = true; _sunriseStart = millis(); }
void LightCtrl::stop()                 { _sunrise = false; _mode = 0; }
