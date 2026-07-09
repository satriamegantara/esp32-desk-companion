#pragma once

#include "Widget.hpp"

class SmartHomeWidget : public Widget
{
public:
    void draw(LGFX &lcd) override;
    void update(LGFX &lcd) override;

private:
    void drawLamp(LGFX &lcd);
    void drawFan(LGFX &lcd);
};