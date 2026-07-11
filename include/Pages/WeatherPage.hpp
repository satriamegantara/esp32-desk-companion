#pragma once

#include "Page.hpp"
#include "WeatherState.hpp"

class WeatherPage : public Page
{
public:
    void draw(LGFX &lcd) override;

    void update(LGFX &lcd) override;

private:
    float lastTemperature = -999;

    float lastHumidity = -999;

    float lastFeelsLike = -999;

    float lastWindSpeed = -999;

    String lastDescription;

    String lastCity;

    WeatherIcon lastIcon =
        WeatherIcon::Unknown;
};