#pragma once

#include "Widget.hpp"

class SmartHomeWidget : public Widget
{
public:
    SmartHomeWidget();
    void draw(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    ScreenID targetScreen() const override;

private:
    void drawLamp(LGFX &lcd);
    void drawFan(LGFX &lcd);
    void drawSpeed(LGFX &lcd);
    void drawSwing(LGFX &lcd);
    void drawMagicWind(LGFX &lcd);
    void drawTimer(LGFX &lcd);
    void drawRow(
        LGFX &lcd,
        const char *label,
        const String &value,
        int y);
    bool lastSelected = false;
};