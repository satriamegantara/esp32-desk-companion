#include "Screens/SmartHomeScreen.hpp"

#include "Theme.hpp"
#include "Layout.hpp"
#include "AppState.hpp"

void SmartHomeScreen::begin(LGFX &lcd)
{
    controller.begin();

    lcd.fillScreen(Theme::Background);

    drawHeader(lcd);

    drawLamp(lcd);
    drawFan(lcd);
    drawSpeed(lcd);
    drawSwing(lcd);
    drawBack(lcd);

    needRedraw = false;
}

void SmartHomeScreen::update(LGFX &lcd)
{
    if (!needRedraw)
        return;

    drawRow(lcd, previous);

    drawRow(lcd, selected);

    if (selected == SmartHomeMenu::Lamp)
        drawLamp(lcd);

    needRedraw = false;
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

    lcd.fillRect(
        20,
        y - 2,
        440,
        24,
        Theme::Background);

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

    lcd.fillRect(
        20,
        y - 2,
        440,
        24,
        Theme::Background);

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

    lcd.fillRect(
        20,
        y - 2,
        440,
        24,
        Theme::Background);

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

    lcd.fillRect(
        20,
        y - 2,
        440,
        24,
        Theme::Background);

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
    previous = selected;

    uint8_t index = static_cast<uint8_t>(selected);

    index++;

    if (index >= static_cast<uint8_t>(SmartHomeMenu::Count))
        index = 0;

    selected = static_cast<SmartHomeMenu>(index);

    needRedraw = true;
}

void SmartHomeScreen::previousWidget()
{
    previous = selected;

    int index = static_cast<int>(selected);

    index--;

    if (index < 0)
        index = static_cast<int>(SmartHomeMenu::Count) - 1;

    selected = static_cast<SmartHomeMenu>(index);

    needRedraw = true;
}

void SmartHomeScreen::drawBack(LGFX &lcd)
{
    int y =
        Layout::SH_StartY +
        Layout::SH_RowHeight * 4;

    lcd.fillRect(
        20,
        y - 2,
        440,
        24,
        Theme::Background);

    lcd.drawFastHLine(
        20,
        y - 12,
        440,
        TFT_DARKGREY);

    String prefix =
        selected == SmartHomeMenu::Back
            ? "> "
            : "  ";

    lcd.drawString(
        prefix + "Back",
        Layout::SH_TextX,
        y);
}

void SmartHomeScreen::activate()
{
    switch (selected)
    {
    case SmartHomeMenu::Lamp:

        controller.toggleLamp();

        needRedraw = true;

        break;

    default:

        break;
    }
}

void SmartHomeScreen::drawRow(
    LGFX &lcd,
    SmartHomeMenu menu)
{
    switch (menu)
    {
    case SmartHomeMenu::Lamp:
        drawLamp(lcd);
        break;

    case SmartHomeMenu::Fan:
        drawFan(lcd);
        break;

    case SmartHomeMenu::Speed:
        drawSpeed(lcd);
        break;

    case SmartHomeMenu::Swing:
        drawSwing(lcd);
        break;

    case SmartHomeMenu::Back:
        drawBack(lcd);
        break;

    default:
        break;
    }
}