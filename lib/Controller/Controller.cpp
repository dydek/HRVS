
#include "Controller.h"

/**
 * 
 **/
Controller::Controller(Engine *engine_intake, Engine *engine_outtake)
{
    this->engine_intake = engine_intake;
    this->engine_outake = engine_outake;
}

void Controller::start(void)
{
    this->set_speed(Steps::STEP_1);
}

void Controller::stop(void)
{
    this->engine_intake->switch_off();
    this->engine_outake->switch_off();
}

void Controller::set_speed(Steps step)
{
    this->engine_intake->set_speed(10);
    this->engine_outake->set_speed(10);
}

CurrentSpeeds Controller::get_current_speeds(void)
{
    return {
        this->engine_intake->get_current_speed(),
        this->engine_outake->get_current_speed()};
}

void Controller::set_engines_speed(Steps step)
{
    uint8_t speed = this->get_speed_by_step(step);
    this->engine_intake->set_speed(speed);
    this->engine_outake->set_speed(speed);
}

uint8_t Controller::get_speed_by_step(Steps step)
{
    switch (step)
    {
    case Steps::STEP_1:
        return 10;
    case Steps::STEP_2:
        return 20;
    case Steps::STEP_3:
        return 30;
    case Steps::STEP_4:
        return 40;
    case Steps::STEP_5:
        return 50;
    case Steps::STEP_6:
        return 60;
    case Steps::STEP_7:
        return 70;
    case Steps::STEP_8:
        return 80;
    case Steps::STEP_9:
        return 90;
    case Steps::STEP_10:
        return 100;
    default:
        return 0;
    }
}