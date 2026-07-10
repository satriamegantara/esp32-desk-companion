#pragma once

#include "Widget.hpp"

class SystemWidget : public Widget
{
public:
    SystemWidget();

    void draw(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    ScreenID targetScreen() const override;
    bool lastSelected = false;
};