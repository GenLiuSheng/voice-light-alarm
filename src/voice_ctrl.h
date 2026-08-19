#ifndef VOICE_CTRL_H
#define VOICE_CTRL_H

#include <Arduino.h>
#include "app_state.h"

// 离线语音命令接收与解析（FR8，UART）
class VoiceCtrl {
public:
  void begin();
  void update();                 // 非阻塞读取串口缓冲

  bool hasCommand();
  VoiceCmd getCommand();         // 返回最近一条命令 ID

private:
  VoiceCmd _last = VOICE_UNKNOWN;
  bool     _pending = false;
};

#endif // VOICE_CTRL_H
