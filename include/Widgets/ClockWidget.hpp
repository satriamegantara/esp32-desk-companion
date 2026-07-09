#pragma once

#include "Widget.hpp"

class ClockWidget : public Widget
{
private:
    String lastTime;
    String lastDay;

public:
    void draw(LGFX &lcd) override;
    void update(LGFX &lcd) override;
};