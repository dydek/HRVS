#ifndef __STATE_H_
#define __STATE_H_

#include <Arduino.h>
#include <Utils.h>

#define MAX_GEAR 9

struct CurrentValues
{
    CurrentValues() {
        strcpy(in_temp_pre_chr, " --.--");
        strcpy(in_temp_post_chr, " --.--");
        strcpy(out_temp_pre_chr, " --.--");
        strcpy(out_temp_post_chr, " --.--");
    };

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
    float heat_efficiency = 0;

    char in_temp_pre_chr[7];
    char in_temp_post_chr[7];
    char out_temp_pre_chr[7];
    char out_temp_post_chr[7];
};

void update_chr_variables();

extern volatile struct CurrentValues current_values;

#endif