

#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

#include <JC_Button.h>
#include <Menu.h>



enum states {
    WAIT,
    BUTTON_1_CLICK,
    BUTTON_1_LONG_PRESS,
    BUTTON_2_CLICK,
    BUTTON_2_LONG_PRESS,
};

const uint16_t LONG_PRESS (700);

/**
 * SimpleKeyboard class helps to navigate through all screens and settings 
 * using only 2 buttons. 
 */
class SimplyKeyboard {
    public:
        SimplyKeyboard(uint8_t, uint8_t);
        void loop_tick(void);
        void button_1_click_register(Menu* menu, void (Menu::*callback)());
        void button_1_long_click_register(void (*callback)(void));
        void button_2_click_register(void (*callback)(void));
        void button_2_long_click_register(void (*callback)(void));
    private:
        Button* button1;
        Button* button2;
        states STATE;
        bool LONG_PRESS_LOCK = false;
};

#endif