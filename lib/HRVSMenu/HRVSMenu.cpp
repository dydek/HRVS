#include <EEPROM.h>
#include <State.h>
#include <LiquidCrystal_I2C.h>
#include <HRVSMenu.h>
#include <Utils.h>
#include "glyphs.h"

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// list of all screens update functions
void (*update_screens[5][4])() = {
    {build_screen_0, update_screen_0, nullptr, nullptr},
    {build_screen_1, update_screen_1, nullptr, nullptr},
    {build_screen_2, update_screen_2, nullptr, nullptr},
    {build_screen_3, update_screen_3, menu_function_increase_speed, menu_function_decrease_speed},
    {build_screen_4, update_screen_4, nullptr, button_2_long_click_screen_4}};

void lcd_show_init_screen()
{
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.write(fan1_index);
    lcd.print((__FlashStringHelper *)init_screen_text1);
    lcd.write(fan1_index);
    lcd.setCursor(1, 2);
    lcd.print((__FlashStringHelper *)init_screen_text2);
}

void menu_function_increase_speed()
{

    if (current_values.fan_gear < MAX_GEAR)
    {
        current_values.fan_gear++;
    }
    EEPROM.write(0, current_values.fan_gear);
    update_screen_3();
}

void menu_function_decrease_speed()
{
    if (current_values.fan_gear > 0)
    {
        current_values.fan_gear--;
    }
    EEPROM.write(0, current_values.fan_gear);
    update_screen_3();
}

void lcd_begin()
{
    lcd.begin(20, 4);
    lcd.createChar(fan1_index, custom_glyps::fan1);
    lcd.createChar(line_right_index, custom_glyps::line_right);
    lcd.createChar(line_left_index, custom_glyps::line_left);
    lcd.createChar(arrow_right_index, custom_glyps::arrow_right);
    lcd.createChar(arrow_left_index, custom_glyps::arrow_left);
}

void menu_next_screen()
{
    if (++_CURRENT_SCREEN_ID < sizeof(update_screens) / sizeof(*update_screens))
    {
        update_screens[_CURRENT_SCREEN_ID][0]();
        update_screens[_CURRENT_SCREEN_ID][1]();
    }
    else
    {
        _CURRENT_SCREEN_ID = 0;
        update_screens[0][0]();
        update_screens[0][1]();
    }
}

void build_screen_0()
{
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print((char)126);
    lcd.print((__FlashStringHelper *)menu_0_text1);

    _lcd_print_degree(6, 1);

    lcd.setCursor(12, 2);
    lcd.print((__FlashStringHelper *)menu_0_text2);
    lcd.setCursor(19, 2);
    lcd.print((char)126);

    _lcd_print_degree(18, 3);

    lcd.setCursor(12, 0);
    lcd.print((__FlashStringHelper *)menu_0_text3);
    lcd.print((char)127);

    _lcd_print_degree(18, 1);

    lcd.setCursor(0, 2);
    lcd.print((char)127);
    lcd.print((__FlashStringHelper *)menu_0_text4);
    _lcd_print_degree(6, 3);

    lcd.setCursor(9, 1);
    lcd.write(line_right_index);
    lcd.setCursor(10, 1);
    lcd.write(line_left_index);
    lcd.setCursor(9, 2);
    lcd.write(arrow_left_index);
    lcd.setCursor(10, 2);
    lcd.write(arrow_right_index);
}

void update_screen_0()
{
    lcd.setCursor(0, 1);
    lcd.print((char *)current_values.in_temp_pre_chr);

    lcd.setCursor(12, 3);
    lcd.print((char *)current_values.in_temp_post_chr);

    lcd.setCursor(12, 1);
    lcd.print((char *)current_values.out_temp_pre_chr);

    lcd.setCursor(0, 3);
    lcd.print((char *)current_values.out_temp_post_chr);
}

void build_screen_1()
{
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print((__FlashStringHelper *)menu_1_text1);

    lcd.setCursor(1, 1);
    lcd.print((__FlashStringHelper *)menu_1_text2);

    lcd.setCursor(1, 2);
    lcd.print((__FlashStringHelper *)menu_1_text3);

    lcd.setCursor(16, 1);
    lcd.print((__FlashStringHelper *)procent_chr);

    lcd.setCursor(16, 2);
    lcd.print((__FlashStringHelper *)procent_chr);
}

void update_screen_1()
{
    lcd.setCursor(10, 1);
    lcd.print(current_values.in_humidity);

    lcd.setCursor(10, 2);
    lcd.print(current_values.out_humidity);
}

void build_screen_2()
{
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print((__FlashStringHelper *)menu_2_text1);
    lcd.setCursor(1, 1);
    lcd.print((__FlashStringHelper *)menu_2_text2);
    lcd.setCursor(17, 1);
    lcd.print((__FlashStringHelper *)procent_chr);
}

void update_screen_2()
{
    lcd.setCursor(12, 1);
    lcd.print(current_values.heat_efficiency);
}

void build_screen_3()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print((__FlashStringHelper *)menu_3_text1);

    lcd.setCursor(0, 1);
    lcd.print((__FlashStringHelper *)menu_3_text2);

    lcd.setCursor(0, 2);
    lcd.print((__FlashStringHelper *)menu_3_text3);

    lcd.setCursor(0, 3);
    lcd.print((__FlashStringHelper *)menu_3_text4);
}

void update_screen_3()
{
    lcd.setCursor(15, 1);
    lcd.print(current_values.fan_gear);

    lcd.setCursor(15, 2);
    lcd.print(current_values.in_fan_speed);

    lcd.setCursor(15, 3);
    lcd.print(current_values.out_fan_speed);
}

// bypass
void build_screen_4()
{
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print((__FlashStringHelper *)menu_4_text1);
}
void update_screen_4()
{
    lcd.setCursor(8, 0);
    lcd.print((__FlashStringHelper *)(current_values.bypass_open ? opened_chr : closed_chr));
}

/**
 * Toggle bypass + refresh the screen
 */
void button_2_long_click_screen_4()
{
    current_values.bypass_open = !current_values.bypass_open;
    update_screen_4();
}

void update_current_screen()
{
    update_screens[_CURRENT_SCREEN_ID][1]();
}

void button_2_long_click_current_screen()
{
    SAFE_CALL(update_screens[_CURRENT_SCREEN_ID][3]);
}

void button_2_click_current_screen()
{
    SAFE_CALL(update_screens[_CURRENT_SCREEN_ID][2]);
}

void _lcd_print_degree(uint8_t column, uint8_t row)
{
    lcd.setCursor(column, row);
    lcd.print((char)223);
    lcd.setCursor(column + 1, row);
    lcd.print((__FlashStringHelper *)celsius_chr);
}