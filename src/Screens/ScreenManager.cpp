#include "Screens/ScreenManager.hpp"

void ScreenManager::begin(LGFX &lcd)
{
    display = &lcd;

    screens[0] = &dashboard;
    screens[1] = &smartHome;
    screens[2] = &camera;
    screens[3] = &system;

    current = 0;

    screens[current]->begin(lcd);
}

void ScreenManager::update(LGFX &lcd)
{
    screens[current]->update(lcd);
}

void ScreenManager::nextScreen(LGFX &lcd)
{
    screens[current]->end();

    current++;

    if (current >= SCREEN_COUNT)
        current = 0;

    lcd.fillScreen(TFT_BLACK);

    screens[current]->begin(lcd);
}

void ScreenManager::nextWidget()
{
    screens[current]->nextWidget();
}

void ScreenManager::previousWidget()
{
    screens[current]->previousWidget();
}

void ScreenManager::activateCurrent()
{
    screens[current]->activate();
}

void ScreenManager::open(ScreenID screen, LGFX &lcd)
{

    screens[current]->end();

    switch (screen)
    {
    case ScreenID::Dashboard:
        current = 0;
        break;

    case ScreenID::SmartHome:
        current = 1;
        break;

    case ScreenID::Camera:
        current = 2;
        break;

    case ScreenID::System:
        current = 3;
        break;
    }

    screens[current]->begin(lcd);
}

ScreenID ScreenManager::currentScreen() const
{
    switch (current)
    {
    case 0:
        return ScreenID::Dashboard;
    case 1:
        return ScreenID::SmartHome;
    case 2:
        return ScreenID::Camera;
    case 3:
        return ScreenID::System;
    default:
        return ScreenID::Dashboard;
    }
}

DashboardScreen &ScreenManager::getDashboard()
{
    return dashboard;
}