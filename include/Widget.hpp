#pragma once

#include "LGFX_Config.hpp"
#include "Rect.hpp"
#include "Theme.hpp"
#include "Layout.hpp"
#include "ScreenID.hpp"

class Widget
{
protected:
    bool selected = false;
    bool focused = false;
    bool visible = true;
    Rect bounds;

    void setBounds(const Rect &rect)
    {
        bounds = rect;
    }

    void drawCard(
        LGFX &lcd,
        uint16_t bg = Theme::Background)
    {
        lcd.fillRoundRect(
            bounds.x,
            bounds.y,
            bounds.w,
            bounds.h,
            Layout::CardRadius,
            bg);

        drawBorder(
            lcd,
            bounds);
    }

    void drawBorder(
        LGFX &lcd,
        const Rect &rect)
    {
        lcd.drawRoundRect(
            rect.x,
            rect.y,
            rect.w,
            rect.h,
            Layout::CardRadius,
            selected
                ? Theme::Accent
                : Theme::Primary);
    }

    bool selectionChanged()
    {
        if (lastSelected != selected)
        {
            lastSelected = selected;
            return true;
        }

        return false;
    }

public:
    virtual ~Widget() {}

    virtual void draw(LGFX &lcd) = 0;
    virtual void update(LGFX &lcd) = 0;

    bool lastSelected = false;

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

    virtual void onSelected()
    {
        selected = true;
    }

    virtual void onDeselected()
    {
        selected = false;
    }

    virtual ScreenID targetScreen() const
    {
        return ScreenID::Dashboard;
    }
};