// disable main loop during testing
#ifndef UNIT_TEST

#include <Arduino.h>
#include <JC_Button.h>
#include <Thread.h>
#include <ThreadController.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <TimerOne.h>

#include <Engine.h>
#include <State.h>
#include <Controller.h>
#include <Menu2.h>
#include <Keyboard.h>
#include <AppFlow.h>

#include "Config.h"

Engine engine1(ENGINE_1_PIN);
Engine engine2(ENGINE_2_PIN);

Menu menu({LCD_RS_PIN,
           LCD_EN_PIN,
           LCD_D4_PIN,
           LCD_D5_PIN,
           LCD_D6_PIN,
           LCD_D7_PIN},
          &current_values);

AppFlow flow(&menu);

SimplyKeyboard keyboard2(BUTTON_PIN_1, BUTTON_PIN_2, &flow);

ThreadController controll = ThreadController();

Thread menuUpdateThread = Thread();

// DHT init
DHT_Unified dht_in(DHTPIN_IN, DHTTYPE);

void niceCallback()
{
    sensors_event_t event;
    dht_in.temperature().getEvent(&event);
    if (!isnan(event.temperature))
    {
        current_values.in_temp_pre = event.temperature;
        menu.refresh();
    }
}

uint32_t delayMS;

uint16_t counter = 0;
uint16_t brightness = 0;

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

void setup()
{
    Serial.begin(9600);

    dht_in.begin();

    delayMS = 2000;

    pinMode(9, OUTPUT);
    digitalWrite(9, LOW);
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);

    // Timer1.pwm(9, 0);
    // Timer1.pwm(10, 0);
    // Timer1.attachInterrupt(update_led);

    // threads
    menuUpdateThread.onRun(niceCallback);
    menuUpdateThread.setInterval(2000);

    controll.add(&menuUpdateThread);

    keyboard2.button_1_click_register(&AppFlow::button_1_click);
    keyboard2.button_2_click_register(&AppFlow::button_2_click);
    menu.begin();

    controll.run();
}

void loop()
{
    keyboard2.loop_tick();
}

#endif