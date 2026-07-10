#include "Widgets/StatusBar.hpp"
#include "Layout.hpp"
#include "Theme.hpp"

void StatusBar::draw(LGFX &lcd)
{
    // Gambar background status bar
    lcd.fillRect(
        Layout::Header.x,
        Layout::Header.y,
        Layout::Header.w,
        Layout::Header.h,
        Theme::Background);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    // Judul
    lcd.drawString("DeskMate", 10, 10);

    // Status WiFi (sementara)
    lcd.drawRightString("WiFi", 470, 10);
}

void StatusBar::update(LGFX &lcd)
{
}