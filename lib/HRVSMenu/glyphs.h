
#pragma once

#include <stdint.h>

namespace custom_glyps
{
uint8_t thermometer[8] = {
    0b00100,
    0b01010,
    0b01010,
    0b01110,
    0b01110,
    0b11111,
    0b11111,
    0b01110};

uint8_t full[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111};
uint8_t fan1[8] = {
    0b00000,
    0b11001,
    0b01011,
    0b00100,
    0b11010,
    0b10011,
    0b00000,
    0b00000};

uint8_t fan2[8] = {
    0b00000,
    0b10011,
    0b11010,
    0b00100,
    0b01011,
    0b11001,
    0b00000,
    0b00000};
uint8_t cross[8] = {
    0b00000,
    0b11011,
    0b01110,
    0b00100,
    0b01110,
    0b11011,
    0b00000,
    0b00000};
uint8_t degree[8] = {
    0b00111,
    0b00101,
    0b00111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000};
} // namespace custom_glyps