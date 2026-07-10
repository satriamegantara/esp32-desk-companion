#include "Controllers/WeatherController.hpp"

#include <Arduino.h>

#include "AppState.hpp"
#include "DirtyFlags.hpp"

extern AppState appState;
extern DirtyFlags dirty;

void WeatherController::begin()
{
    appState.weather.city = "Purwokerto";
    appState.weather.description = "Sunny";

    appState.weather.temperature = 30.0f;
    appState.weather.humidity = 65.0f;
}

void WeatherController::update()
{
    if (millis() - lastUpdate < 5000)
        return;

    lastUpdate = millis();

    static uint8_t state = 0;

    state = (state + 1) % 5;

    switch (state)
    {
    case 0:
        appState.weather.description = "Sunny";
        appState.weather.temperature = 31;
        break;

    case 1:
        appState.weather.description = "Cloudy";
        appState.weather.temperature = 29;
        break;

    case 2:
        appState.weather.description = "Rain";
        appState.weather.temperature = 26;
        break;

    case 3:
        appState.weather.description = "Storm";
        appState.weather.temperature = 24;
        break;

    case 4:
        appState.weather.description = "Clear";
        appState.weather.temperature = 28;
        break;
    }

    appState.weather.humidity =
        random(60, 90);

    dirty.clock = true;
}