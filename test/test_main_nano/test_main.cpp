#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include <unity.h>


void setUp(void) {
// set stuff up here
}

void tearDown(void) {
// clean stuff up here
}

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(LED_BUILTIN, 13);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_led_builtin_pin_number);
    // RUN_TEST(test_proper_config);
    UNITY_END();
}


void loop() {
    delay(500);
}

#endif