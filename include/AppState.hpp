#pragma once

#include <Arduino.h>

struct AppState
{
    // Clock
    String time = "21:35";
    String day = "Monday";

    // WiFi
    bool wifiConnected = false;

    // Smart Home
    bool lamp = false;
    bool fan = false;

    // Environment
    float temperature = 30.0;
    float humidity = 65.0;

    // System
    uint32_t freeHeap = 0;
};

extern AppState appState;