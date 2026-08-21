// ============================================================
// M1 例程 01：Blink —— 验证烧录链路 / 串口 / GPIO 输出
// 板到第一天第一件事：先跑通这个，再谈别的。
// 接线：GPIO2 ——330Ω—— 任意 LED 阳极，LED 阴极接 GND
//      （GPIO2 非 strapping，安全；不接 LED 也能看串口输出）
// ============================================================

#include <Arduino.h>

#define TEST_LED_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(TEST_LED_PIN, OUTPUT);
  Serial.println("[01_blink] setup OK - LED on GPIO2, toggle 500ms");
}

void loop() {
  digitalWrite(TEST_LED_PIN, HIGH);
  Serial.printf("[01_blink] %lu ms ON\n", millis());
  delay(500);

  digitalWrite(TEST_LED_PIN, LOW);
  Serial.printf("[01_blink] %lu ms OFF\n", millis());
  delay(500);
}
