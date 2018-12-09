#ifndef __APPFLOW_H_
#define __APPFLOW_H_

#include <HRVSMenu.h>

class AppFlow
{
  public:
    AppFlow(HRVSMenu* menu);
    void button_1_click(void);
    void button_2_click(void);
  private:
    HRVSMenu* menu;
};

#endif