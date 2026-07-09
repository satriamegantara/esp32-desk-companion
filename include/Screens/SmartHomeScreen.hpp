#pragma once

#include "Screen.hpp"
#include "SmartHomeMenu.hpp"
#include "Controllers/SmartHomeController.hpp"

class SmartHomeScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override {}

    void nextWidget() override;
    void previousWidget() override;

    void activate() override;

private:
        SmartHomeMenu selected = SmartHomeMenu::Lamp;
    SmartHomeMenu previous = SmartHomeMenu::Lamp;

    bool needRedraw = false;

    SmartHomeController controller;

    void drawHeader(LGFX &lcd);

    void drawLamp(LGFX &lcd);
    void drawFan(LGFX &lcd);
    void drawSpeed(LGFX &lcd);
    void drawSwing(LGFX &lcd);
    void drawBack(LGFX &lcd);

    void drawRow(LGFX &lcd, SmartHomeMenu menu);
};