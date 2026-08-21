#include "voice_ctrl.h"
#include "config.h"

// 骨架：用 HardwareSerial 接收；协议待 M6 确认
void VoiceCtrl::begin() {
  // TODO M6: Serial2.begin(VOICE_UART_BAUD, SERIAL_8N1, VOICE_RX_PIN, VOICE_TX_PIN);
}

void VoiceCtrl::update() {
  // TODO M6: 非阻塞读取，解析命令 ID，置 _pending
}

bool VoiceCtrl::hasCommand() { return _pending; }
VoiceCmd VoiceCtrl::getCommand() { _pending = false; return _last; }
