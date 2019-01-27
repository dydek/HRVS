// disable main loop during testing
#ifndef UNIT_TEST

#include <Arduino.h>
#include <EEPROM.h>
#include <JC_Button.h>
#include <Thread.h>
#include <ThreadController.h>

#include <Engine.h>
#include <State.h>
#include <HRVSMenu.h>
#include <Keyboard.h>

#include "Config.h"
#include "Sensors.h"
#include "Tasks.h"
#include "Utils.h"

SimplyKeyboard keyboard2(BUTTON_PIN_1, BUTTON_PIN_2);

ThreadController controll;

Thread menuUpdateThread(updateMenu, 2000);
Thread DHT1UpdateThread(DHT1SensorUpdate, 25);
Thread DHT2UpdateThread(DHT2SensorUpdate, 25);
Thread D18B20UpdateThread(D18B20SensorsUpdate, 100);
Thread MotorSpeedThread(updateMotorSpeeds, 1000);
Thread CalculateOtherParametersThread(updateOtherParameters, 2000);


void setup()
{
    Serial.begin(9600);

    // set pin modes
    pinMode(BYPASS_RELAY, OUTPUT);
    pinMode(MOTOR_RELAY, OUTPUT);
    digitalWrite(MOTOR_RELAY, HIGH);
    digitalWrite(BYPASS_RELAY, HIGH);

    initialize_timers();
    initialize_sensors();

    controll.add(&menuUpdateThread);
    controll.add(&DHT1UpdateThread);
    controll.add(&DHT2UpdateThread);
    controll.add(&D18B20UpdateThread);
    controll.add(&MotorSpeedThread);
    controll.add(&CalculateOtherParametersThread);

    lcd_begin();
    
    lcd_show_init_screen();
    restore_state();
    _delay_ms(2500);
    build_screen_0();
}

void loop()
{
    controll.run();
    keyboard2.loop_tick();
}

#endif