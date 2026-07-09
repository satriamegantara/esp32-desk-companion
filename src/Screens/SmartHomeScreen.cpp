#include "Screens/SmartHomeScreen.hpp"
#include "Theme.hpp"

void SmartHomeScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    lcd.drawCentreString(
        "SMART HOME",
        240,
        20);
}

void SmartHomeScreen::update(LGFX &lcd)
{
    // Implement the update logic for the Smart Home screen here
}