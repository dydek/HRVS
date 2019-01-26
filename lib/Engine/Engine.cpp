
#include <Arduino.h>
#include "Engine.h"

Engine::Engine(uint8_t pin) {
}

/**
 * set speed of the current engine
 */
void Engine::set_speed(uint8_t speed) {
    if (speed > ENGINE_MAX_SPEED) {
        this->current_speed = ENGINE_MAX_SPEED;
    } else {
        this->current_speed = speed;
    }
}

void Engine::switch_off() {
    this->set_speed(0);
}

void Engine::switch_on() {
    this->set_speed(10);
}

uint8_t Engine::get_current_speed(void) {
    return this->current_speed;
}

// void Engine::update_engine_speed(void)
// {

// }

// void Engine::config_output_pin(void)
// {
        
// }