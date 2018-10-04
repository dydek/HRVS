#include <State.h>
#include "AppFlow.h"


AppFlow::AppFlow(Menu *menu)
{
    this->menu = menu;
}

void AppFlow::button_1_click(void)
{
    this->menu->next_screen();
}

void AppFlow::button_2_click(void)
{
    current_values.fan_speed ++;
    this->menu->refresh();
}