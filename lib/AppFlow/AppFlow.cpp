#include "AppFlow.h"

AppFlow::AppFlow(Menu *menu)
{
    this->menu = menu;
}

void AppFlow::button_1_click(void)
{
    Serial.println("AppFlow::button_1_click");
    this->menu->next_screen();
}