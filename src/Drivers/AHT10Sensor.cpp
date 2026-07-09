#include "Drivers/AHT10Sensor.hpp"
#include "Pins.hpp"
#include "AppState.hpp"
#include "DirtyFlags.hpp"

bool AHT10Sensor::begin()
{
    Wire.begin(Pins::SDA, Pins::SCL);

    if (!sensor.begin())
    {
        Serial.println("AHT10 FAIL");
        return false;
    }

    Serial.println("AHT10 OK");

    return true;
}

void AHT10Sensor::update()
{
    if (millis() - lastRead < 2000)
        return;

    lastRead = millis();

    float t = sensor.readTemperature();
    float h = sensor.readHumidity();

    if (isnan(t) || isnan(h))
        return;

    appState.temperature = t;
    appState.humidity = h;

    dirty.footer = true;
}