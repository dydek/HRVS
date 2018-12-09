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
#include <AppFlow.h>

#include "Config.h"
#include "Sensors.h"
// #include "Tasks.h"

Engine engine1(ENGINE_1_PIN);
Engine engine2(ENGINE_2_PIN);

HRVSMenu menu({LCD_RS_PIN,
               LCD_EN_PIN,
               LCD_D4_PIN,
               LCD_D5_PIN,
               LCD_D6_PIN,
               LCD_D7_PIN});

// AppFlow flow(&menu);

SimplyKeyboard keyboard2(BUTTON_PIN_1, BUTTON_PIN_2, &menu);

ThreadController controll = ThreadController();

Thread menuUpdateThread = Thread();
Thread DHT1UpdateThread = Thread();
Thread DHT2UpdateThread = Thread();
Thread D18B20UpdateThread = Thread();

// uint32_t delayMS;

uint16_t counter = 0;
uint16_t brightness = 0;
uint16_t lastCheck = 0;

void update_led()
{
    counter++;
    if (counter > 500)
    {
        brightness++;
        Timer1.pwm(9, brightness);
        Timer1.pwm(10, brightness);
        if (brightness > 1000)
            brightness = 0;
        counter = 0;
    }
}

void updateMenu()
{
    menu.refresh();
}

void setup()
{
    Serial.begin(9600);
    // delayMS = 2000;

    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);

    // Timer1.pwm(9, 0);
    // Timer1.pwm(10, 0);
    // Timer1.attachInterrupt(update_led);

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

    controll.add(&menuUpdateThread);
    controll.add(&DHT1UpdateThread);
    controll.add(&DHT2UpdateThread);
    controll.add(&D18B20UpdateThread);
    menu.begin();
}

void loop()
{
    controll.run();
    keyboard2.loop_tick();
}

#endif