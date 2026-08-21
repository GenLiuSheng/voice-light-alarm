#ifndef CONFIG_H
#define CONFIG_H

// ============================================================
// 引脚与参数配置（初稿，2026-08-21 Day 3 定稿）
// ⚠️ 待板到实测复核后再视为定稿（见 hardware/wiring.md §3）
// 避让原则：
//   - strapping 引脚：GPIO0 / 3 / 45 / 46（上电时序敏感）
//   - USB 专用：GPIO19 / 20
//   - N16R8 octal PSRAM 占用 GPIO33~37，勿用作外部功能
// ============================================================

// ---- WS2812 灯光 ----
// GPIO38：3.3V 逻辑，DIN 需 5V → 电平转换（74HCT245 或灯环自带），串 330Ω
#define WS2812_PIN       38
#define WS2812_COUNT     60          // 实际灯带 60 颗（V1 全亮需独立电源，默认限亮度）

// ---- I2C（OLED + DS3231 共用总线）----
#define I2C_SDA          8
#define I2C_SCL          9
#define OLED_ADDR        0x3C        // SSD1315（SSD1306 指令兼容）
#define RTC_ADDR         0x68        // DS3231

// ---- 按键（MODE / ADD / SUB / OK）----
#define KEY_MODE_PIN     10
#define KEY_ADD_PIN      11
#define KEY_SUB_PIN      12
#define KEY_OK_PIN       13

// ---- 蜂鸣器 ----
// ⚠️ GPIO3 为 strapping 引脚（JTAG 选择）；板到如影响启动，改 GPIO5/14/15
#define BUZZER_PIN       3

// ---- 语音模块 SU-03T（UART2）----
#define VOICE_RX_PIN     16          // 接模块 TX
#define VOICE_TX_PIN     17          // 接模块 RX
#define VOICE_UART_BAUD  9600        // 默认波特率，待 M6 实测确认

// ---- 业务参数默认值 ----
#define DEFAULT_SNOOZE_MIN   5
#define SUNRISE_LEAD_DEFAULT 20      // 日出提前分钟（10/20/30）
#define MAX_BRIGHTNESS_LEVEL 5

#endif // CONFIG_H
