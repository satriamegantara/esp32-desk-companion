#include <Arduino.h>

#include "LGFX_Config.hpp"
#include "Application.hpp"

LGFX lcd;
Application app;

void setup()
{
    Serial.begin(115200);

    lcd.init();
    lcd.setRotation(1);

    app.begin(lcd);
}

void loop()
{
    app.update(lcd);

    delay(10);
}