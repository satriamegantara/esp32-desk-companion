#include "TimeManager.hpp"

#include <WiFi.h>
#include <time.h>

#include "AppState.hpp"
#include "DirtyFlags.hpp"

TimeManager timeManager;

void TimeManager::begin()
{
    configTime(
        7 * 3600, // GMT+7
        0,
        "pool.ntp.org",
        "time.nist.gov");
}

void TimeManager::update()
{
    if (WiFi.status() != WL_CONNECTED)
        return;

    struct tm timeinfo;

    if (!getLocalTime(&timeinfo))
        return;

    char buf[10];

    strftime(buf, sizeof(buf), "%H:%M:%S", &timeinfo);

    appState.time = String(buf);

    char day[20];

    strftime(day, sizeof(day), "%A", &timeinfo);

    appState.day = String(day);

    dirty.clock = true;
}