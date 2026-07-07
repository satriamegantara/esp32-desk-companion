#pragma once

#include "Widget.hpp"

class StatusBar : public Widget
{
public:
    void draw(LGFX &lcd) override;

    void update(LGFX &lcd) override;

private:
    bool lastWifi = false;
};