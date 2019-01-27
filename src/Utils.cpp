#include <EEPROM.h>
#include <pins_arduino.h>
#include <TimerOne.h>
#include <State.h>
#include "Utils.h"
#include "Config.h"

void restore_state()
{
    uint8_t gear = EEPROM.read(0);
    if (gear <= MAX_GEAR)
    {
        current_values.fan_gear = gear;
        Serial.println(F("Data loaded from EEPROM"));
    }
}

void attach_interrupts_for_rpm()
{
    // pinMode(ENGINE_RPM_IN_PIN, INPUT_PULLUP);
    // attachInterrupt(digitalPinToInterrupt(ENGINE_RPM_IN_PIN), void(), CHANGE);

    // pinMode(ENGINE_RPM_OUT_PIN, INPUT_PULLUP);
    // attachInterrupt(digitalPinToInterrupt(ENGINE_RPM_OUT_PIN), void(), CHANGE);
}

void initialize_timers()
{
    pinMode(ENGINE_IN_PIN, OUTPUT);
    digitalWrite(ENGINE_IN_PIN, HIGH);
    pinMode(ENGINE_OUT_PIN, OUTPUT);
    digitalWrite(ENGINE_OUT_PIN, HIGH);

    // timers
    Timer1.initialize(50);
    Timer1.pwm(ENGINE_IN_PIN, 0);
    Timer1.pwm(ENGINE_OUT_PIN, 0);
}