//
// Created by Michał Dydecki on 19/11/2017.
//

#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal.h>
#include <LiquidMenu.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

LiquidLine welcome_line1(1, 0, "Hello Menu");

LiquidLine welcome_line2(1, 1, "Hello test 2");

LiquidScreen welcome_screen(welcome_line1, welcome_line2);

LiquidMenu my_menu(lcd, welcome_screen);

void setup() {
    Serial.begin(9600);
    Serial.println("Hello world!");

    lcd.begin(16, 2);
    my_menu.next_screen();
}

void loop() {
}

