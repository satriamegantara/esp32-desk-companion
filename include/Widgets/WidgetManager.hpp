#pragma once

#include "Widget.hpp"

class WidgetManager
{
public:
    void add(Widget *widget);
    void draw(LGFX &lcd);
    void update(LGFX &lcd);
    void clear();

    void next();
    void previous();

    bool isFirst() const;

    bool isLast() const;

    uint8_t widgetCount() const;

    Widget *currentWidget() const;

    uint8_t selectedIndex() const;

    ScreenID currentTarget() const;

private:
    static constexpr uint8_t MAX_WIDGETS = 10;

    Widget *widgets[MAX_WIDGETS];

    uint8_t count = 0;
    uint8_t currentIndex = 0;
};