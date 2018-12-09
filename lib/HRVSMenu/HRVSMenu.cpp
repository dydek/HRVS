#include <State.h>
#include <HRVSMenu.h>
#include "glyphs.h"

void menu_function_increase_speed()
{

    if (current_values.fan_gear < MAX_GEAR)
    {
        current_values.fan_gear++;
    }
}

void menu_function_decrease_speed()
{
    if (current_values.fan_gear > 0)
    {
        current_values.fan_gear--;
    }
}

/**
 * 
 * 
 */
HRVSMenu::HRVSMenu(LcdConfig config)
{
    this->lcd = new LiquidCrystal(
        config.rs_pin,
        config.en_pin,
        config.d4_pin,
        config.d5_pin,
        config.d6_pin,
        config.d7_pin);
    this->register_glyphs();
    this->init_menu();
}

void HRVSMenu::begin()
{

    this->menu = new LiquidMenu(*(this->lcd));
    this->lcd->begin(16, 2);

    this->menu->add_screen(*this->menu_screen_0);
    this->menu->add_screen(*this->menu_screen_1);
    this->menu->add_screen(*this->menu_screen_2);
    this->menu->add_screen(*this->menu_screen_3);

    this->menu->change_screen(*this->menu_screen_0);
}

void HRVSMenu::init_menu()
{
    // this->line1_1 = new LiquidLine(0, 0, "Tmp:");
    // this->line1_2 = new LiquidLine(0, 1, current_values.in_temp_pre);
    // this->menu_screen_0 = new LiquidScreen(*this->line1_1, *this->line1_2);
    // screen 0
    // this->menu_0_lines[0] = new LiquidLine(0, 0, thermometer_index);
    // this->menu_0_lines[0]->set_asGlyph(1);

    this->menu_0_lines[0] = new LiquidLine(1, 0, current_values.in_temp_pre, "C");
    this->menu_0_lines[1] = new LiquidLine(10, 1, current_values.in_temp_post, "C");
    this->menu_0_lines[2] = new LiquidLine(10, 0, current_values.out_temp_pre, "C");
    this->menu_0_lines[3] = new LiquidLine(1, 1, current_values.out_temp_post, "C");
    this->menu_screen_0 = new LiquidScreen();
    this->build_screen(this->menu_screen_0, this->menu_0_lines, 4);

    // screen 2
    this->menu_1_lines[0] = new LiquidLine(0, 0, fan1_index);
    this->menu_1_lines[0]->set_asGlyph(1);

    this->menu_1_lines[1] = new LiquidLine(3, 0, current_values.in_fan_speed, "rpm");

    this->menu_1_lines[2] = new LiquidLine(0, 1, fan2_index);
    this->menu_1_lines[2]->set_asGlyph(1);

    this->menu_1_lines[3] = new LiquidLine(3, 3, current_values.out_fan_speed, "rpm");

    this->menu_screen_1 = new LiquidScreen();
    this->build_screen(this->menu_screen_1, this->menu_1_lines, 4);

    this->line3_1 = new LiquidLine(0, 0, "Humidity:");
    this->line3_2 = new LiquidLine(0, 1, current_values.in_humidity);
    this->line3_3 = new LiquidLine(8, 1, current_values.out_humidity);
    this->menu_screen_2 = new LiquidScreen(*this->line3_1, *this->line3_2, *this->line3_3);

    this->build_speed_screen();
}

void HRVSMenu::build_speed_screen()
{
    this->line4_1 = new LiquidLine(0, 0, "Speed set:");
    this->line4_2 = new LiquidLine(10, 0, current_values.fan_gear);
    this->line4_2->attach_function(short_click_button_2, menu_function_increase_speed);
    this->line4_2->attach_function(long_click_button_2, menu_function_decrease_speed);

    this->menu_screen_3 = new LiquidScreen(*this->line4_1, *this->line4_2);
    // this->menu_screen_3->set_focusPosition(1);
    this->menu_screen_3->set_focusPosition(Position::LEFT);
}

void HRVSMenu::register_glyphs()
{
    this->lcd->createChar(fan1_index, custom_glyps::fan1);
    this->lcd->createChar(fan2_index, custom_glyps::fan2);
    this->lcd->createChar(full_index, custom_glyps::full);
    this->lcd->createChar(thermometer_index, custom_glyps::thermometer);
}

void HRVSMenu::next_screen()
{
    this->menu->next_screen();
}

void HRVSMenu::refresh()
{
    this->menu->update();
}

/**
 * 
 * 
 */
void HRVSMenu::build_screen(LiquidScreen *screen, LiquidLine *lines[], uint8_t size)
{

    for (uint8_t i = 0; i < size; i++)
    {
        if (lines[i])
        {
            screen->add_line(*(lines[i]));
        }
    }
}
