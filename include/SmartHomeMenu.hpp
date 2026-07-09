#pragma once

#include <Arduino.h>

enum class SmartHomeMenu : uint8_t
{
    Lamp = 0,
    Fan,
    Speed,
    Swing,

    Count
};