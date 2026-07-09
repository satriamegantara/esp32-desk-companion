#pragma once

#include "Screen.hpp"

#include "DashboardScreen.hpp"
#include "SystemScreen.hpp"
#include "CameraScreen.hpp"
#include "ScreenID.hpp"
#include "SmartHomeScreen.hpp"

class ScreenManager
{
public:
    void begin(LGFX &lcd);
    void update(LGFX &lcd);
    void nextScreen(LGFX &lcd);

    void nextWidget();
    void previousWidget();
    void activateCurrent();

    void open(ScreenID screen, LGFX &lcd);

    ScreenID currentScreen() const;
    DashboardScreen &getDashboard();

private:
    LGFX *display = nullptr;

    static constexpr uint8_t SCREEN_COUNT = 4;

    DashboardScreen dashboard;

    SmartHomeScreen smartHome;

    CameraScreen camera;

    SystemScreen system;

    Screen *screens[SCREEN_COUNT];

    uint8_t current = 0;
};