#include "Screens/ScreenManager.hpp"

void ScreenManager::begin(LGFX &lcd)
{
    screens[0] = &dashboard;
    screens[1] = &system;

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