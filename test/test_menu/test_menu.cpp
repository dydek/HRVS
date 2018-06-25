#include <Arduino.h>
#include <unity.h>

void test_example()
{
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_example);
    UNITY_END();
}

void loop()
{
    delay(500);
}