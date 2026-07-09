#include "Widgets/SmartHomeWidget.hpp"

#include "Theme.hpp"
#include "Layout.hpp"
#include "AppState.hpp"
#include "DirtyFlags.hpp"

void SmartHomeWidget::draw(LGFX &lcd)
{
    // Background card
    lcd.fillRoundRect(
        Layout::SmartCard.x,
        Layout::SmartCard.y,
        Layout::SmartCard.w,
        Layout::SmartCard.h,
        10,
        Theme::Background);

    // Border
    lcd.drawRoundRect(
        Layout::SmartCard.x,
        Layout::SmartCard.y,
        Layout::SmartCard.w,
        Layout::SmartCard.h,
        10,
        Theme::Primary);

    lcd.setTextColor(Theme::White, Theme::Background);
    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString(
        "SMART HOME",
        Layout::SmartCard.x + Layout::SmartCard.w / 2,
        Layout::SmartCard.y + 15);

    drawLamp(lcd);
    drawFan(lcd);
}

void SmartHomeWidget::update(LGFX &lcd)
{
    if (!dirty.smartHome)
        return;

    drawLamp(lcd);
    drawFan(lcd);

    dirty.smartHome = false;
}

void SmartHomeWidget::drawLamp(LGFX &lcd)
{
    // Bersihkan hanya area baris lamp
    lcd.fillRect(
        Layout::SmartArrowX,
        Layout::LampY - 2,
        Layout::SmartStateX - Layout::SmartArrowX + 20,
        28,
        Theme::Background);

    lcd.setFont(&fonts::Font2);
    lcd.setTextColor(Theme::White, Theme::Background);

    // Arrow
    if (appState.focus == FocusItem::Lamp)
        lcd.drawString(">", Layout::SmartArrowX, Layout::LampY);

    // Text
    lcd.drawString(
        "Lamp",
        Layout::SmartTextX,
        Layout::LampY);

    // Status
    lcd.drawRightString(
        appState.lamp ? "ON" : "OFF",
        Layout::SmartStateX,
        Layout::LampY);
}

void SmartHomeWidget::drawFan(LGFX &lcd)
{
    lcd.fillRect(
        Layout::SmartArrowX,
        Layout::FanY - 2,
        Layout::SmartStateX - Layout::SmartArrowX + 20,
        28,
        Theme::Background);

    lcd.setFont(&fonts::Font2);
    lcd.setTextColor(Theme::White, Theme::Background);

    if (appState.focus == FocusItem::Fan)
        lcd.drawString(">", Layout::SmartArrowX, Layout::FanY);

    lcd.drawString(
        "Fan",
        Layout::SmartTextX,
        Layout::FanY);

    lcd.drawRightString(
        appState.fan ? "ON" : "OFF",
        Layout::SmartStateX,
        Layout::FanY);
}