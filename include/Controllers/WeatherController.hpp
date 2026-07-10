#pragma once

#include <Arduino.h>

class WeatherController
{
public:
    bool begin();

    void update();

private:
    uint32_t lastUpdate = 0;

    bool fetchWeather();
};