#include <State.h>
#include "AppFlow.h"


AppFlow::AppFlow(HRVSMenu *menu)
{
    this->menu = menu;
}

void AppFlow::button_1_click(void)
{
    this->menu->next_screen();
}

void AppFlow::button_2_click(void)
{
    current_values.in_fan_speed += 100;
    this->menu->refresh();
}