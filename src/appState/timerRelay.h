#ifndef TIMER_RELAY
#define TIMER_RELAY

#include "string.h"

class TimerRelay
{
public:
    TimerRelay(int pin);
    ~TimerRelay();

    void setState(bool state);
    void setName(char *name);
    void setDuration(int duration);

private:
    /* data */
    int _pin;
    bool _state;
    char _name[25];
    int _duration = 1800; // specified in seconds
};

#endif