#include "Controllers/WeatherController.hpp"

#include <Arduino.h>

#include "AppState.hpp"
#include "DirtyFlags.hpp"

#include "Controllers/WeatherController.hpp"

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "Secrets.hpp"
#include "AppState.hpp"

extern AppState appState;
extern DirtyFlags dirty;

bool WeatherController::begin()
{
    return true;
}

void WeatherController::update()
{
    if (!WiFi.isConnected())
        return;

    if (millis() - lastUpdate < 60000)
        return;

    lastUpdate = millis();

    fetchWeather();
}

bool WeatherController::fetchWeather()
{
    String url =
        "https://api.openweathermap.org/data/2.5/weather?q=";

    url += Secrets::CITY;
    url += ",";
    url += Secrets::COUNTRY;
    url += "&units=metric";
    url += "&appid=";
    url += Secrets::OPENWEATHER_API_KEY;

    HTTPClient http;

    http.begin(url);

    int httpCode = http.GET();

    if (httpCode != HTTP_CODE_OK)
    {
        Serial.print("Weather Error : ");

        Serial.println(httpCode);

        http.end();

        return false;
    }

    String payload =
        http.getString();

    JsonDocument doc;

    DeserializationError error =
        deserializeJson(
            doc,
            payload);

    if (error)
    {
        Serial.print("JSON Error : ");

        Serial.println(error.c_str());

        http.end();

        return false;
    }

    appState.weather.temperature =
        doc["main"]["temp"];

    appState.weather.humidity =
        doc["main"]["humidity"];

    appState.weather.city =
        doc["name"].as<String>();

    appState.weather.description =
        doc["weather"][0]["description"].as<String>();

    appState.weather.feelsLike =
        doc["main"]["feels_like"];

    appState.weather.windSpeed =
        doc["wind"]["speed"];

    String icon =
        doc["weather"][0]["icon"].as<String>();

    if (icon.startsWith("01"))
        appState.weather.icon = WeatherIcon::Clear;

    else if (
        icon.startsWith("02") ||
        icon.startsWith("03") ||
        icon.startsWith("04"))
        appState.weather.icon = WeatherIcon::Cloud;

    else if (
        icon.startsWith("09") ||
        icon.startsWith("10"))
        appState.weather.icon = WeatherIcon::Rain;

    else if (icon.startsWith("11"))
        appState.weather.icon = WeatherIcon::Storm;

    else if (icon.startsWith("13"))
        appState.weather.icon = WeatherIcon::Snow;

    else if (icon.startsWith("50"))
        appState.weather.icon = WeatherIcon::Mist;

    else
        appState.weather.icon = WeatherIcon::Unknown;

    // Serial.println("====== WEATHER ======");

    // Serial.print("City        : ");

    // Serial.println(appState.weather.city);

    // Serial.print("Temperature : ");

    // Serial.print(appState.weather.temperature);

    // Serial.println(" °C");

    // Serial.print("Humidity    : ");

    // Serial.print(appState.weather.humidity);

    // Serial.println(" %");

    // Serial.print("Description : ");

    // Serial.println(appState.weather.description);

    // Serial.print("Feels Like : ");

    // Serial.println(appState.weather.feelsLike);

    // Serial.print("Wind Speed : ");

    // Serial.println(appState.weather.windSpeed);

    // Serial.print("Icon Type : ");

    // switch (appState.weather.icon)
    // {
    // case WeatherIcon::Clear:
    //     Serial.println("Clear");
    //     break;

    // case WeatherIcon::Cloud:
    //     Serial.println("Cloud");
    //     break;

    // case WeatherIcon::Rain:
    //     Serial.println("Rain");
    //     break;

    // case WeatherIcon::Storm:
    //     Serial.println("Storm");
    //     break;

    // case WeatherIcon::Snow:
    //     Serial.println("Snow");
    //     break;

    // case WeatherIcon::Mist:
    //     Serial.println("Mist");
    //     break;

    // default:
    //     Serial.println("Unknown");
    // }

    // Serial.println("=====================");

    http.end();

    return true;
}