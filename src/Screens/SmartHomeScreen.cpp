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
    drawFooterArea(lcd);

    needRedraw = false;

    lastLamp = appState.lamp;
    lastFan = appState.fan;
    lastSpeed = appState.fanSpeed;
    lastSwing = appState.swing;
}

void SmartHomeScreen::update(LGFX &lcd)
{
    if (needRedraw)
    {
        drawRow(lcd, previous);
        drawRow(lcd, selected);

        previous = selected;

        drawFooterArea(lcd);

        needRedraw = false;
    }

    if (lastLamp != appState.lamp)
    {
        drawLamp(lcd);
        lastLamp = appState.lamp;
    }

    if (lastFan != appState.fan)
    {
        drawFan(lcd);
        lastFan = appState.fan;
    }

    if (lastSpeed != appState.fanSpeed)
    {
        drawSpeed(lcd);
        lastSpeed = appState.fanSpeed;
    }

    if (lastSwing != appState.swing)
    {
        drawSwing(lcd);
        lastSwing = appState.swing;
    }
}

void SmartHomeScreen::drawHeader(LGFX &lcd)
{
    lcd.setFont(&fonts::Font4);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

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

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

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

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

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

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    String prefix =
        selected == SmartHomeMenu::Speed
            ? "> "
            : "  ";

    lcd.drawString(
        prefix + "Speed",
        Layout::SH_TextX,
        y);

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

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

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
    lcd.fillRect(
        20,
        Layout::SH_BackY - 2,
        440,
        24,
        Theme::Background);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        selected == SmartHomeMenu::Back
            ? Theme::Accent
            : Theme::White,
        Theme::Background);

    lcd.drawString(
        "< Dashboard",
        Layout::SH_BackX,
        Layout::SH_BackY);
}

void SmartHomeScreen::activate()
{
    switch (selected)
    {
    case SmartHomeMenu::Lamp:
        controller.toggleLamp();
        break;

    case SmartHomeMenu::Fan:
        controller.toggleFan();
        break;

    case SmartHomeMenu::Speed:

        switch (appState.fanSpeed)
        {
        case FanSpeed::Low:
            controller.setFanSpeed(FanSpeed::Medium);
            break;

        case FanSpeed::Medium:
            controller.setFanSpeed(FanSpeed::High);
            break;

        case FanSpeed::High:
            controller.setFanSpeed(FanSpeed::Low);
            break;
        }

        break;

    default:
        break;
    }

    needRedraw = true;
}

void SmartHomeScreen::drawRow(LGFX &lcd, SmartHomeMenu menu)
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

SmartHomeMenu SmartHomeScreen::currentMenu() const
{
    return selected;
}

void SmartHomeScreen::drawHint(LGFX &lcd)
{
    lcd.fillRect(
        20,
        Layout::SH_HintY - 2,
        440,
        18,
        Theme::Background);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        TFT_DARKGREY,
        Theme::Background);

    String hint;

    switch (selected)
    {
    case SmartHomeMenu::Lamp:
        hint = "Press to toggle lamp";
        break;

    case SmartHomeMenu::Fan:
        hint = "Press to toggle fan";
        break;

    case SmartHomeMenu::Speed:
        hint = "Press to change speed";
        break;

    case SmartHomeMenu::Swing:
        hint = "Press to toggle swing";
        break;

    case SmartHomeMenu::Back:
        hint = "Return to dashboard";
        break;

    default:
        hint = "";
        break;
    }

    lcd.drawCentreString(
        hint,
        240,
        Layout::SH_HintY);
}

void SmartHomeScreen::drawFooterArea(LGFX &lcd)
{
    lcd.drawFastHLine(
        30,
        Layout::SH_SeparatorY,
        420,
        TFT_DARKGREY);

    drawHint(lcd);

    drawBack(lcd);
}