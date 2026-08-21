// ============================================================
// M1 例程 02：WS2812B 灯带（预研 R1）
// 目标：验证 供电 / 共地 / 数据链路 / GRB 颜色顺序，低亮度安全起步
//
// ⚠️ 接线前必读：
//   1. 灯带 VCC 用独立 5V 电源（60 颗全白 ≈ 3.6A），与主控共地不共线
//   2. GPIO38(3.3V) → 330Ω → DIN；先试 3.3V 直驱，不稳再加 74HCT245 电平转换
//   3. 灯带 VCC/GND 间并 100μF（若闪烁/复位，加并 470~1000μF）
//   4. 本程序全程限亮度 ≤25%，避免大电流烧电源/灯带
//
// 阶段演示（每 4 秒切一阶段）：
//   ① 单颗红 @10%  → ② 全带 10% 白光 → ③ 暖光渐变爬升 → ④ 彩虹循环
// ============================================================

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define STRIP_PIN     38
#define STRIP_COUNT   60        // 实际 60 颗；测试建议临时改 16
#define BRIGHT_SAFE   25        // 全局亮度上限 25/255 ≈ 10%

#define PH_DURATION_MS 4000     // 每阶段 4 秒

Adafruit_NeoPixel strip(STRIP_COUNT, STRIP_PIN, NEO_GRB + NEO_KHZ800);

int     g_phase = 0;            // 0~3
uint32_t g_phaseStart = 0;

// 暖白 → 冷白的渐变插值（R/G/B）
void setWarmToWhite(uint8_t i, uint8_t bright) {
  // 从暖橙 (255,160,64) 渐变到白 (255,255,255)
  uint8_t g = map(bright, 0, 63, 160, 255);
  uint8_t b = map(bright, 0, 63, 64, 255);
  strip.setPixelColor(i, 255, g, b);
}

void nextPhase() {
  g_phase = (g_phase + 1) % 4;
  g_phaseStart = millis();
  strip.clear();
  strip.show();
  Serial.printf("[02_ws2812] phase %d\n", g_phase);
}

void loop() {
  uint32_t elapsed = millis() - g_phaseStart;

  // 阶段超时则切换
  if (elapsed >= PH_DURATION_MS) {
    nextPhase();
    return;
  }

  switch (g_phase) {
    case 0: {  // ① 单颗红 @10%：验证供电/共地/数据链
      strip.clear();
      strip.setPixelColor(0, 255, 0, 0);   // GRB 顺序，红 = (255,0,0)
      break;
    }
    case 1: {  // ② 全带 10% 白光：验证电流与电源
      for (int i = 0; i < STRIP_COUNT; i++) strip.setPixelColor(i, 255, 255, 255);
      break;
    }
    case 2: {  // ③ 暖光渐变爬升：亮度 0→63（约 25%）
      uint8_t bright = map(elapsed, 0, PH_DURATION_MS, 0, 63);
      for (int i = 0; i < STRIP_COUNT; i++) setWarmToWhite(i, bright);
      break;
    }
    case 3: {  // ④ 彩虹循环：动效 + 顺带测全色
      uint16_t hue = (elapsed / 20) % 360;
      for (int i = 0; i < STRIP_COUNT; i++) {
        strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(hue * 256, 255, 255)));
      }
      break;
    }
  }
  strip.show();   // 注意：每轮 loop 都 show()，不阻塞（无 delay）
}

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(BRIGHT_SAFE);   // 全局亮度上限，防止大电流
  strip.clear();
  strip.show();
  Serial.println("[02_ws2812] init OK - bright cap 10%, phase demo 4s each");
}
