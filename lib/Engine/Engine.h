
#include <Arduino.h>

#ifndef _ENGINE_H_
#define _ENGINE_H_

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
    void update_engine_speed(void);
    void config_output_pin(void);
};

#endif