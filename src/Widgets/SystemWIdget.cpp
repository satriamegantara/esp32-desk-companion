#include "Widgets/SystemWidget.hpp"

#include "Layout.hpp"
#include "Theme.hpp"
#include "DirtyFlags.hpp"

void SystemWidget::draw(LGFX &lcd)
{
    drawCard(lcd);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawCentreString(
        "System",
        Layout::SystemCard.x + Layout::SystemCard.w / 2,
        Layout::SystemCard.y + 8);
}

void SystemWidget::update(LGFX &lcd)
{
    if (selectionChanged())
    {
        drawBorder(
            lcd,
            bounds);

        lastSelected = selected;
    }
}

SystemWidget::SystemWidget()
{
    setBounds(
        Layout::SystemCard);
}

ScreenID SystemWidget::targetScreen() const
{
    return ScreenID::System;
}