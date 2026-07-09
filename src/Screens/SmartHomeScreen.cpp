#include "Screens/SmartHomeScreen.hpp"

#include "Theme.hpp"
#include "Layout.hpp"
#include "AppState.hpp"

void SmartHomeScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    drawHeader(lcd);

    drawLamp(lcd);

    drawFan(lcd);

    drawSpeed(lcd);

    drawSwing(lcd);
}

void SmartHomeScreen::update(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    drawHeader(lcd);

    drawLamp(lcd);

    drawFan(lcd);

    drawSpeed(lcd);

    drawSwing(lcd);
}

void SmartHomeScreen::drawHeader(LGFX &lcd)
{
    lcd.setFont(&fonts::Font4);

    lcd.setTextColor(Theme::White);

    lcd.drawCentreString(
        "SMART HOME",
        240,
        Layout::SH_TitleY);
}

void SmartHomeScreen::drawLamp(LGFX &lcd)
{
    int y = Layout::SH_StartY;

    lcd.setFont(&fonts::Font2);

    String prefix =
        selected == SmartHomeMenu::Lamp
            ? "> "
            : "  ";

    lcd.drawString(
        prefix + "Lamp",
        Layout::SH_TextX,
        y);

    lcd.drawRightString(
        appState.lamp ? "ON" : "OFF",
        Layout::SH_StateX,
        y);
}

void SmartHomeScreen::drawFan(LGFX &lcd)
{
    int y = Layout::SH_StartY + Layout::SH_RowHeight;

    lcd.setFont(&fonts::Font2);

    String prefix =
        selected == SmartHomeMenu::Fan
            ? "> "
            : "  ";

    lcd.drawString(
        prefix + "Fan",
        Layout::SH_TextX,
        y);

    lcd.drawRightString(
        appState.fan ? "ON" : "OFF",
        Layout::SH_StateX,
        y);
}

void SmartHomeScreen::drawSpeed(LGFX &lcd)
{
    int y =
        Layout::SH_StartY +
        Layout::SH_RowHeight * 2;

    lcd.setFont(&fonts::Font2);

    String prefix =
        selected == SmartHomeMenu::Speed
            ? "> "
            : "  ";

    String text = "LOW";

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

    lcd.drawString(
        prefix + "Speed",
        Layout::SH_TextX,
        y);

    lcd.drawRightString(
        text,
        Layout::SH_StateX,
        y);
}

void SmartHomeScreen::drawSwing(LGFX &lcd)
{
    int y =
        Layout::SH_StartY +
        Layout::SH_RowHeight * 3;

    lcd.setFont(&fonts::Font2);

    String prefix =
        selected == SmartHomeMenu::Swing
            ? "> "
            : "  ";

    lcd.drawString(
        prefix + "Swing",
        Layout::SH_TextX,
        y);

    lcd.drawRightString(
        appState.swing ? "ON" : "OFF",
        Layout::SH_StateX,
        y);
}

void SmartHomeScreen::nextWidget()
{
    uint8_t index = static_cast<uint8_t>(selected);

    index++;

    if (index >= static_cast<uint8_t>(SmartHomeMenu::Count))
        index = 0;

    selected = static_cast<SmartHomeMenu>(index);
}

void SmartHomeScreen::previousWidget()
{
    int index = static_cast<int>(selected);

    index--;

    if (index < 0)
        index = static_cast<int>(SmartHomeMenu::Count) - 1;

    selected = static_cast<SmartHomeMenu>(index);
}