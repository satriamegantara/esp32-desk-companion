#include <Arduino.h>

#include "Application.hpp"
#include "Screens/DashboardScreen.hpp"
#include "Camera/CameraDriver.hpp"
#include "Camera/CameraConfig.hpp"

LGFX lcd;
Application app;

constexpr uint32_t FRAME_TIME = 16; // sekitar 60 FPS

// void setup()
// {
//     Serial.begin(115200);

//     lcd.init();
//     lcd.setRotation(1);

//     app.begin(lcd);
// }

// void loop()
// {
//     static uint32_t lastFrame = 0;

//     if (millis() - lastFrame >= FRAME_TIME)
//     {
//         lastFrame = millis();
//         app.update(lcd);
//     }
// }

CameraDriver camera;

void setup()
{
    pinMode(16, OUTPUT);
    Serial.begin(115200);

    if (camera.begin())
    {
        camera.capture();
    }
}

void loop()
{
    digitalWrite(16, LOW);
    delay(3000);

    digitalWrite(16, HIGH);
    delay(3000);
    camera.begin();
}