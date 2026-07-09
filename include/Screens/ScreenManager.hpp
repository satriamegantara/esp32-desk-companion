#pragma once

#include "Screen.hpp"

#include "DashboardScreen.hpp"
#include "SystemScreen.hpp"

class ScreenManager
{
public:
    void begin(LGFX &lcd);
    void update(LGFX &lcd);
    void nextScreen(LGFX &lcd);

    void nextWidget();

    void previousWidget();

private:
    static constexpr uint8_t SCREEN_COUNT = 2;

    DashboardScreen dashboard;

    SystemScreen system;

    Screen *screens[SCREEN_COUNT];

    uint8_t current = 0;
};