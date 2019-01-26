
#pragma once

#include <stdint.h>

namespace custom_glyps
{
uint8_t thermometer[8]  = {
    0b00100,
    0b01010,
    0b01010,
    0b01110,
    0b01110,
    0b11111,
    0b11111,
    0b01110};
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
uint8_t arrow_right[8] = {
	0b10000,
	0b01000,
	0b00101,
	0b00011,
	0b00111,
	0b00000,
	0b00000,
	0b00000
};

uint8_t arrow_left[8] = {
	0b00001,
	0b00010,
	0b10100,
	0b11000,
	0b11100,
	0b00000,
	0b00000,
	0b00000
};

uint8_t line_right[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b10000,
	0b01000,
	0b00100,
	0b00010,
	0b00001
};

uint8_t line_left[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b10000
};
} // namespace custom_glyps