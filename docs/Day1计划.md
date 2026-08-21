# Day 1 计划 — 2026-08-19（周三）

> 目标：完成 V1 项目立项，搭好文档骨架，锁定硬件方案
> 角色：大三实习生 ｜ Mentor 验收节点：节点 1 立项完成
> 更新：2026-08-19 晚（bom 二次更新：确认 SSD1315 OLED / SU-03T 语音 / WS2812B 60LED 灯带 / 100μF 电容 / 5V 电源模块；新增 Arduino IDE 安装任务）

## ✅ 已完成（P0）

- [x] **创建本地仓库** `voice-light-alarm/` 及子目录（docs/ hardware/ media/ src/ examples/）
- [x] **撰写 docs/立项书.md**
- [x] **撰写 hardware/bom.md**（已更新为实际购买型号：ESP32-S3 N16R8 / SSD1315 OLED / DS3231 / SU-03T / WS2812B 60LED / 100μF / 5V 模块）
- [x] **撰写 README.md**
- [x] **GitHub 仓库创建 + 首次 push**（仓库：https://github.com/GenLiuSheng/voice-light-alarm ；连接器只读，最终用短期 PAT 走 `git push`，令牌已清除）
- [x] **硬件采购完成**：主控 **ESP32-S3 N16R8**、显示 **SSD1315 0.96" OLED**、时钟 **DS3231**、语音 **SU-03T**、灯带 **WS2812B 60LED**、电容 **100μF**、电源 **5V 模块**、万用表 **天宇 T21L** 已下单（待到货）

## 📋 板到货前可推进（本周 P1，部分已完成）

- [x] 撰写 `docs/需求文档.md`（FR1–FR9 + 非功能需求）
- [x] 撰写 `docs/预研计划.md`（WS2812 / I2C / 语音 / 卡死 4 风险 + ESP32-S3 专项）
- [x] 创建 `docs/问题记录.md` 模板
- [ ] **成功下载、安装并正确激活 Arduino IDE**（安装 ESP32 开发板支持包 + USB 转串驱动，烧录 Blink 验证端口）
- [ ] 安装 VS Code + PlatformIO，建 `esp32-s3-devkitc-1` 工程骨架（不依赖硬件）
- [ ] ESP32-S3 专项预习（pinout / 3.3V 电平 / PSRAM 开启 / 烧录方式）
- [ ] 每天 10 分钟站会自检

## 📦 等待原件送到期间的任务安排（约 7 天）

板子（ESP32-S3 N16R8）与其余元件在途，**期间无法跑硬件**，但可把"不焊电路"的软件 / 文档 / 预习全部做完。

### Day 1–2：开发环境（纯软件，不需要板）

- [ ] **成功下载、安装并正确激活 Arduino IDE**（https://www.arduino.cc/en/software ；首选项附加开发板网址加入 ESP32 包；装 ESP32 板支持 + USB 驱动；烧录 Blink 验证端口）
- [ ] 安装 VS Code + PlatformIO 插件
- [ ] 新建 PlatformIO 工程：`platform = espressif32`，`board = esp32-s3-devkitc-1`
- [ ] 写 `platformio.ini` + `src/` 六模块空骨架（light/clock/alarm/voice/ui/storage 各 `.h/.cpp`，含空 `update()`）
- [ ] 配置 PSRAM：`board_build.psram = enable`；确认 16MB flash 分区
- [ ] 跑通**纯编译** Blink（无板也能 `PlatformIO: Build` 验证工具链）

### Day 3–4：需求与预研文档（本次已产出）

- [x] `docs/需求文档.md` —— 已完成
- [x] `docs/预研计划.md` —— 已完成
- [x] `docs/问题记录.md` 模板 —— 已完成

### Day 5–6：ESP32-S3 专项预习（关键，避免到货踩坑）

- [ ] 查 ESP32-S3 数据手册 pinout：确认 I2C 默认引脚（S3 与 ESP32 的 GPIO21/22 不同，需显式 `Wire.begin(SDA, SCL)`）
- [ ] 弄清 **3.3V vs 5V 电平**：WS2812 DIN 电平转换方案（74HCT245 / 模块自带？）
- [ ] 弄清 PSRAM 开启方式（Arduino 下 `board_build.psram = enable`）
- [ ] 确认 S3 烧录方式（原生 USB-CDC vs UART0）与 PlatformIO 上传配置
- [ ] 预习 WS2812 GRB 颜色顺序、Adafruit NeoPixel / FastLED 用法
- [ ] 预习 DS3231（0x68）、SSD1315（0x3C/0x3D）I2C 地址

### Day 7：到货前最后核对

- [ ] 对照 `hardware/bom.md` 逐项核对物流状态，到货后回填单价 / 链接
- [ ] 画面包板接线草图（先不焊）
- [ ] 列"到货第一天必做 5 件事"（见 `docs/预研计划.md` 末尾）

## ⏱ 时间预算（剩余）

| 任务 | 预计耗时 |
|---|---:|
| 装 Arduino IDE + 跑 Blink | 30 min |
| 装 VS Code + PlatformIO + 建骨架 | 30 min |
| ESP32-S3 预习 | 1~2 h |
| 接线草图 + 到货清单 | 30 min |
| **合计** | **~3.5 h（分散在一周）** |

## 📌 站会自检

### 今天完成
- [x] GitHub 仓库已建并 push（commit 558c6b4 → 5876d20）
- [x] 硬件型号已确认并更新 bom：ESP32-S3 N16R8 + SSD1315 OLED + DS3231 + SU-03T + WS2812B 60LED + 100μF + 5V 模块 + 天宇 T21L
- [x] 需求文档 / 预研计划 / 问题记录模板 已写

### 遇到问题
- GitHub 连接器只读（create_repository / push_files 均 403）→ 改用短期 PAT 走 git push

### 解决方案
- 用户生成 classic PAT（repo scope），`git remote set-url` 带令牌 push，推完立即清除令牌

### 明天计划
- 成功下载、安装并正确激活 Arduino IDE
- 装 VS Code + PlatformIO，建 S3 工程骨架
- ESP32-S3 pinout / 电平 / PSRAM 预习

---

> 来自 mentor 的提醒：每完成一项就 git commit 一次，commit 信息按 `feat:` / `docs:` / `fix:` / `test:` 分类。
