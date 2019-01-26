// disable main loop during testing
#ifndef UNIT_TEST

#include <Arduino.h>
#include <JC_Button.h>
#include <Thread.h>
#include <ThreadController.h>

// #include <TimerOne.h>

#include <Engine.h>
#include <State.h>
// #include <Controller.h>
#include <HRVSMenu.h>
#include <Keyboard.h>

#include <MemoryFree.h>
#include <pgmStrToRAM.h>

#include "Config.h"
#include "Sensors.h"
#include "Tasks.h"

HRVSMenu menu;

SimplyKeyboard keyboard2(BUTTON_PIN_1, BUTTON_PIN_2, &menu);

void updateMenu()
{
    update_chr_variables();
    menu.refresh();
    Serial.print(F("Free RAM = "));
    Serial.println(freeMemory());
}

ThreadController controll;

Thread menuUpdateThread(updateMenu, 2000);
Thread DHT1UpdateThread(DHT1SensorUpdate, 25);
Thread DHT2UpdateThread(DHT2SensorUpdate, 25);
Thread D18B20UpdateThread(D18B20SensorsUpdate, 100);
Thread MotorSpeedThread(updateMotorSpeeds, 1000);
Thread CalculateOtherParametersThread(updateOtherParameters, 1000);

void setup()
{
    Serial.begin(9600);

    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);

    // Timer1.initialize(50);
    // Timer1.pwm(9, 0);
    // Timer1.pwm(10, 0);

    configureSensors();

    controll.add(&menuUpdateThread);
    controll.add(&DHT1UpdateThread);
    controll.add(&DHT2UpdateThread);
    controll.add(&D18B20UpdateThread);
    controll.add(&MotorSpeedThread);
    menu.begin();

    Serial.println(F("--- START ---"));
    
}

void loop()
{
    controll.run();
    keyboard2.loop_tick();
}

#endif