#include <Arduino.h>

#include "Engine.h"

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

enum Steps {
  STEP_1,
  STEP_2,
  STEP_3,
  STEP_4,
  STEP_5,
  STEP_6,
  STEP_7,
  STEP_8,
  STEP_9,
  STEP_10
};

struct CurrentSpeeds {
  uint8_t engine_intake_speed;
  uint8_t engine_outake_speed;
};

/**
 * 
 * 
 */
class Controller
{
public:
  Controller(Engine*, Engine*);
  void start();
  void stop();
  void set_speed(Steps);
  CurrentSpeeds get_current_speeds(void);
private:
  Engine *engine_intake;
  Engine *engine_outake;
  void set_engines_speed(Steps);
  uint8_t get_speed_by_step(Steps);
};

#endif