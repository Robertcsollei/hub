#include "timerRelay.h"


TimerRelay::TimerRelay(int pin): _pin(pin)
{
}

TimerRelay::~TimerRelay()
{
}


void TimerRelay::setState(bool state)
{
    _state = state;
}

void TimerRelay::setName(char *name)
{
    strcpy(_name, name);
}

void TimerRelay::setDuration(int duration)
{
    _duration = duration;
}