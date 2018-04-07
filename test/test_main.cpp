#include <Arduino.h>
#include <unity.h>

#ifdef UNIT_TEST

void setUp(void) {
// set stuff up here
}

void tearDown(void) {
// clean stuff up here
}

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(LED_BUILTIN, 13);
}

#endif