#include "Application.hpp"
#include "DirtyFlags.hpp"
#include "AppState.hpp"
#include "WiFiManager.hpp"
#include "TimeManager.hpp"

Application::Application()
    : uiController(encoder, smartHome)
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
    irReceiver.begin();
    irSender.begin();
    camera.begin();
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

        uiController.update(lcd);
    uiController.render(lcd);
}