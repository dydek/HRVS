#ifndef __TASKS_H_
#define __TASKS_H_

#include <Arduino.h>
// #include <TimerOne.h>
#include <State.h>

/**
 * 
 * 
 */
void updateMotorSpeeds()
{
    uint16_t current_speed = 1000 - (uint16_t)(1000 - 100 * current_values.fan_gear);
    // Timer1.setPwmDuty(9, current_speed);
    // Timer1.setPwmDuty(10, current_speed);
}

/**
 * 
 * 
 */
void updateOtherParameters()
{
    current_values.heat_efficiency = (
        (current_values.in_temp_post-current_values.in_temp_pre) /
        (current_values.out_temp_pre-current_values.in_temp_post)
    );
}

#endif