#include <Arduino.h>
#include <unity.h>
#include "Config.h"

void test_lcd_config(void) {
    UNITY_TEST_ASSERT_NOT_NULL(LCD_RS_PIN, 6 , "message");
}

void test_engine_config(void) {

}

void test_dht_config(void) {

}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_lcd_config);
    RUN_TEST(test_engine_config);
    RUN_TEST(test_dht_config);
    UNITY_END();
}


void loop() {
    delay(500);
}
