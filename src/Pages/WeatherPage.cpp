#include "Pages/WeatherPage.hpp"

#include "AppState.hpp"
#include "Theme.hpp"

extern AppState appState;

static const char *weatherIconText(
    WeatherIcon icon)
{
    switch (icon)
    {
    case WeatherIcon::Clear:
        return "Clear";

    case WeatherIcon::Cloud:
        return "Cloud";

    case WeatherIcon::Rain:
        return "Rain";

    case WeatherIcon::Storm:
        return "Storm";

    case WeatherIcon::Snow:
        return "Snow";

    case WeatherIcon::Mist:
        return "Mist";

    default:
        return "UNKNOWN";
    }
}

static String capitalizeWords(
    String text)
{
    bool capitalize = true;

    for (size_t i = 0; i < text.length(); i++)
    {
        if (capitalize)
        {
            text[i] = toupper(text[i]);
            capitalize = false;
        }

        if (text[i] == ' ')
            capitalize = true;
    }

    return text;
}

void WeatherPage::draw(LGFX &lcd)
{
    lastTemperature = -999;
    lastHumidity = -999;
    lastFeelsLike = -999;
    lastWindSpeed = -999;

    lastDescription = "";
    lastCity = "";
    lastIcon = WeatherIcon::Unknown;

    lcd.fillScreen(Theme::Background);

    lcd.setTextColor(
        TFT_DARKGREY,
        Theme::Background);

    lcd.setFont(&fonts::Font4);

    lcd.drawCentreString(
        "WEATHER",
        240,
        20);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawCentreString(
        weatherIconText(appState.weather.icon),
        240,
        48);

    lcd.setFont(&fonts::Font8);

    lcd.drawCentreString(
        String(appState.weather.temperature, 1) + " C", 240,
        75);

    lcd.setFont(&fonts::Font4);

    lcd.drawCentreString(
        capitalizeWords(appState.weather.description),
        240,
        145);

    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString(
        appState.weather.city,
        240,
        170);

    lcd.setTextColor(
        TFT_DARKGREY,
        Theme::Background);

    lcd.drawString(
        "Feels Like",
        40,
        220);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawRightString(
        String(appState.weather.feelsLike, 1) + " C", 440,
        220);

    lcd.setTextColor(
        TFT_DARKGREY,
        Theme::Background);

    lcd.drawString(
        "Humidity",
        40,
        248);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawRightString(
        String((int)appState.weather.humidity) + "%",
        440,
        248);

    lcd.setTextColor(
        TFT_DARKGREY,
        Theme::Background);

    lcd.drawString(
        "Wind",
        40,
        276);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawRightString(
        String(appState.weather.windSpeed, 1) + " m/s",
        440,
        276);

    lcd.drawFastHLine(
        40,
        205,
        400,
        Theme::Primary);

    lcd.drawFastHLine(
        40,
        288,
        400,
        Theme::Primary);

    lcd.setTextColor(
        Theme::Accent,
        Theme::Background);

    lcd.drawString(
        "< Dashboard",
        40,
        296);
}

void WeatherPage::update(LGFX &lcd)
{
    if (lastTemperature != appState.weather.temperature)
    {
        lastTemperature =
            appState.weather.temperature;

        lcd.fillRect(
            120,
            75,
            240,
            45,
            Theme::Background);

        lcd.setFont(&fonts::Font8);

        lcd.setTextColor(
            Theme::White,
            Theme::Background);

        lcd.drawCentreString(
            String(lastTemperature, 1) + "°C",
            240,
            75);
    }

    // commit berikutnya lanjut humidity dll
}