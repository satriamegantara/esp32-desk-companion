#include "Controllers/SystemController.hpp"

#include <Arduino.h>

#include "AppState.hpp"

extern AppState appState;

void SystemController::begin()
{
}

void SystemController::update()
{
    appState.freeHeap =
        ESP.getFreeHeap() / 1024;

    appState.cpuMHz =
        getCpuFrequencyMhz();

    appState.psramSize =
        ESP.getPsramSize() / 1024 / 1024;

    appState.flashSize =
        ESP.getFlashChipSize() / 1024 / 1024;

    appState.uptime =
        millis() / 1000;
}