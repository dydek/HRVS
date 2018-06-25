#include <Arduino.h>
#include <unity.h>

#include "Engine.h"

void setUp(void) {
    
}

void tearDown(void) {
// clean stuff up here
}

void test_engine_switch_off(void) {
    Engine engine(1);
    engine.set_speed(10);
    engine.switch_off();
    TEST_ASSERT_EQUAL(engine.get_current_speed(), 0);
}

void test_engine_set_speed(void) {
    Engine engine(1);
    engine.set_speed(40);
    TEST_ASSERT_EQUAL(40, engine.get_current_speed());
}

void test_set_engine_max_speed(void) {
    Engine engine(1);
    engine.set_speed(150);
    TEST_ASSERT_EQUAL(100, engine.get_current_speed());
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_engine_switch_off);
    RUN_TEST(test_engine_set_speed);
    RUN_TEST(test_set_engine_max_speed);
    UNITY_END();
}


void loop() {
    delay(500);
}