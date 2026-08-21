// ============================================================
// 主程序骨架（ESP32-S3 / Arduino 框架）
// 原则：loop() 只调度，不写复杂逻辑；模块各提供 update()。
// 硬件到货前此文件仅作结构示范，逻辑待 M1~M6 填充。
// ============================================================

#include <Arduino.h>
#include "config.h"
#include "app_state.h"

// 六模块（位于 src/modules/ 子目录）
#include "modules/light_ctrl.h"
#include "modules/clock_ctrl.h"
#include "modules/alarm_ctrl.h"
#include "modules/voice_ctrl.h"
#include "modules/ui_ctrl.h"
#include "modules/storage_ctrl.h"

// ---- 模块实例 ----
LightCtrl   lightCtrl;
ClockCtrl   clockCtrl;
AlarmCtrl   alarmCtrl;
VoiceCtrl   voiceCtrl;
UiCtrl      uiCtrl;
StorageCtrl storageCtrl;

SystemState g_state = STATE_NORMAL_DISPLAY;

// ---- 应用层：状态 + 事件分发 ----
class App {
public:
  void begin() {
    storageCtrl.load();          // 载入掉电保存参数
    clockCtrl.begin();
    lightCtrl.begin();
    voiceCtrl.begin();
    uiCtrl.begin();
    // 其余 begin() 待模块实现
  }

  void onSecondTick(time_t now) {
    // 每秒：检查闹钟 / 日出触发
    if (alarmCtrl.isAlarmTime(now)) {
      g_state = STATE_ALARM_RINGING;
    } else if (alarmCtrl.isSunriseStart(now)) {
      g_state = STATE_SUNRISE;
    }
  }

  void onKeyEvent(SystemEvent ev) {
    // 按键事件 → 状态机 / 菜单
    (void)ev; // TODO: M3 实现
  }

  void onVoiceCommand(VoiceCmd cmd) {
    // 语音命令 → 动作
    switch (cmd) {
      case VOICE_OPEN_LIGHT:  g_state = STATE_NIGHT_LIGHT; break;
      case VOICE_CLOSE_LIGHT: g_state = STATE_LIGHT_OFF;   break;
      case VOICE_CLOSE_ALARM: /* TODO: 关闭闹钟 */ break;
      case VOICE_SNOOZE:      g_state = STATE_SNOOZE;      break;
      default: break;
    }
  }

  SystemState state() const { return g_state; }
} app;

void setup() {
  Serial.begin(115200);
  app.begin();
}

void loop() {
  uint32_t now = millis();

  clockCtrl.update(now);
  voiceCtrl.update();
  storageCtrl.update();

  if (clockCtrl.isNewSecond()) {
    app.onSecondTick(clockCtrl.now());
  }
  if (voiceCtrl.hasCommand()) {
    app.onVoiceCommand(voiceCtrl.getCommand());
  }

  lightCtrl.update(now);
  uiCtrl.update(clockCtrl, alarmCtrl, g_state);

  // 禁用长 delay()，所有定时用 millis()
}

// 注意：本骨架仅搭结构，模块方法需在各自 .cpp 中实现后才能编译通过。
