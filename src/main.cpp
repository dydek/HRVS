//
// Created by Michał Dydecki on 19/11/2017.
//

#include <Arduino.h>
#include <Bounce2.h>
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
#include <Menu.h>

#include "Config.h"

#define BUTTON_PIN_1 A5
#define BUTTON_PIN_2 A4

volatile CurrentValues current_values;

Engine engine1(ENGINE_1_PIN);
Engine engine2(ENGINE_2_PIN);

Menu menu({LCD_RS_PIN,
           LCD_EN_PIN,
           LCD_D4_PIN,
           LCD_D5_PIN,
           LCD_D6_PIN,
           LCD_D7_PIN},
           &current_values);


Button button1(BUTTON_PIN_1);
Button button2(BUTTON_PIN_2);

ThreadController controll = ThreadController();

Thread menuUpdateThread = Thread();

// DHT init
DHT_Unified dht_in(DHTPIN_IN, DHTTYPE);

void niceCallback(){
	sensors_event_t event;
    dht_in.temperature().getEvent(&event);
    if (isnan(event.temperature))
    {
        // Serial.println("Error reading temperature!");
    }
    else
    {
        // Serial.print("Temperature: ");
        current_values.in_temp_pre = event.temperature;
        // Serial.print(current_values.in_temp_pre);
        // Serial.println(" *C");
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
    digitalWrite(9, HIGH);
    // pinMode(10, OUTPUT);
    // Timer1.initialize(40);

    // Timer1.pwm(9, 0);
    // Timer1.pwm(10, 0);
    // Timer1.attachInterrupt(update_led);

    // threads
    menuUpdateThread.onRun(niceCallback);
    menuUpdateThread.setInterval(2000);

    controll.add(&menuUpdateThread);

    menu.begin();

    button1.begin();
    button2.begin();
}

unsigned int period_nextScreen = 5000;
unsigned long lastMs_nextScreen = 0;

void loop()
{
    button1.read();
    button2.read();

    if (button1.wasPressed()) {
        menu.next_screen();
        Serial.println("short click");
    }

    if (button1.pressedFor(500) && button1.wasReleased()) {
        menu.next_screen();
        Serial.println("long click");
    }

    if (button2.wasPressed()) {
        current_values.fan_speed += 1;
    }

    // float value;
    // value = millis();
    // // Get temperature event and print its value.
    // // Get humidity event and print its value.
    // dht_in.humidity().getEvent(&event);
    // if (isnan(event.relative_humidity))
    // {
    //     Serial.println("Error reading humidity!");
    // }
    // else
    // {
    //     Serial.print("Humidity: ");
    //     Serial.print(event.relative_humidity);
    //     Serial.println("%");
    // }
    controll.run();
}
