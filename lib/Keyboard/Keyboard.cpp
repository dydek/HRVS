
#include "Keyboard.h"
#include <JC_Button.h>
#include <Utils.h>
#include <HRVSMenu.h>

#define KEYBOARD_DEBUG

SimplyKeyboard::SimplyKeyboard(uint8_t button_pin_1, uint8_t button_pin_2, HRVSMenu *hrvs_menu)
{
    this->button1 = new Button(button_pin_1);
    this->button2 = new Button(button_pin_2);

    this->button1->begin();
    this->button2->begin();

    this->hrvs_menu = hrvs_menu;
    // this->flow = flow;
}

void SimplyKeyboard::button_1_click_run()
{
    this->hrvs_menu->next_screen();
}

void SimplyKeyboard::button_2_click_run()
{
    this->hrvs_menu->menu->call_function(short_click_button_2);
    Serial.println(short_click_button_2);
}

void SimplyKeyboard::button_1_long_click_run()
{
    // this->hrvs_menu->menu->call_function(long_click_button_1);
    this->hrvs_menu->menu->switch_focus();
}

void SimplyKeyboard::button_2_long_click_run()
{
    this->hrvs_menu->menu->call_function(long_click_button_2);
}

void SimplyKeyboard::button_click_callback(buttonID, buttonPressType, __appflow_callback)
{
}

void SimplyKeyboard::loop_tick(void)
{
    this->button1->read();
    this->button2->read();

    switch (this->STATE)
    {
    case WAIT:
        if (this->button1->pressedFor(LONG_PRESS) && !this->LONG_PRESS_LOCK)
        {
            this->STATE = BUTTON_1_LONG_PRESS;
        }
        else if (this->button1->wasReleased() && !this->LONG_PRESS_LOCK)
        {
            this->STATE = BUTTON_1_CLICK;
        }
        else if (this->button1->wasReleased())
        {
            this->LONG_PRESS_LOCK = false;
        }
        else if (this->button2->pressedFor(LONG_PRESS) && !this->LONG_PRESS_LOCK)
        {
            this->STATE = BUTTON_2_LONG_PRESS;
        }
        else if (this->button2->wasReleased() && !this->LONG_PRESS_LOCK)
        {
            this->STATE = BUTTON_2_CLICK;
        }
        else if (this->button2->wasReleased())
        {
            this->LONG_PRESS_LOCK = false;
        }

        break;

    case BUTTON_1_CLICK:
#ifdef KEYBOARD_DEBUG
        Serial.println("DEBUG::BUTTON_1_CLICK");
#endif
        this->STATE = WAIT;
        this->button_1_click_run();
        break;

    case BUTTON_1_LONG_PRESS:
#ifdef KEYBOARD_DEBUG
        Serial.println("DEBUG::BUTTON_1_LONG_PRESS");
#endif
        this->LONG_PRESS_LOCK = true;
        this->STATE = WAIT;
        this->button_1_long_click_run();
        break;

    case BUTTON_2_CLICK:
#ifdef KEYBOARD_DEBUG
        Serial.println("DEBUG::BUTTON_2_CLICK");
#endif
        this->button_2_click_run();
        this->STATE = WAIT;
        break;

    case BUTTON_2_LONG_PRESS:
#ifdef KEYBOARD_DEBUG
        Serial.println("DEBUG::BUTTON_2_LONG_PRESS");
#endif
        this->LONG_PRESS_LOCK = true;
        this->STATE = WAIT;
        this->button_2_long_click_run();
        break;
    }
}