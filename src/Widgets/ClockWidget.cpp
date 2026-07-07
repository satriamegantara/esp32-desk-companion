#include "Widgets/ClockWidget.hpp"
#include "Theme.hpp"
#include "AppState.hpp"

#include "Layout.hpp"

void ClockWidget::draw(LGFX& lcd)
{
    lcd.drawRoundRect(
        Layout::ClockCard.x,
        Layout::ClockCard.y,
        Layout::ClockCard.w,
        Layout::ClockCard.h,
        10,
        Theme::Primary
    );

    lcd.drawCentreString(
        "CLOCK",
        Layout::ClockCard.x + Layout::ClockCard.w/2,
        Layout::ClockCard.y + 15
    );

    lcd.setTextColor(Theme::White);

    lcd.setFont(&fonts::Font2);
    lcd.drawCentreString("CLOCK",85,70);

    lcd.setFont(&fonts::Font7);
    lcd.drawCentreString(appState.time.c_str(),85,120);

    lcd.setFont(&fonts::Font2);
    lcd.drawCentreString(appState.day.c_str(),85,185);
}

void ClockWidget::update(LGFX& lcd)
{
    if(lastTime != appState.time)
    {
        // redraw angka jam saja

        lastTime = appState.time;
    }
}