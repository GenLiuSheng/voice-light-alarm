#ifndef ALARM_CTRL_H
#define ALARM_CTRL_H

#include <Arduino.h>
#include "config.h"

// 闹钟 / 贪睡 / 日出逻辑（FR3/FR4/FR5/FR6）
class AlarmCtrl {
public:
  void begin();
  void update(uint32_t now);

  bool isAlarmTime(time_t t);     // FR4 到点
  bool isSunriseStart(time_t t);  // FR6 提前 N 分
  void snooze();                  // FR5 贪睡 5 分钟
  void disable();                 // 关闭当前闹钟

  void setAlarm(int h, int m, bool on);
  void setLead(int minutes);      // 10/20/30

private:
  int  _hour = 0, _min = 0;
  bool _enabled = false;
  int  _lead = SUNRISE_LEAD_DEFAULT;
  uint32_t _snoozeUntil = 0;
};

#endif // ALARM_CTRL_H
