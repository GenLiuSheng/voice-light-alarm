#ifndef STORAGE_CTRL_H
#define STORAGE_CTRL_H

#include <Arduino.h>

// 参数掉电保存（FR9，ESP32 Preferences / NVS）
class StorageCtrl {
public:
  void begin();
  void load();                    // 上电读取
  void update();                  // 周期检测变更
  void save();                    // 立即保存

private:
  bool _dirty = false;
};

#endif // STORAGE_CTRL_H
