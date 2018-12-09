// disable main loop during testing
#ifndef UNIT_TEST

#include <Arduino.h>
#include <JC_Button.h>
#include <Thread.h>
#include <ThreadController.h>

#include <TimerOne.h>

#include <Engine.h>
#include <State.h>
#include <Controller.h>
#include <HRVSMenu.h>
#include <Keyboard.h>

#include "Config.h"
#include "Sensors.h"
#include "Tasks.h"

Engine engine1(ENGINE_1_PIN);
Engine engine2(ENGINE_2_PIN);

HRVSMenu menu({LCD_RS_PIN,
               LCD_EN_PIN,
               LCD_D4_PIN,
               LCD_D5_PIN,
               LCD_D6_PIN,
               LCD_D7_PIN});

SimplyKeyboard keyboard2(BUTTON_PIN_1, BUTTON_PIN_2, &menu);

ThreadController controll;

Thread menuUpdateThread; 
Thread DHT1UpdateThread; 
Thread DHT2UpdateThread; 
Thread D18B20UpdateThread; 
Thread MotorSpeedThread;


void updateMenu()
{
    menu.refresh();
}

void setup()
{
    Serial.begin(9600);

    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);

    Timer1.initialize(50);
    Timer1.pwm(9, 0);
    Timer1.pwm(10, 0);

    configureSensors();

    // threads
    menuUpdateThread.onRun(updateMenu);
    menuUpdateThread.setInterval(500);

    DHT1UpdateThread.onRun(DHT1SensorUpdate);
    DHT1UpdateThread.setInterval(5);

    DHT2UpdateThread.onRun(DHT2SensorUpdate);
    DHT2UpdateThread.setInterval(5);

    D18B20UpdateThread.onRun(D18B20SensorsUpdate);
    D18B20UpdateThread.setInterval(100);

    MotorSpeedThread.onRun(updateMotorSpeeds);
    MotorSpeedThread.setInterval(1000);

    controll.add(&menuUpdateThread);
    controll.add(&DHT1UpdateThread);
    controll.add(&DHT2UpdateThread);
    controll.add(&D18B20UpdateThread);
    controll.add(&MotorSpeedThread);
    menu.begin();
}

void loop()
{
    controll.run();
    keyboard2.loop_tick();
}

#endif