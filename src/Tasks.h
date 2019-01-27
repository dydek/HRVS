#pragma once

#include <Arduino.h>
#include <EEPROM.h>
#include <TimerOne.h>
#include <State.h>
#include <HRVSMenu.h>

/**
 * 
 * 
 */
void updateMotorSpeeds()
{
    uint16_t current_speed = 1000 - (uint16_t)(1000 - 100 * current_values.fan_gear);
    Timer1.setPwmDuty(9, current_speed);
    Timer1.setPwmDuty(10, current_speed);
}

/**
 * 
 * 
 */ 
void readMotorsSpeeds()
{

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
    // TODO bypass should be also open when the temp outside is above 25C
    digitalWrite(BYPASS_RELAY, !current_values.bypass_open);
}

void updateMenu()
{
    update_chr_variables();
    update_current_screen();
}