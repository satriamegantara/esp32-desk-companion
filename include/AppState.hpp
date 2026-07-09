#pragma once

#include <Arduino.h>

enum class FocusItem
{
    Lamp,
    Fan
};

enum class NavigationMode
{
    Dashboard,
    Widget
};

struct AppState
{
    // Clock
    String time = "21:35";
    String day = "Monday";

    // WiFi
    bool wifiConnected = false;
    String ipAddress;

    // Smart Home
    bool lamp = false;
    bool fan = false;

    FocusItem focus = FocusItem::Lamp;
    NavigationMode navigationMode = NavigationMode::Dashboard;

    // Environment
    float temperature = 30.0;
    float humidity = 65.0;

    // System
    uint32_t freeHeap = 0;
    uint32_t uptime = 0;
};

extern AppState appState;