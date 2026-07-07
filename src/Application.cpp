#include "Application.hpp"

void Application::begin(LGFX& lcd)
{
    screenManager.begin(lcd);
}

void Application::update(LGFX& lcd)
{
    static uint32_t previous = millis();

    uint32_t now = millis();

    uint32_t delta = now - previous;

    previous = now;

    updateManager.update();

    screenManager.update(lcd);
}