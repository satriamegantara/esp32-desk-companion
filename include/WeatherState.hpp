#pragma once

#include <Arduino.h>

enum class WeatherIcon
{
    Clear,
    Cloud,
    Rain,
    Storm,
    Snow,
    Mist,
    Unknown
};

struct WeatherData
{
    float temperature = 0;

    float humidity = 0;

    float feelsLike = 0;

    float windSpeed = 0;

    String city;

    String description;

    uint32_t lastUpdate = 0;

    WeatherIcon icon =
        WeatherIcon::Unknown;
};