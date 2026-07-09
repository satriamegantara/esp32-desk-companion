#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <AHT10.h>

class AHT10Sensor
{
public:
    bool begin();

    void update();

private:
    AHT10 sensor;

    uint32_t lastRead = 0;
};