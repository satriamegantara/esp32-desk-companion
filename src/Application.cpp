#include "Application.hpp"

void Application::begin(LGFX& lcd)
{
    inputManager.begin();
    screenManager.begin(lcd);
}

void Application::update(LGFX& lcd)
{
    inputManager.update();
    updateManager.update();

    if(inputManager.press())
    {
        screenManager.nextScreen(lcd);
    }

    screenManager.update(lcd);
}