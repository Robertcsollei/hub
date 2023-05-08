#ifndef RELAY_SCHEMA
#define RELAY_SCHEMA

#include <string>
using namespace std;

struct RelaySchema
{
    int pin;
    bool state;
    char name[25];
};

#endif
