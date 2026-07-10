#include "UpdateManager.hpp"

#include <Arduino.h>

#include "DirtyFlags.hpp"

extern DirtyFlags dirty;

void UpdateManager::update()
{
    uint32_t now = millis();

    //----------------------------
    // 100 ms
    //----------------------------
    if (now - last100ms >= 100)
    {
        last100ms = now;

        dirty.smartHome = true;
    }

    //----------------------------
    // 500 ms
    //----------------------------
    if (now - last500ms >= 500)
    {
        last500ms = now;

        dirty.camera = true;
    }

    //----------------------------
    // 1 second
    //----------------------------
    if (now - last1s >= 1000)
    {
        last1s = now;

        dirty.clock = true;
        dirty.footer = true;
        dirty.system = true;
    }
}