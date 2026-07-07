#include "Widgets/FooterWidget.hpp"
#include "Theme.hpp"
#include "AppState.hpp"
#include "Layout.hpp"

void FooterWidget::draw(LGFX &lcd)
{
    lcd.fillRect(
        Layout::Footer.x,
        Layout::Footer.y,
        Layout::Footer.w,
        Layout::Footer.h,
        Theme::Header);

    lcd.setTextColor(Theme::White, Theme::Header);
    lcd.setFont(&fonts::Font2);

    lcd.drawString("Temp --C", 10, 296);
    lcd.drawString("Hum --%", 120, 296);
    lcd.drawString(
        "Up " + String(appState.uptime),
        220,
        296);
    lcd.drawString("WiFi Offline", 340, 296);
    lcd.drawString(String(millis() / 1000), 430, 296);
}