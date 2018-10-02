#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include <unity.h>

#include <Keyboard.h>

void test_keyboard_press_short()
{
    SimplyKeyboard keyboard(A5, A4);
    
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_keyboard_press_short);
    UNITY_END();
}

void loop()
{
    delay(500);
}

#endif