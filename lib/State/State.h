#ifndef __STATE_H_
#define __STATE_H_

#include <Arduino.h>

#define MAX_GEAR 10

struct CurrentValues
{
    bool bypass_open = false;
    uint16_t in_fan_speed = 0;
    uint16_t out_fan_speed = 0;
    uint8_t fan_gear = 0;
    float in_temp_pre = 0;
    float in_temp_post = 0;
    float out_temp_pre = 0;
    float out_temp_post = 0;
    float in_humidity = 0;
    float out_humidity = 0;
};

extern volatile struct CurrentValues current_values;

#endif