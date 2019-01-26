#include <State.h>
#include <LiquidCrystal_I2C.h>
#include <HRVSMenu.h>
#include <Utils.h>
#include "glyphs.h"

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// list of all screens update functions
void (*update_screens[4])() = {update_screen_0, update_screen_1, update_screen_2, update_screen_3};

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

void lcd_begin()
{
    lcd.begin(20, 4);
    lcd.createChar(fan1_index, custom_glyps::fan1);
    lcd.createChar(line_right_index, custom_glyps::line_right);
    lcd.createChar(line_left_index, custom_glyps::line_left);
    lcd.createChar(arrow_right_index, custom_glyps::arrow_right);
    lcd.createChar(arrow_left_index, custom_glyps::arrow_left);
    build_screen_0();
}

void menu_next_screen()
{
    switch (++_CURRENT_SCREEN_ID)
    {
    case 0:
        build_screen_0();
        update_screen_0();
        break;

    case 1:
        build_screen_1();
        update_screen_1();
        break;

    case 2:
        build_screen_2();
        update_screen_2();
        break;

    case 3:
        build_screen_3();
        update_screen_3();
        break;

    default:
        _CURRENT_SCREEN_ID = -1;
        menu_next_screen();
        break;
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

void update_current_screen()
{
    update_screens[_CURRENT_SCREEN_ID]();
}

void _lcd_print_degree(uint8_t column, uint8_t row)
{
    lcd.setCursor(column, row);
    lcd.print((char)223);
    lcd.setCursor(column + 1, row);
    lcd.print((__FlashStringHelper *)celsius_chr);
}

/**
 * 
 * 
 */
// HRVSMenu::HRVSMenu()
// {
//     this->lcd = new LiquidCrystal_I2C(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// }

// void HRVSMenu::begin()
// {

//     // this->menu = new LiquidMenu(*(this->lcd));
//     this->lcd->begin(20, 4);

//     this->register_glyphs();
//     this->init_menu();

//this->menu->add_screen(*this->menu_screen_0);
//this->menu->add_screen(*this->menu_screen_1);
//this->menu->add_screen(*this->menu_screen_2);
//this->menu->add_screen(*this->menu_screen_3);

//this->menu->change_screen(*this->menu_screen_0);
//}

// void HRVSMenu::init_menu()
// {
// this->menu_0_lines[0] = new LiquidLine(1, 0, menu_0_text1);
// this->menu_0_lines[0]->set_asProgmem(1);
// this->menu_0_lines[1] = new LiquidLine(0, 1, current_values.in_temp_pre_chr_ptr);
// this->menu_0_lines[2] = new LiquidLine(6, 1, degree_index, "C");
// this->menu_0_lines[2]->set_asGlyph(1);

// this->menu_0_lines[3] = new LiquidLine(12, 2, menu_0_text2);
// this->menu_0_lines[3]->set_asProgmem(1);

// this->menu_0_lines[4] = new LiquidLine(12, 3, current_values.in_temp_post_chr_ptr);
// this->menu_0_lines[5] = new LiquidLine(18, 3, degree_index, "C");
// this->menu_0_lines[5]->set_asGlyph(1);

// this->menu_0_lines[6] = new LiquidLine(12, 0, menu_0_text3);
// this->menu_0_lines[6]->set_asProgmem(1);

// this->menu_0_lines[7] = new LiquidLine(12, 1, current_values.out_temp_pre_chr_ptr);
// this->menu_0_lines[8] = new LiquidLine(18, 1, degree_index, "C");
// this->menu_0_lines[8]->set_asGlyph(1);

// this->menu_0_lines[9] = new LiquidLine(1, 2, menu_0_text4);
// this->menu_0_lines[9]->set_asProgmem(1);
// this->menu_0_lines[10] = new LiquidLine(0, 3, current_values.out_temp_post_chr_ptr);
// this->menu_0_lines[11] = new LiquidLine(6, 3, degree_index, "C");
// this->menu_0_lines[11]->set_asGlyph(1);

// this->menu_screen_0 = new LiquidScreen();
// this->build_screen(this->menu_screen_0, this->menu_0_lines, 12);

// screen 2
// this->menu_1_lines[0] = new LiquidLine(0, 0, fan1_index);
// this->menu_1_lines[0]->set_asGlyph(1);

// this->menu_1_lines[1] = new LiquidLine(3, 0, current_values.in_fan_speed, "rpm");

// this->menu_1_lines[2] = new LiquidLine(0, 1, fan2_index);
// this->menu_1_lines[2]->set_asGlyph(1);

// this->menu_1_lines[3] = new LiquidLine(3, 3, current_values.out_fan_speed, "rpm");

// this->menu_screen_1 = new LiquidScreen();
// this->build_screen(this->menu_screen_1, this->menu_1_lines, 4);

// this->line3_1 = new LiquidLine(0, 0, menu_2_text1);
// this->line3_1->set_asProgmem(1);
// this->line3_2 = new LiquidLine(0, 1, current_values.in_humidity);
// this->line3_3 = new LiquidLine(8, 1, current_values.out_humidity);
// this->menu_screen_2 = new LiquidScreen(*this->line3_1); //, *this->line3_2, *this->line3_3);

// this->build_speed_screen();
//     lcd->home();
//     lcd->print((char *)current_values.in_temp_pre_chr_ptr);
// }

// void HRVSMenu::build_speed_screen()
// {
//this->line4_1 = new LiquidLine(0, 0, "TEST");
//this->line4_1->set_asProgmem(1);
// this->line4_2 = new LiquidLine(10, 0, "Test");

// this->menu_screen_3 = new LiquidScreen(*this->line4_1); //*this->line4_2);
// }

// void HRVSMenu::register_glyphs()
// {
//     this->lcd->createChar(fan1_index, custom_glyps::fan1);
//     this->lcd->createChar(fan2_index, custom_glyps::fan2);
//     this->lcd->createChar(thermometer_index, custom_glyps::thermometer);
//     this->lcd->createChar(cross_index, custom_glyps::cross);
//     this->lcd->createChar(degree_index, custom_glyps::degree);
// }

// void HRVSMenu::next_screen()
// {
//     // this->menu->next_screen();
// }

// void HRVSMenu::refresh()
// {
//     // this->menu->update();
//     lcd->home();
//     lcd->print((char *)current_values.in_temp_pre_chr_ptr);
// }

// void HRVSMenu::call_function(uint8_t fn_type) {
//     switch (fn_type)
//     {
//         case SHORT_CLICK_BUTTON_2:
//             menu_function_increase_speed();
//             refresh();
//             break;
//         case LONG_CLICK_BUTTON_2:
//             menu_function_decrease_speed();
//             refresh();
//             break;
//         default:
//             break;
//     }
// }
