#include <Arduino.h>

#include "Application.hpp"
#include "Screens/DashboardScreen.hpp"

LGFX lcd;
Application app;

constexpr uint32_t FRAME_TIME = 16; // sekitar 60 FPS

void setup()
{
    Serial.begin(115200);

    lcd.init();
    lcd.setRotation(1);

    app.begin(lcd);
}

void loop()
{
    static uint32_t lastFrame = 0;

    if (millis() - lastFrame >= FRAME_TIME)
    {
        lastFrame = millis();
        app.update(lcd);
    }
}