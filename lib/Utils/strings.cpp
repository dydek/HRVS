#include "string.h"
#include <WString.h>
#include <State.h>

const String safeDisplayValue(uint16_t value)
{
    // if (value == 0)
    // {
    //     return "----";
    // }
    return "----";
}

const char* formatTemperature(float value)
{
    String s_value = String(value, 1);
    return s_value.c_str();
};

void printActualState()
{
    Serial.println("Actual state");
    Serial.println("In Pre\tIn post\tIn h\tOut pre\tOut h\tOut pos\tIn RPM\tOut RPM\tbypass");
    Serial.print(current_values.in_temp_pre);
    Serial.print("C\t");
    Serial.print(current_values.in_temp_post);
    Serial.print("C\t");
    Serial.print(current_values.in_humidity);
    Serial.print("%\t");
    Serial.print(current_values.out_temp_pre);
    Serial.print("C\t");
    Serial.print(current_values.out_humidity);
    Serial.print("%\t");
    Serial.print(current_values.out_temp_post);
    Serial.print("C\t");
    Serial.print(current_values.in_fan_speed);
    Serial.print(" RPM\t");
    Serial.print(current_values.out_fan_speed);
    Serial.print(" RPM\t");
    // Serial.print(current_values.out_humidity);
    Serial.print("closed\n");
}