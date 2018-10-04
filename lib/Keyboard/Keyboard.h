

#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

#include <JC_Button.h>
#include <Menu2.h>
#include <AppFlow.h>

typedef void (AppFlow::*__appflow_callback)();

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
        SimplyKeyboard(uint8_t, uint8_t, AppFlow* flow);
        void loop_tick(void);
        void button_1_click_register(__appflow_callback);
        void button_1_long_click_register(__appflow_callback);
        void button_2_click_register(__appflow_callback);
        void button_2_long_click_register(__appflow_callback);
    private:
        void button_1_click_run(void);
        void button_2_click_run(void);
        AppFlow* flow;
        Button* button1;
        Button* button2;
        states STATE;
        bool LONG_PRESS_LOCK = false;
        // callbacks
        __appflow_callback button_1_click_callback;
        __appflow_callback button_2_click_callback;
};

#endif