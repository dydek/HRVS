#ifndef __APPFLOW_H_
#define __APPFLOW_H_

#include <Menu2.h>

class AppFlow
{
  public:
    AppFlow(Menu* menu);
    void button_1_click(void);
    void button_2_click(void);
  private:
    Menu* menu;
};

#endif