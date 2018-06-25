#include <Arduino.h>
#include <unity.h>

#include "Engine.h"
#include "Controller.h"

Engine *engine_intake_ptr;
Engine *engine_outake_ptr;

void setUp(void)
{
    Engine engine_intake(1);
    Engine engine_outake(2);
    engine_intake_ptr = &engine_intake;
    engine_outake_ptr = &engine_outake;
}

void tearDown(void)
{
    // clean stuff up here
}

void test_controller_start(void)
{
    Controller controller(
        engine_intake_ptr,
        engine_outake_ptr);
    controller.start();
    CurrentSpeeds current_speeds = controller.get_current_speeds();
    TEST_ASSERT_EQUAL(10, current_speeds.engine_intake_speed);
    TEST_ASSERT_EQUAL(10, current_speeds.engine_outake_speed);
}

void test_controller_set_engines_speeds(void)
{
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_controller_start);
    RUN_TEST(test_controller_set_engines_speeds);
    UNITY_END();
}

void loop()
{
    delay(500);
}