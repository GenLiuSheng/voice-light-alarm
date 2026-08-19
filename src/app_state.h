#ifndef APP_STATE_H
#define APP_STATE_H

// ============================================================
// 系统状态机定义（骨架）
// loop() 只负责调度，状态切换与复杂逻辑进各模块。
// ============================================================

enum SystemState {
  STATE_NORMAL_DISPLAY,   // 正常显示时间
  STATE_SETTING_TIME,     // 设置时间
  STATE_SETTING_ALARM,    // 设置闹钟
  STATE_SUNRISE,          // 日出模拟中
  STATE_ALARM_RINGING,    // 闹钟响
  STATE_SNOOZE,           // 贪睡
  STATE_NIGHT_LIGHT,      // 夜灯
  STATE_LIGHT_OFF         // 灯关闭
};

enum SystemEvent {
  EVENT_NONE,
  EVENT_TICK_1S,
  EVENT_KEY_MODE,
  EVENT_KEY_ADD,
  EVENT_KEY_SUB,
  EVENT_KEY_OK,
  EVENT_VOICE_CMD,
  EVENT_ALARM_TIME_REACHED,
  EVENT_SUNRISE_START,
  EVENT_SNOOZE_TIMEOUT
};

// 语音命令 ID（与 docs/需求文档.md FR8 对应）
enum VoiceCmd {
  VOICE_OPEN_LIGHT   = 0x01,
  VOICE_CLOSE_LIGHT  = 0x02,
  VOICE_NIGHT        = 0x03,
  VOICE_WARM         = 0x04,
  VOICE_READ         = 0x05,
  VOICE_CLOSE_ALARM  = 0x06,
  VOICE_SNOOZE       = 0x07,
  VOICE_START_SUNRISE= 0x08,
  VOICE_UNKNOWN      = 0x00
};

#endif // APP_STATE_H
