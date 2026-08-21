#ifndef UI_CTRL_H
#define UI_CTRL_H

#include <Arduino.h>
#include "app_state.h"

class ClockCtrl;   // 前向声明
class AlarmCtrl;

// OLED 显示与按键菜单（FR1/FR2/FR3，M2/M3）
class UiCtrl {
public:
  void begin();
  void update(const ClockCtrl& clk, const AlarmCtrl& alm, SystemState state);

  // 按键事件由 keyCtrl 产生，这里仅占位（按键模块待 M3 拆分）
  void onKey(SystemEvent ev);

private:
  int _menuIndex = 0;
};

#endif // UI_CTRL_H
