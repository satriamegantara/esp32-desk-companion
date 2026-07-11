#include "Application.hpp"
#include "DirtyFlags.hpp"
#include "AppState.hpp"
#include "WiFiManager.hpp"
#include "TimeManager.hpp"
#include "Pins.hpp"

Application::Application()
    : relayLamp(Pins::RelayLamp),
      relayAux(Pins::RelayAux),
      uiController(encoder, smartHome)
{
}

void Application::begin(LGFX &lcd)
{
    inputManager.begin();
    uiController.begin(lcd);
    wifiManager.begin();
    clock.begin();
    encoder.begin();
    environment.begin();
    weather.begin();
    system.begin();
    smartHome.begin();
    relayLamp.begin();
    relayAux.begin();
    irReceiver.begin();
    irSender.begin();
    camera.begin();

    // Serial.println();
    // Serial.println("===== Camera Bringup =====");
}

void Application::update(LGFX &lcd)
{
    encoder.update();
    inputManager.update();
    updateManager.update();
    wifiManager.update();
    clock.update();
    environment.update();
    weather.update();
    system.update();
    irReceiver.update();
    camera.update();

    appState.wifiConnected = wifiManager.connected();
    appState.ipAddress = wifiManager.ip();

    static uint32_t lastToggle = 0;
    static bool state = false;

    if (millis() - lastToggle > 2000)
    {
        lastToggle = millis();

        state = !state;

        if (state)
            relayLamp.on();
        else
            relayLamp.off();
    }

    uiController.update(lcd);
    uiController.render(lcd);
}
