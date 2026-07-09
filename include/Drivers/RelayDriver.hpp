#pragma once

#include <Arduino.h>
#include "Pins.hpp"

class RelayDriver
{
public:
    void begin();

    void setLamp(bool on);

    void setFan(bool on);
};