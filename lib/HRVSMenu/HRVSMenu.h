#pragma once

// #include <Arduino.h>
#include <avr/pgmspace.h>
#include <LiquidCrystal_I2C.h>
#include <State.h>

#define SHORT_CLICK_BUTTON_1 1
#define SHORT_CLICK_BUTTON_2 2
#define LONG_CLICK_BUTTON_1 3
#define LONG_CLICK_BUTTON_2 4

#define SAFE_CALL(funcPtr) ((funcPtr) != nullptr ? (funcPtr)() : (void()))

const uint8_t fan1_index = 0;
const uint8_t fan2_index = 1;
const uint8_t thermometer_index = 2;
const uint8_t line_right_index = 3;
const uint8_t line_left_index = 4;
const uint8_t arrow_right_index = 5;
const uint8_t arrow_left_index = 6;

const char init_screen_text1[] PROGMEM = "Dydo reku v. 0.1";
const char init_screen_text2[] PROGMEM = "Checking status...";
const char menu_0_text1[] PROGMEM = "Intake";
const char menu_0_text2[] PROGMEM = "Air in";
const char menu_0_text3[] PROGMEM = "Air out";
const char menu_0_text4[] PROGMEM = "Outtake";
const char menu_1_text1[] PROGMEM = "Humidity";
const char menu_1_text2[] PROGMEM = "Air in:";
const char menu_1_text3[] PROGMEM = "Air out:";
const char menu_2_text1[] PROGMEM = "Heat exchange";
const char menu_2_text2[] PROGMEM = "efficiency:";
const char menu_3_text1[] PROGMEM = "Motors";
const char menu_3_text2[] PROGMEM = "Gear:";
const char menu_3_text3[] PROGMEM = "IN motor RPM:";
const char menu_3_text4[] PROGMEM = "OUT motor RPM:";
const char menu_4_text1[] PROGMEM = "Bypass:";
const char celsius_chr[] PROGMEM = "C";
const char procent_chr[] PROGMEM = "%";
const char opened_chr[] PROGMEM = "OPENED";
const char closed_chr[] PROGMEM = "CLOSED";

void lcd_begin();
void lcd_show_init_screen();

void update_current_screen();
void menu_next_screen();

void build_screen_0();
void update_screen_0();

void build_screen_1();
void update_screen_1();

void build_screen_2();
void update_screen_2();

void build_screen_3();
void update_screen_3();

void menu_function_increase_speed();
void menu_function_decrease_speed();

void build_screen_4();
void update_screen_4();
void button_2_long_click_screen_4();

void button_2_long_click_current_screen();
void button_2_click_current_screen();

void _lcd_print_degree(uint8_t, uint8_t);

// 


static uint8_t _CURRENT_SCREEN_ID = 0;

