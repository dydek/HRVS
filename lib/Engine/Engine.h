#ifndef __ENGINE_H_
#define __ENGINE_H_

#include <Arduino.h>

#define ENGINE_MAX_SPEED 100

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
    uint8_t get_current_speed();
    static void init(void);
  protected:
  private:
    uint8_t current_speed;
    // void update_engine_speed(void);
    // void config_output_pin(void);
};

#endif