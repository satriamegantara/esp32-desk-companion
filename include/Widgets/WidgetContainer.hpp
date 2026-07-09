#pragma once

#include "Widget.hpp"

class WidgetContainer
{
public:
    void add(Widget *widget);

    void draw(LGFX &lcd);

    void update(LGFX &lcd);

private:
    static constexpr uint8_t MAX_WIDGETS = 10;

    Widget *widgets[MAX_WIDGETS];

    uint8_t count = 0;
};