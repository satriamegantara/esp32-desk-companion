#include "Widgets/SmartHomeWidget.hpp"
#include "Theme.hpp"

#include "Layout.hpp"

void SmartHomeWidget::draw(LGFX &lcd)
{
    lcd.drawRoundRect(
        Layout::SmartCard.x,
        Layout::SmartCard.y,
        Layout::SmartCard.w,
        Layout::SmartCard.h,
        10,
        Theme::Primary);

    lcd.setTextColor(Theme::White);

    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString("SMART HOME", 320, 70);

    lcd.drawString("Lamp", 195, 115);
    lcd.drawString("OFF", 390, 115);

    lcd.drawString("Fan", 195, 155);
    lcd.drawString("OFF", 390, 155);
}