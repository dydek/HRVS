#include <State.h>
#include <LiquidCrystal_I2C.h>
#include <HRVSMenu.h>
#include <Utils.h>
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
HRVSMenu::HRVSMenu()
{
    this->lcd = new LiquidCrystal_I2C(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
}

void HRVSMenu::begin()
{

    this->menu = new LiquidMenu(*(this->lcd));
    this->lcd->begin(20, 4);

    this->register_glyphs();
    this->init_menu();

    this->menu->add_screen(*this->menu_screen_0);
    //this->menu->add_screen(*this->menu_screen_1);
    this->menu->add_screen(*this->menu_screen_2);
    this->menu->add_screen(*this->menu_screen_3);

    this->menu->change_screen(*this->menu_screen_0);
}

void HRVSMenu::init_menu()
{
    this->menu_0_lines[0] = new LiquidLine(1, 0, menu_0_text1);
    this->menu_0_lines[0]->set_asProgmem(1);
    this->menu_0_lines[1] = new LiquidLine(0, 1, current_values.in_temp_pre_chr_ptr);
    this->menu_0_lines[2] = new LiquidLine(6, 1, degree_index, "C");
    this->menu_0_lines[2]->set_asGlyph(1);

    this->menu_0_lines[3] = new LiquidLine(12, 2, menu_0_text2);
    this->menu_0_lines[3]->set_asProgmem(1);

    this->menu_0_lines[4] = new LiquidLine(12, 3, current_values.in_temp_post_chr_ptr);
    this->menu_0_lines[5] = new LiquidLine(18, 3, degree_index, "C");
    this->menu_0_lines[5]->set_asGlyph(1);

    this->menu_0_lines[6] = new LiquidLine(12, 0, menu_0_text3);
    this->menu_0_lines[6]->set_asProgmem(1);

    this->menu_0_lines[7] = new LiquidLine(12, 1, current_values.out_temp_pre_chr_ptr);
    this->menu_0_lines[8] = new LiquidLine(18, 1, degree_index, "C");
    this->menu_0_lines[8]->set_asGlyph(1);

    this->menu_0_lines[9] = new LiquidLine(1, 2, menu_0_text4);
    this->menu_0_lines[9]->set_asProgmem(1);
    this->menu_0_lines[10] = new LiquidLine(0, 3, current_values.out_temp_post_chr_ptr);
    this->menu_0_lines[11] = new LiquidLine(6, 3, degree_index, "C");
    this->menu_0_lines[11]->set_asGlyph(1);

    this->menu_screen_0 = new LiquidScreen();
    this->build_screen(this->menu_screen_0, this->menu_0_lines, 12);

    // screen 2
    // this->menu_1_lines[0] = new LiquidLine(0, 0, fan1_index);
    // this->menu_1_lines[0]->set_asGlyph(1);

    // this->menu_1_lines[1] = new LiquidLine(3, 0, current_values.in_fan_speed, "rpm");

    // this->menu_1_lines[2] = new LiquidLine(0, 1, fan2_index);
    // this->menu_1_lines[2]->set_asGlyph(1);

    // this->menu_1_lines[3] = new LiquidLine(3, 3, current_values.out_fan_speed, "rpm");

    // this->menu_screen_1 = new LiquidScreen();
    // this->build_screen(this->menu_screen_1, this->menu_1_lines, 4);

    this->line3_1 = new LiquidLine(0, 0, menu_2_text1);
    this->line3_1->set_asProgmem(1);
    // this->line3_2 = new LiquidLine(0, 1, current_values.in_humidity);
    // this->line3_3 = new LiquidLine(8, 1, current_values.out_humidity);
    this->menu_screen_2 = new LiquidScreen(*this->line3_1); //, *this->line3_2, *this->line3_3);

    this->build_speed_screen();
}

void HRVSMenu::build_speed_screen()
{
    this->line4_1 = new LiquidLine(0, 0, menu_3_text1);
    this->line4_1->set_asProgmem(1);
    // this->line4_2 = new LiquidLine(10, 0, "Test");

    this->menu_screen_3 = new LiquidScreen(*this->line4_1); //*this->line4_2);
}

void HRVSMenu::register_glyphs()
{
    this->lcd->createChar(fan1_index, custom_glyps::fan1);
    this->lcd->createChar(fan2_index, custom_glyps::fan2);
    this->lcd->createChar(thermometer_index, custom_glyps::thermometer);
    this->lcd->createChar(cross_index, custom_glyps::cross);
    this->lcd->createChar(degree_index, custom_glyps::degree);
}

void HRVSMenu::next_screen()
{
    this->menu->next_screen();
}

void HRVSMenu::refresh()
{
    this->menu->update();
}

void HRVSMenu::call_function(uint8_t fn_type) {
    switch (fn_type)
    {
        case SHORT_CLICK_BUTTON_2:
            menu_function_increase_speed();
            refresh();
            break;
        case LONG_CLICK_BUTTON_2:
            menu_function_decrease_speed();
            refresh();
            break;
        default:
            break;
    }
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
