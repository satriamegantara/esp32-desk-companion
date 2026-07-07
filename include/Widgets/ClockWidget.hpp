#pragma once

#include "LGFX_Config.hpp"

class ClockWidget
{
private:

    String lastTime;

public:

    void draw(LGFX& lcd);

    void update(LGFX& lcd);
};

void drawClockWidget(LGFX& lcd);