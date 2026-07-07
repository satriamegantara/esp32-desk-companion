#include "UpdateManager.hpp"
#include "AppState.hpp"
#include "DirtyFlags.hpp"

#include <Arduino.h>

void UpdateManager::update()
{
    static uint32_t last = 0;

    if (millis() - last >= 1000)
    {
        last = millis();

        appState.freeHeap = ESP.getFreeHeap();

        // dummy clock
        static int second = 35;

        second++;

        char buffer[6];

        sprintf(buffer, "21:%02d", second % 60);

        if (appState.time != buffer)
        {
            appState.time = buffer;

            dirty.clock = true;
        }
    }
}