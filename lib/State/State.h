#include <Arduino.h>

#ifndef _STATE_H
#define _STATE_H

struct CurrentValues
{
    bool bypass_open = false;
    uint8_t fan_speed = 0;
    float in_temp_pre = 0;
    float in_temp_post = 0;
    float out_temp_pre = 0;
    float out_temp_post = 0;
};

#endif