#pragma once

#include "LGFX_Config.hpp"
#include "Rect.hpp"

class Widget
{
protected:
    bool selected = false;
    bool focused = false;
    bool visible = true;
    Rect bounds;

public:
    virtual ~Widget() {}

    virtual void draw(LGFX &lcd) = 0;
    virtual void update(LGFX &lcd) = 0;

    void setSelected(bool s)
    {
        selected = s;
    }

    void setFocused(bool f)
    {
        focused = f;
    }

    void setVisible(bool v)
    {
        visible = v;
    }

    bool isSelected() const
    {
        return selected;
    }

    bool isFocused() const
    {
        return focused;
    }

    bool isVisible() const
    {
        return visible;
    }
};