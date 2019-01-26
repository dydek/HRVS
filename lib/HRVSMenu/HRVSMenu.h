#ifndef __HRVSMENU_H_
#define __HRVSMENU_H_

#include <avr/pgmspace.h>
#include <LiquidMenu.h>
#include <LiquidCrystal_I2C.h>
#include <State.h>

#define SHORT_CLICK_BUTTON_1 1
#define SHORT_CLICK_BUTTON_2 2
#define LONG_CLICK_BUTTON_1 3
#define LONG_CLICK_BUTTON_2 4

const uint8_t fan1_index = 0;
const uint8_t fan2_index = 1;
const uint8_t thermometer_index = 2;
const uint8_t cross_index = 3;
const uint8_t degree_index = 4;

const char menu_0_text1[] PROGMEM = "Intake";
const char menu_0_text2[] PROGMEM = "Air in";
const char menu_0_text3[] PROGMEM = "Air out";
const char menu_0_text4[] PROGMEM = "Outtake";
const char menu_2_text1[] PROGMEM = "Humidity";
const char menu_3_text1[] PROGMEM = "Speed set: ";

void menu_function_increase_speed();
void menu_function_decrease_speed();

class HRVSMenu
{
public:
  HRVSMenu();
  void begin();
  void next_screen();
  void call_function(uint8_t);
  void refresh();
  LiquidMenu *menu;

private:
  void init_menu();
  void register_glyphs();
  void build_screen(LiquidScreen *, LiquidLine *[], uint8_t);
  void build_speed_screen();
  LiquidCrystal_I2C *lcd;

  LiquidLine *menu_0_lines[12];
  // LiquidLine *menu_1_lines[4];
  // LiquidLine *menu_2_lines[4];
  // LiquidLine *menu_3_lines[4];

  // LiquidLine *line1_1;
  // LiquidLine *line1_2;
  // LiquidLine *line1_3;
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