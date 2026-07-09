#include "Widgets/FooterWidget.hpp"
#include "Theme.hpp"
#include "AppState.hpp"
#include "Layout.hpp"
#include "DirtyFlags.hpp"

void FooterWidget::draw(LGFX &lcd)
{
    lcd.fillRect(
        Layout::Footer.x,
        Layout::Footer.y,
        Layout::Footer.w,
        Layout::Footer.h,
        Theme::Header);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Header);

    update(lcd);
}

void FooterWidget::update(LGFX &lcd)
{
    if (!dirty.footer)
        return;

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Header);

    lcd.fillRect(
        Layout::Footer.x,
        Layout::Footer.y,
        Layout::Footer.w,
        Layout::Footer.h,
        Theme::Header);

    lcd.drawCentreString(
        String(appState.temperature, 1) + "C",
        Layout::FooterCol1,
        Layout::FooterTextY);

    lcd.drawCentreString(
        String(appState.humidity, 1) + "%",
        Layout::FooterCol2,
        Layout::FooterTextY);

    lcd.drawCentreString(
        String(appState.freeHeap) + " KB",
        Layout::FooterCol3,
        Layout::FooterTextY);

    lcd.drawCentreString(
        appState.wifiConnected ? "ONLINE"
                               : "OFFLINE",
        Layout::FooterCol4,
        Layout::FooterTextY);

    dirty.footer = false;
}