#include "Menu.h"

Menu::Menu(LcdConfig config, volatile CurrentValues *current_values)
{
    this->lcd = new LiquidCrystal(
        config.rs_pin,
        config.en_pin,
        config.d4_pin,
        config.d5_pin,
        config.d6_pin,
        config.d7_pin);
    this->current_values = current_values;
    this->init_menu();
}

void Menu::begin()
{

    this->menu = new LiquidMenu(*(this->lcd));
    this->lcd->begin(16, 2);

    this->menu->add_screen(*this->welcome_screen);
    this->menu->add_screen(*this->menu_screen_1);
    this->menu->add_screen(*this->menu_screen_2);
    this->menu->add_screen(*this->menu_screen_3);
    this->menu->change_screen(*this->welcome_screen);
}

void Menu::init_menu()
{
    this->line1_1 = new LiquidLine(0, 0, "Temparatures:");
    this->line1_2 = new LiquidLine(0, 1, this->current_values->in_temp_pre, " *C");
    this->line1_3 = new LiquidLine(8, 1, "-- C");
    this->welcome_screen = new LiquidScreen(
        *this->line1_1, *this->line1_2, *this->line1_3);

    this->line2_1 = new LiquidLine(0, 0, "Speeds:");
    this->line2_2 = new LiquidLine(0, 1, "1200rpm");
    this->line2_3 = new LiquidLine(8, 1, "1450rpm");
    this->menu_screen_1 = new LiquidScreen(
        *this->line2_1, *this->line2_2, *this->line2_3);

    this->line3_1 = new LiquidLine(0, 0, "Humidity:");
    this->line3_2 = new LiquidLine(0, 1, "25 %");
    this->line3_3 = new LiquidLine(8, 1, "56 %");
    this->menu_screen_2 = new LiquidScreen(
        *this->line3_1, *this->line3_2, *this->line3_3);

    this->line4_1 = new LiquidLine(0, 0, "Speed set:");
    this->line4_2 = new LiquidLine(0, 1, "0");
    this->menu_screen_3 = new LiquidScreen(
        *this->line4_1, *this->line4_2);

    // Set speed menu
    // this->line_set_speed_1 = new LiquidLine(0, 0, "");
}

void Menu::next_screen()
{
    Serial.println("next screen");
    this->menu->next_screen();
}


void Menu::refresh() {
    this->menu->softUpdate();
}