#pragma once

#include <Arduino.h>

struct WeatherData
{
    float temperature = 0;

    float humidity = 0;

    String city;

    String description;
};