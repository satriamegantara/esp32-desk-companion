#pragma once

#include "Widget.hpp"

class FooterWidget : public Widget
{
public:
    void draw(LGFX &lcd) override;

    void update(LGFX &lcd) override;

private:
    float lastTemp = -999;
    float lastHum = -999;
    uint32_t lastHeap = 0;
    bool lastWifi = false;
};