#include "ui_ctrl.h"
#include "clock_ctrl.h"
#include "alarm_ctrl.h"

// 骨架：SSD1306 显示；逻辑待 M2/M3 填充
void UiCtrl::begin() {
  // TODO M2: display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
}

void UiCtrl::update(const ClockCtrl& clk, const AlarmCtrl& alm, SystemState state) {
  (void)clk; (void)alm; (void)state;
  // TODO M2/M3: 显示时间 / 日期 / 菜单 / ALARM 提示
}

void UiCtrl::onKey(SystemEvent ev) { (void)ev; }
