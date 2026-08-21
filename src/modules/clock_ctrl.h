#ifndef CLOCK_CTRL_H
#define CLOCK_CTRL_H

#include <Arduino.h>

// 时间管理（FR1/FR2，基于 DS3231）
class ClockCtrl {
public:
  void begin();
  void update(uint32_t now);

  bool isNewSecond();           // 每秒产生一次事件
  time_t now();                  // 当前 Unix 时间
  void setTime(time_t t);        // FR2 设置

private:
  bool   _newSecond = false;
  time_t _last = 0;
};

#endif // CLOCK_CTRL_H
