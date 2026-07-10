#pragma once

#include <Arduino.h>

class WeatherController
{
public:
    void begin();
    void update();

private:
    uint32_t lastUpdate = 0;
};