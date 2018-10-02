#ifndef __APPFLOW_H_
#define __APPFLOW_H_

#include <Menu2.h>

class AppFlow
{
  public:
    AppFlow(Menu* menu);
    void button_1_click(void);
  private:
    Menu* menu;
};

#endif