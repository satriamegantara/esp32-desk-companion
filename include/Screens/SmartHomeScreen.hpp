#pragma once

#include "Screen.hpp"
#include "SmartHomeMenu.hpp"
#include "Controllers/SmartHomeController.hpp"

class SmartHomeScreen : public Screen
{
public:
    SmartHomeMenu currentMenu() const;
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

    bool lastLamp = false;
    bool lastFan = false;
    FanSpeed lastSpeed = FanSpeed::Low;
    bool lastSwing = false;

    SmartHomeController controller;

    void drawHeader(LGFX &lcd);

    void drawLamp(LGFX &lcd);
    void drawFan(LGFX &lcd);
    void drawSpeed(LGFX &lcd);
    void drawSwing(LGFX &lcd);
    void drawBack(LGFX &lcd);

    void drawRow(LGFX &lcd, SmartHomeMenu menu);
    void drawHint(LGFX &lcd);
    void drawFooterArea(LGFX &lcd);
};