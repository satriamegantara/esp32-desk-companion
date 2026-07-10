#include "Screens/WeatherScreen.hpp"

#include "AppState.hpp"
#include "Theme.hpp"

extern AppState appState;

void WeatherScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.setFont(&fonts::Font4);

    lcd.drawCentreString(
        "Weather",
        240,
        20);

    lcd.setFont(&fonts::Font8);

    lcd.drawCentreString(
        String((int)appState.weather.temperature) + " C",
        240,
        70);

    lcd.setFont(&fonts::Font4);

    lcd.drawCentreString(
        appState.weather.description,
        240,
        145);

    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString(
        appState.weather.city,
        240,
        175);

    lcd.drawString(
        "Humidity",
        40,
        225);

    lcd.drawRightString(
        String((int)appState.weather.humidity) + " %",
        440,
        225);

    drawBack(lcd);
}

void WeatherScreen::update(LGFX &lcd)
{
    static uint32_t last = 0;

    if (millis() - last < 1000)
        return;

    last = millis();

    lcd.fillRect(
        120,
        60,
        240,
        40,
        Theme::Background);

    lcd.setFont(&fonts::Font8);

    lcd.drawCentreString(
        String((int)appState.weather.temperature) + "°C",
        240,
        70);

    lcd.setFont(&fonts::Font4);

    lcd.fillRect(
        80,
        140,
        320,
        25,
        Theme::Background);

    lcd.drawCentreString(
        appState.weather.description,
        240,
        145);

    lcd.fillRect(
        80,
        170,
        320,
        20,
        Theme::Background);

    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString(
        appState.weather.city,
        240,
        175);

    lcd.fillRect(
        300,
        220,
        140,
        20,
        Theme::Background);

    lcd.drawRightString(
        String((int)appState.weather.humidity) + " %",
        440,
        225);
}

void WeatherScreen::end()
{
}

void WeatherScreen::nextWidget()
{
}

void WeatherScreen::previousWidget()
{
}

void WeatherScreen::drawBack(LGFX &lcd)
{
    lcd.drawFastHLine(
        20,
        285,
        440,
        TFT_DARKGREY);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::Accent,
        Theme::Background);

    lcd.drawString(
        "< Dashboard",
        40,
        295);
}