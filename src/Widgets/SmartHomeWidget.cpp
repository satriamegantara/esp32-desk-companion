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
    uint16_t borderColor =
        selected
            ? Theme::Accent
            : Theme::Primary;

    lcd.drawRoundRect(
        Layout::SmartCard.x,
        Layout::SmartCard.y,
        Layout::SmartCard.w,
        Layout::SmartCard.h,
        10,
        borderColor);

    lcd.setTextColor(Theme::White, Theme::Background);
    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString(
        "Smart Home",
        Layout::SmartCard.x + Layout::SmartCard.w / 2,
        Layout::SmartCard.y + 15);

    drawLamp(lcd);

    drawFan(lcd);

    drawSpeed(lcd);

    drawSwing(lcd);
}

void SmartHomeWidget::update(LGFX &lcd)
{
    if (!dirty.smartHome)
        return;

    uint16_t border =
        selected ? Theme::Accent : Theme::Primary;

    lcd.drawRoundRect(
        Layout::SmartCard.x,
        Layout::SmartCard.y,
        Layout::SmartCard.w,
        Layout::SmartCard.h,
        10,
        border);

    drawLamp(lcd);
    drawFan(lcd);
    drawSpeed(lcd);
    drawSwing(lcd);

    dirty.smartHome = false;
}

void SmartHomeWidget::drawLamp(LGFX &lcd)
{
    // Bersihkan hanya area baris lamp
    lcd.fillRect(
        Layout::SmartTextX,
        Layout::LampY - 2,
        Layout::SmartStateX - Layout::SmartTextX + 20,
        28,
        Theme::Background);

    lcd.setFont(&fonts::Font2);
    lcd.setTextColor(Theme::White, Theme::Background);

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
        Layout::SmartTextX,
        Layout::FanY - 2,
        Layout::SmartStateX - Layout::SmartTextX + 20,
        28,
        Theme::Background);

    lcd.setFont(&fonts::Font2);
    lcd.setTextColor(Theme::White, Theme::Background);

    lcd.drawString(
        "Fan",
        Layout::SmartTextX,
        Layout::FanY);

    lcd.drawRightString(
        appState.fan ? "ON" : "OFF",
        Layout::SmartStateX,
        Layout::FanY);
}

void SmartHomeWidget::drawSpeed(LGFX &lcd)
{
    lcd.fillRect(
        Layout::SmartTextX,
        Layout::SpeedY - 2,
        Layout::SmartStateX - Layout::SmartTextX + 20,
        28,
        Theme::Background);

    lcd.drawString(
        "Speed",
        Layout::SmartTextX,
        Layout::SpeedY);

    String text;

    switch (appState.fanSpeed)
    {
    case FanSpeed::Low:
        text = "LOW";
        break;

    case FanSpeed::Medium:
        text = "MED";
        break;

    case FanSpeed::High:
        text = "HIGH";
        break;
    }

    lcd.drawRightString(
        text,
        Layout::SmartStateX,
        Layout::SpeedY);

    lcd.drawFastHLine(
        Layout::SmartCard.x + 20,
        182,
        Layout::SmartCard.w - 40,
        TFT_DARKGREY);
}

void SmartHomeWidget::drawSwing(LGFX &lcd)
{
    lcd.fillRect(
        Layout::SmartTextX,
        Layout::SpeedY - 2,
        Layout::SmartStateX - Layout::SmartTextX + 20,
        28,
        Theme::Background);

    lcd.drawString(
        "Swing",
        Layout::SmartTextX,
        Layout::SwingY);

    lcd.drawRightString(
        appState.swing ? "ON" : "OFF",
        Layout::SmartStateX,
        Layout::SwingY);
}

void SmartHomeWidget::drawMagicWind(LGFX &lcd)
{
    lcd.fillRect(
        Layout::SmartTextX,
        Layout::SpeedY - 2,
        Layout::SmartStateX - Layout::SmartTextX + 20,
        28,
        Theme::Background);

    lcd.drawString(
        "Magic Wind",
        Layout::SmartTextX,
        Layout::MagicWindY);

    lcd.drawRightString(
        appState.magicWind ? "ON" : "OFF",
        Layout::SmartStateX,
        Layout::MagicWindY);
}

void SmartHomeWidget::drawTimer(LGFX &lcd)
{
    lcd.fillRect(
        Layout::SmartTextX,
        Layout::SpeedY - 2,
        Layout::SmartStateX - Layout::SmartTextX + 20,
        28,
        Theme::Background);

    lcd.drawString(
        "Timer",
        Layout::SmartTextX,
        Layout::TimerY);

    lcd.drawRightString(
        String(appState.timerHour) + " H",
        Layout::SmartStateX,
        Layout::TimerY);
}