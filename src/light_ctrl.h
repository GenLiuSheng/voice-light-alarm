#ifndef LIGHT_CTRL_H
#define LIGHT_CTRL_H

#include <Arduino.h>

// 灯光控制（FR6 日出 / FR7 模式 / 亮度）
class LightCtrl {
public:
  void begin();
  void update(uint32_t now);

  void setMode(int mode);          // 0关 1夜灯 2暖光 3阅读
  void setBrightness(int level);   // 0..MAX_BRIGHTNESS_LEVEL
  void startSunrise();             // FR6 手动启动
  void stop();

private:
  int   _mode = 0;
  int   _brightness = 0;
  bool  _sunrise = false;
  uint32_t _sunriseStart = 0;
};

#endif // LIGHT_CTRL_H
