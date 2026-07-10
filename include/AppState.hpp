#pragma once

#include <Arduino.h>
#include "CameraState.hpp"
#include "WeatherState.hpp"

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

enum class FanSpeed
{
    Low,
    Medium,
    High
};

struct AppState
{
    // Clock
    String time = "21:35:23";
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
    uint16_t cpuFreq = 0;
    uint32_t psramSize = 0;
    uint32_t flashSize = 0;

    // Fan
    FanSpeed fanSpeed = FanSpeed::Low;
    bool swing = false;
    bool magicWind = false;
    uint8_t timerHour = 0;

    // Camera
    CameraState cameraState = CameraState::Mock;

    // Weather
    WeatherData weather;

    NavigationMode navigation =
        NavigationMode::Dashboard;
};

extern AppState appState;