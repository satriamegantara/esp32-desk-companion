#include "Screens/SmartHomeScreen.hpp"
#include "Theme.hpp"

void SmartHomeScreen::begin(LGFX &lcd)
{

    lcd.fillScreen(TFT_BLUE);

    lcd.setTextColor(TFT_WHITE);
    lcd.setFont(&fonts::Font4);

    lcd.drawCentreString("SMART HOME", 240, 120);
}

void SmartHomeScreen::update(LGFX &lcd)
{
    // Implement the update logic for the Smart Home screen here
}