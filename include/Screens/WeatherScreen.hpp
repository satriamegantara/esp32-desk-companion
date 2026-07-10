#pragma once

#include "Screen.hpp"

class WeatherScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override;

    void nextWidget() override;
    void previousWidget() override;

private:
    void drawBack(LGFX &lcd);
};