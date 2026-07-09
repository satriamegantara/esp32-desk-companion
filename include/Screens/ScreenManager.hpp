#pragma once

#include "Screen.hpp"

#include "DashboardScreen.hpp"
#include "SystemScreen.hpp"
#include "CameraScreen.hpp"

class ScreenManager
{
public:
    void begin(LGFX &lcd);
    void update(LGFX &lcd);
    void nextScreen(LGFX &lcd);

    void nextWidget();

    void previousWidget();

private:
    static constexpr uint8_t SCREEN_COUNT = 3;

    DashboardScreen dashboard;

    CameraScreen camera;

    SystemScreen system;

    Screen *screens[SCREEN_COUNT];

    uint8_t current = 0;
};