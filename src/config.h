#ifndef CONFIG_H
#define CONFIG_H

// ============================================================
// 引脚与参数配置（骨架）
// 待 M1~M3 实测后定稿。ESP32-S3 默认 I2C 引脚与 ESP32 不同，
// 需查数据手册并显式指定（见 docs/预研计划.md）。
// ============================================================

// ---- WS2812 灯光 ----
#define WS2812_PIN       (待定)      // ESP32-S3 GPIO（3.3V，建议加 74HCT245 电平转换）
#define WS2812_COUNT     16          // 灯环 16 颗（V1 ≤ 30）

// ---- I2C（OLED + DS3231 共用）----
// ESP32-S3 默认 I2C 引脚需确认，下面先占位，实测定稿
#define I2C_SDA          (待定)
#define I2C_SCL          (待定)
#define OLED_ADDR        0x3C
#define RTC_ADDR         0x68

// ---- 按键（MODE / ADD / SUB / OK）----
#define KEY_MODE_PIN     (待定)
#define KEY_ADD_PIN      (待定)
#define KEY_SUB_PIN      (待定)
#define KEY_OK_PIN       (待定)

// ---- 蜂鸣器 ----
#define BUZZER_PIN       (待定)

// ---- 语音模块 UART ----
#define VOICE_RX_PIN     (待定)      // 接语音模块 TX
#define VOICE_TX_PIN     (待定)      // 接语音模块 RX
#define VOICE_UART_BAUD  9600

// ---- 业务参数默认值 ----
#define DEFAULT_SNOOZE_MIN   5
#define SUNRISE_LEAD_DEFAULT 20      // 日出提前分钟（10/20/30）
#define MAX_BRIGHTNESS_LEVEL 5

#endif // CONFIG_H
