#include <LiquidMenu.h>
#include <State.h>

#ifndef _MENU_H
#define _MENU_H

struct LcdConfig {
  uint8_t rs_pin;
  uint8_t en_pin;
  uint8_t d4_pin;
  uint8_t d5_pin;
  uint8_t d6_pin;
  uint8_t d7_pin;
};



class Menu
{
public:
  Menu(LcdConfig, volatile CurrentValues*);
  void begin();
  void next_screen();
  void refresh();
private:
  void init_menu();
  volatile CurrentValues *current_values;
  LiquidCrystal *lcd;
  LiquidMenu *menu;
  LiquidScreen *welcome_screen;
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
  LiquidScreen *menu_screen_1;
  LiquidScreen *menu_screen_2;
  LiquidScreen *menu_screen_3;
  LiquidScreen *menu_screen_4;
};

#endif