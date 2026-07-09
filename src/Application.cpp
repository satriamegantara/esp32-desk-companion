#include "Application.hpp"
#include "DirtyFlags.hpp"
#include "AppState.hpp"
#include "WiFiManager.hpp"
#include "TimeManager.hpp"
#include "Pins.hpp"

void Application::begin(LGFX &lcd)
{
    inputManager.begin();
    screenManager.begin(lcd);
    wifiManager.begin();
    clock.begin();
    encoder.begin();
    environment.begin();
    smartHome.begin();
    irReceiver.begin();
    irSender.begin();

    pinMode(Pins::BootButton, INPUT_PULLUP);
}

void Application::update(LGFX &lcd)
{
    encoder.update();
    inputManager.update();
    updateManager.update();
    wifiManager.update();
    clock.update();
    environment.update();
    irReceiver.update();

    appState.wifiConnected = wifiManager.connected();

    appState.ipAddress = wifiManager.ip();

    if (encoder.right())
    {
        if (appState.focus == FocusItem::Lamp)
            appState.focus = FocusItem::Fan;
        else
            appState.focus = FocusItem::Lamp;

        dirty.smartHome = true;
    }

    if (encoder.pressed())
    {
        if (appState.focus == FocusItem::Lamp)
            smartHome.toggleLamp();

        else
            smartHome.toggleFan();
    }

    static uint32_t lastUpdate = 0;

    if (millis() - lastUpdate >= 1000)
    {
        lastUpdate = millis();
        dirty.footer = true;
    }

    static bool last = HIGH;

    bool now = digitalRead(Pins::BootButton);

    if (last == HIGH && now == LOW)
    {
        if (appState.focus == FocusItem::Lamp)
        {
            appState.lamp = !appState.lamp;
        }
        else
        {
            appState.fan = !appState.fan;
        }

        dirty.smartHome = true;
    }

    last = now;

    appState.freeHeap = ESP.getFreeHeap() / 1024;
    appState.uptime = millis() / 1000;
    screenManager.update(lcd);
}