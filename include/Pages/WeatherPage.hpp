#pragma once

#include "Page.hpp"

class WeatherPage : public Page
{
public:
    void draw(LGFX &lcd) override;

    void update(LGFX &lcd) override;
};