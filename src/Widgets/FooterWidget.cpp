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
        25,
        294,
        90,
        18,
        Theme::Header);

    lcd.drawString(
        String(appState.temperature, 1) + " C",
        25,
        296);

    lcd.fillRect(
        150,
        294,
        90,
        18,
        Theme::Header);

    lcd.drawString(
        String(appState.humidity, 1) + " %",
        150,
        296);

    lcd.fillRect(
        275,
        294,
        90,
        18,
        Theme::Header);

    lcd.drawString(
        String(appState.freeHeap) + " KB",
        275,
        296);

    lcd.fillRect(
        380,
        294,
        120,
        18,
        Theme::Header);

    lcd.drawString(
        appState.wifiConnected
            ? "WiFi Online"
            : "WiFi Offline",
        380,
        296);

    dirty.footer = false;
}