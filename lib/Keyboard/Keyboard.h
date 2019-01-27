

#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

#include <JC_Button.h>
#include <HRVSMenu.h>

const uint16_t LONG_PRESS = 500;

enum states
{
    WAIT,
    BUTTON_1_CLICK,
    BUTTON_1_LONG_PRESS,
    BUTTON_2_CLICK,
    BUTTON_2_LONG_PRESS,
};

/**
 * SimpleKeyboard class helps to navigate through all screens and settings 
 * using only 2 buttons. 
 */
class SimplyKeyboard
{
  public:
    SimplyKeyboard(uint8_t, uint8_t);
    void loop_tick(void);

  private:
    Button *button1;
    Button *button2;
    states STATE;
    bool LONG_PRESS_LOCK = false;
};

#endif