#pragma once

#include "Screen.hpp"
#include "SmartHomeMenu.hpp"

class SmartHomeScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override {}

    // Navigasi encoder
    void nextWidget() override;
    void previousWidget() override;

private:
    SmartHomeMenu selected = SmartHomeMenu::Lamp;

    void drawHeader(LGFX &lcd);
    void drawLamp(LGFX &lcd);
    void drawFan(LGFX &lcd);
    void drawSpeed(LGFX &lcd);
    void drawSwing(LGFX &lcd);
};