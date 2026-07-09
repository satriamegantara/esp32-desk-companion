#include "Controllers/SmartHomeController.hpp"

#include "AppState.hpp"
#include "DirtyFlags.hpp"

extern AppState appState;
extern DirtyFlags dirty;

void SmartHomeController::begin()
{
    relay.begin();
}

void SmartHomeController::toggleLamp()
{
    appState.lamp = !appState.lamp;

    relay.setLamp(appState.lamp);

    dirty.smartHome = true;
}

void SmartHomeController::toggleFan()
{
    appState.fan = !appState.fan;

    relay.setFan(appState.fan);

    dirty.smartHome = true;
}