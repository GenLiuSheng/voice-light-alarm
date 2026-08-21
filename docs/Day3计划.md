# Day 3 计划 — 2026-08-21（周五）

> 角色：大三实习生（ESP32-S3 路线）
> 阶段：**硬件仍未到货**，延续 Day 2「零硬件」路径。
> 关联：Day 2 已完成 Arduino IDE 编译验证 + VS Code 下载；未完成项顺延到今日。

---

## 一、逻辑主线

Day 2 把「工具链 + 方案 + 例程」三件事开了头，今日按依赖顺序收尾：

```text
1. 先闭合工具链   → PlatformIO 装好并编译通过（Day 2 第 2 项未完成）
2. 再定稿设计文档 → 供电/电平/引脚/语音命令写进文档（Day 2 第 3/4/5 项）
3. 最后预写例程   → 学基础 + 先写 M1 例程（Day 2 第 6 项，板到即测）
```

目标不变：**板到那天插上电就能直接烧、直接点，不现场查资料**。

---

## 二、P0 必做（4 项，按依赖顺序）

### 1. PlatformIO 工具链闭合（Day 2 第 2 项）✅ 已完成
- [x] 安装 VS Code + PlatformIO 插件
- [x] 打开已有 `platformio.ini`（`board = esp32-s3-devkitc-1` + PSRAM + 4 库）
- [x] 阅读 `src/` 六模块职责与工程入口，确认 `config.h` 引脚仍为「待定」
- [x] 执行 **PlatformIO: Build**，骨架编译通过
- [x] 截图/记录 + commit：`fix: PlatformIO 工具链闭合 - 修正 DS3231 库名(northernwidget)与 config.h 头文件依赖，骨架编译通过(RAM 5.6%/Flash 7.9%)`

> 📌 实测记录（2026-08-21）：
> - 首次 Build 失败原因 1：`robtillaard/DS3231` 库名在 PlatformIO 不存在 → 改为 `northernwidget/DS3231 @ ^1.2.0`
> - 失败原因 2：`alarm_ctrl.h` 用到 `SUNRISE_LEAD_DEFAULT` 但未包含 `config.h` → 补 `#include "config.h"`
> - 成功：RAM 5.6%（18488 B / 327680 B），Flash 7.9%（264361 B / 3342336 B），耗时 48s
> - 另：新增 `.gitignore` 排除 `.pio/` 构建产物

### 2. 设计文档定稿（Day 2 第 3/4 项）✅ 已完成
> 不依赖硬件，今天把方案写死，避免板到后临时拍脑袋。

- [x] **BOM 登记电压模块**：已知输出 3.3V/5V/12V；型号、额定电流、通道数、是否具备逻辑电平转换均待到货实测（不臆测）→ bom.md 增加「电压模块待测登记表」
- [x] **wiring.md 写供电两路**（新建 hardware/wiring.md）：
  - 路线 A：到货测模块 5V 带载 ≥2A → 供电主控+OLED+SU-03T，灯带低亮度
  - 路线 B：灯带独立 5V/≥4A 电源，与主控共地不共线
- [x] 确认 DIN 串 330Ω、灯带电源端并 100μF（闪烁/复位再加大到 470~1000μF）→ 写入 wiring.md §3

### 3. 引脚与语音命令表（Day 2 第 5 项）✅ 已完成
- [x] 确认引脚初稿（I2C=GPIO8/9，WS2812 DIN=GPIO38 经电平转换，按键10/11/12/13，蜂鸣器 GPIO3，SU-03T=UART2 GPIO16/17）；标注「待板复核，避开 strapping 引脚」→ 写入 src/config.h + docs/引脚与命令映射.md
- [x] SU-03T 8 条命令映射（打开灯/关闭灯/夜灯/暖光/阅读/关闹钟/再睡5分/开始日出）→ 需求文档 FR8 已有，新增 docs/引脚与命令映射.md 细化词条/协议/配置流程，协议格式待 M6 实测

### 4. 基础学习 + M1 例程预写（Day 2 第 6 项）✅ 已完成
- [x] 学 ESP32-S3 基础：strapping 引脚、`Wire.begin(SDA,SCL)`、PSRAM 开启 → 要点写入 config.h 注释与 docs/引脚与命令映射.md
- [x] 学 WS2812：共地、GRB 顺序、亮度限制、供电电流（60 颗全白≈3.6A）→ 要点写入 02_ws2812 代码注释与 wiring.md
- [x] **预写 `examples/01_blink`、`02_ws2812`**：先写先编译验证，板到再实测
- [x] commit：`feat: 预写 M1 Blink 与 WS2812 例程`

> 📌 例程编译记录（2026-08-21）：`01_blink` RAM 5.8%/Flash 8.3%（35s）；`02_ws2812` RAM 5.8%/Flash 8.4%（48s），均 `[SUCCESS]`。

---

## 三、P1 可选（板到前顺手做）
- [ ] 每天 10 分钟站会自检（写本文件底部）
- [ ] `hardware/wiring.md` 接线图初稿（ASCII/mermaid，板到补照片）

---

## 四、明确延后（不今天做）
- ⏸ USB 驱动安装（板未到，无法确认 CH340/CP210x/原生 CDC）→ 到货第一天
- ⏸ 实物点灯 / RTC 读时 / 语音实测 → 硬件到货后

---

## 五、时间预算

| 任务 | 预计耗时 |
|---|---:|
| PlatformIO 安装 + 编译 | 30 min |
| 设计文档定稿（BOM + wiring） | 30 min |
| 引脚表 + SU-03T 命令 | 30 min |
| 基础学习 + M1 例程预写 | 60 min |
| **合计** | **~2.5 h** |

---

## 六、站会自检（2026-08-21 回填）

### 今天完成
- [x] PlatformIO 工程编译通过（RAM 5.6%/Flash 7.9%）
- [x] 设计文档定稿（BOM 电压模块登记表 + wiring.md 供电两路）
- [x] 引脚初稿 + SU-03T 8 命令映射（config.h + docs/引脚与命令映射.md）
- [x] M1 例程预写并编译（examples/01_blink、02_ws2812）

### 遇到问题
- 无（硬件未到，均为纯软件任务）

### 解决方案
- —

### 明天计划
- 硬件到货则执行「到货第一天核对清单」（wiring.md §4 顺序）；
- 未到货则做 P1 项：站会自检、wiring 接线图照片版，或推进 M2 例程预写（OLED/DS3231）。

---

> Mentor 提醒：每完成一项 commit 一次；例程先写先编译，板到即测，别等全到齐才动手。
