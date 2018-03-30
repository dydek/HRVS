//
// Created by Michał Dydecki on 19/11/2017.
//

#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal.h>
#include <LiquidMenu.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <TimerOne.h>

#include "Config.h"
#include "Engine.h"

struct CurrentValues
{
    bool bypass_open = false;
};

LiquidCrystal lcd(
    LCD_RS_PIN,
    LCD_EN_PIN,
    LCD_D4_PIN,
    LCD_D5_PIN,
    LCD_D6_PIN,
    LCD_D7_PIN);

LiquidLine welcome_line1(1, 0, "Hello Menu");

LiquidLine welcome_line2(1, 1, "Hello test 2");

LiquidScreen welcome_screen(welcome_line1, welcome_line2);

LiquidMenu my_menu(lcd, welcome_screen);

Engine engine1(ENGINE_1_PIN);

Engine engine2(ENGINE_2_PIN);

// DHT init
DHT_Unified dht_in(DHTPIN_IN, DHTTYPE);

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
    lcd.begin(16, 2);

    dht_in.begin();

    my_menu.next_screen();
    volatile CurrentValues current_values;
    Engine::init();

    delayMS = 2000;

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    Timer1.initialize(40);

    Timer1.pwm(9, 0);
    Timer1.pwm(10, 0);
    Timer1.attachInterrupt(update_led);
}

void loop()
{
    delay(delayMS);

    float value;
    value = millis();
    // Get temperature event and print its value.
    sensors_event_t event;
    dht_in.temperature().getEvent(&event);
    if (isnan(event.temperature))
    {
        Serial.println("Error reading temperature!");
    }
    else
    {
        Serial.print("Temperature: ");
        Serial.print(event.temperature);
        Serial.println(" *C");
    }
    // Get humidity event and print its value.
    dht_in.humidity().getEvent(&event);
    if (isnan(event.relative_humidity))
    {
        Serial.println("Error reading humidity!");
    }
    else
    {
        Serial.print("Humidity: ");
        Serial.print(event.relative_humidity);
        Serial.println("%");
    }
    Serial.println(millis() - value);
}
