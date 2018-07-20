
#include "Keyboard.h"
#include <JC_Button.h>


SimplyKeyboard::SimplyKeyboard(uint8_t button_pin_1, uint8_t button_pin_2) {
    this->button1 = new Button(button_pin_1);
    this->button2 = new Button(button_pin_2);

    this->button1->begin();
    this->button2->begin();
}

void SimplyKeyboard::button_1_click_register(Menu* menu, void (Menu::*callback)()){
    //(menu->*callback)();
}

void SimplyKeyboard::button_1_long_click_register(void (*callback)(void)){

}

void SimplyKeyboard::button_2_click_register(void (*callback)(void)){

}

void SimplyKeyboard::button_2_long_click_register(void (*callback)(void)){

}


void SimplyKeyboard::loop_tick(void) {
    this->button1->read();
    this->button2->read();

    switch(this->STATE) {
        case WAIT:
            if (this->button1->pressedFor(LONG_PRESS) && !this->LONG_PRESS_LOCK )
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
            else if (this->button2->pressedFor(LONG_PRESS) && !this->LONG_PRESS_LOCK )
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
            Serial.println("BUTTON_1_CLICK");
        #endif
            this->STATE = WAIT;
            break;

        case BUTTON_1_LONG_PRESS:
        #ifdef KEYBOARD_DEBUG
            Serial.println("BUTTON_1_LONG_PRESS");
        #endif
            this->LONG_PRESS_LOCK = true;
            this->STATE = WAIT;
            break;

        case BUTTON_2_CLICK:
        #ifdef KEYBOARD_DEBUG
            Serial.println("BUTTON_2_CLICK");
        #endif
            this->STATE = WAIT;
            break;

        case BUTTON_2_LONG_PRESS:
        #ifdef KEYBOARD_DEBUG
            Serial.println("BUTTON_2_LONG_PRESS");
        #endif
            this->LONG_PRESS_LOCK = true;
            this->STATE = WAIT;
            break;
    }
}