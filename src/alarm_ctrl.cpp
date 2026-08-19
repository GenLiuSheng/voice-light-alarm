#include "alarm_ctrl.h"
#include "config.h"

// 骨架：逻辑待 M4 填充
void AlarmCtrl::begin() {}

void AlarmCtrl::update(uint32_t now) { (void)now; }

bool AlarmCtrl::isAlarmTime(time_t t) {
  (void)t; return false;   // TODO M4: 比较时/分，且同分钟只触发一次
}
bool AlarmCtrl::isSunriseStart(time_t t) {
  (void)t; return false;   // TODO M5: t 在 [闹钟-_lead, 闹钟) 内
}
void AlarmCtrl::snooze()    { _snoozeUntil = millis() + DEFAULT_SNOOZE_MIN * 60000UL; }
void AlarmCtrl::disable()   { _enabled = false; }

void AlarmCtrl::setAlarm(int h, int m, bool on) { _hour = h; _min = m; _enabled = on; }
void AlarmCtrl::setLead(int minutes)            { _lead = minutes; }
