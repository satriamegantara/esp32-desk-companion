#include "Application.hpp"
#include "DirtyFlags.hpp"
#include "AppState.hpp"

void Application::begin(LGFX &lcd)
{
    inputManager.begin();
    screenManager.begin(lcd);
}

void Application::update(LGFX &lcd)
{
    inputManager.update();
    updateManager.update();

    if (inputManager.press())
    {
        screenManager.nextScreen(lcd);
    }

    static uint32_t lastUpdate = 0;

    if (millis() - lastUpdate >= 1000)
    {
        lastUpdate = millis();
        dirty.footer = true;
    }

    appState.freeHeap = ESP.getFreeHeap() / 1024;
    appState.uptime = millis() / 1000;
    Serial.println(ESP.getFreeHeap());
    screenManager.update(lcd);
}