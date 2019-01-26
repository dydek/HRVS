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

void formatTemperature(float value, char *text)
{

    dtostrf(value, 2, 2, text);
    // uint8_t startChar = 1;
    // if (value < 0)
    // {
    //     text[0] = '-';
    // }
    // else
    // {
    //     text[0] = ' ';
    // }

    // if (abs(value) < 10)
    // {
    //     text[1] = ' ';
    //     startChar = 2;
    // }

    // char temp[5];

    // dtostrf(
    //     abs(value), 2, 2, temp);

    // for (uint8_t i = 0; i < 5; i++)
    // {
    //     text[i + startChar] = temp[i];
    // }
}