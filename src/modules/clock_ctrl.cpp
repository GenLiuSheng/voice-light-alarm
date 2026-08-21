#include "clock_ctrl.h"

// 骨架：DS3231 读取；逻辑待 M2 填充
void ClockCtrl::begin() {
  // TODO M2: Wire.begin(I2C_SDA, I2C_SCL); rtc.begin();
}

void ClockCtrl::update(uint32_t now) {
  (void)now;
  // TODO M2: 周期读取 RTC，检测跨秒
  _newSecond = false;
}

bool ClockCtrl::isNewSecond() { return _newSecond; }
time_t ClockCtrl::now()       { return _last; }
void ClockCtrl::setTime(time_t t) { _last = t; }
