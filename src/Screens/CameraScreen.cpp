#include "Screens/CameraScreen.hpp"
#include "Theme.hpp"

void CameraScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    cameraWidget.draw(lcd);
}

void CameraScreen::update(LGFX &lcd)
{
    cameraWidget.update(lcd);
}

void CameraScreen::end()
{
}

void CameraScreen::nextWidget()
{
}

void CameraScreen::previousWidget()
{
}