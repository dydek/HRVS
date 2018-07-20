#include <Arduino.h>

#ifndef __STATE_H_
#define __STATE_H_

struct CurrentValues
{
    bool bypass_open = false;
    uint8_t fan_speed = 0;
    float in_temp_pre = 0;
    float in_temp_post = 0;
    float out_temp_pre = 0;
    float out_temp_post = 0;
    float in_humidity = 0;
    float out_humidity = 0;
};

extern volatile struct CurrentValues current_values;

#endif