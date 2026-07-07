#include "Widgets/HeaderWidget.hpp"
#include "Theme.hpp"

void drawHeader(LGFX& lcd)
{
    lcd.fillRect(0,0,480,40,Theme::Header);

    lcd.setTextColor(Theme::White, Theme::Header);
    lcd.setFont(&fonts::Font2);

    lcd.drawString("DeskMate",15,12);

    lcd.drawRightString("21:35",410,12);

    lcd.fillCircle(455,20,5,Theme::Success);
}