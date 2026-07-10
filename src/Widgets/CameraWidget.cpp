#include "Widgets/CameraWidget.hpp"

#include "Theme.hpp"
#include "Layout.hpp"
#include "AppState.hpp"
#include "DirtyFlags.hpp"

void CameraWidget::draw(LGFX &lcd)
{
    drawCard(lcd);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString(
        "Camera",
        Layout::CameraCard.x + Layout::CameraCard.w / 2,
        Layout::CameraCard.y + 8);
}

void CameraWidget::update(LGFX &lcd)
{
    if (selectionChanged())
    {
        drawBorder(
            lcd,
            bounds);

        lastSelected = selected;
    }
}

CameraWidget::CameraWidget()
{
    setBounds(
        Layout::CameraCard);
}

ScreenID CameraWidget::targetScreen() const
{
    return ScreenID::Camera;
}