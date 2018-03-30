
#include <Arduino.h>

#ifndef _ENGINE_H_
#define _ENGINE_H_

/*
 *
 */
class Engine
{
  public:
    Engine(uint8_t pin);
    void set_speed(uint8_t speed);
    void switch_on(void);
    void switch_off(void);
    uint16_t get_current_speed();
    static void init(void);
  protected:
  private:
};

#endif