#include "storage_ctrl.h"

// 骨架：Preferences；逻辑待 M4 填充
void StorageCtrl::begin() {
  // TODO M4: preferences.begin("vla", false);
}
void StorageCtrl::load()  { /* TODO: 读闹钟/模式/亮度 */ }
void StorageCtrl::update(){ /* TODO: 若 _dirty 则 save() */ }
void StorageCtrl::save()  { _dirty = false; }
