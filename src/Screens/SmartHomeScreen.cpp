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

    lcd.drawString("> Lamp", Layout::SH_TextX, y);

    lcd.drawRightString(
        appState.lamp ? "ON" : "OFF",
        Layout::SH_StateX,
        y);
}

void SmartHomeScreen::drawFan(LGFX &lcd)
{
    int y = Layout::SH_StartY + Layout::SH_RowHeight;

    lcd.setFont(&fonts::Font2);

    lcd.drawString("  Fan", Layout::SH_TextX, y);

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

    lcd.drawString("  Speed", Layout::SH_TextX, y);

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

    lcd.drawString("  Swing", Layout::SH_TextX, y);

    lcd.drawRightString(
        appState.swing ? "ON" : "OFF",
        Layout::SH_StateX,
        y);
}