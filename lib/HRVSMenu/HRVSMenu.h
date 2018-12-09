#ifndef __HRVSMENU_H_
#define __HRVSMENU_H_

#include <LiquidMenu.h>
#include <State.h>

struct LcdConfig
{
  uint8_t rs_pin;
  uint8_t en_pin;
  uint8_t d4_pin;
  uint8_t d5_pin;
  uint8_t d6_pin;
  uint8_t d7_pin;
};

enum FunctionTypes
{
  short_click_button_1 = 1,
  short_click_button_2 = 2,
  long_click_button_1 = 3,
  long_click_button_2 = 4
};

const uint8_t fan1_index = 0;
const uint8_t fan2_index = 1;
const uint8_t full_index = 2;
const uint8_t thermometer_index = 3;

void menu_function_increase_speed();
void menu_function_decrease_speed();

class HRVSMenu
{
public:
  HRVSMenu(LcdConfig);
  void begin();
  void next_screen();
  void refresh();
    LiquidMenu *menu;

private:
  void init_menu();
  void register_glyphs();
  void build_screen(LiquidScreen *, LiquidLine *[], uint8_t);
  void build_speed_screen();
  LiquidCrystal *lcd;

  LiquidLine *menu_0_lines[4];
  LiquidLine *menu_1_lines[4];
  LiquidLine *menu_2_lines[4];
  LiquidLine *menu_3_lines[4];

  LiquidLine *line1_1;
  LiquidLine *line1_2;
  LiquidLine *line1_3;
  LiquidLine *line2_1;
  LiquidLine *line2_2;
  LiquidLine *line2_3;
  LiquidLine *line3_1;
  LiquidLine *line3_2;
  LiquidLine *line3_3;
  LiquidLine *line4_1;
  LiquidLine *line4_2;

  LiquidScreen *menu_screen_0;
  LiquidScreen *menu_screen_1;
  LiquidScreen *menu_screen_2;
  LiquidScreen *menu_screen_3;
  LiquidScreen *menu_screen_4;
  //LiquidScreen* menu_screen_set_speed;
};

#endif