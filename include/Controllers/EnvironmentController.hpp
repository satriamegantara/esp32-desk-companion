#pragma once

#include "Drivers/AHT10Sensor.hpp"

class EnvironmentController
{
public:
    void begin();

    void update();

private:
    AHT10Sensor sensor;
};