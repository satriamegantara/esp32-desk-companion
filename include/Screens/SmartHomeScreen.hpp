#pragma once

#include "Screen.hpp"

class SmartHomeScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override {}

private:
    uint8_t selected = 0;

    void drawHeader(LGFX &lcd);
    void drawLamp(LGFX &lcd);
    void drawFan(LGFX &lcd);
    void drawSpeed(LGFX &lcd);
    void drawSwing(LGFX &lcd);
};