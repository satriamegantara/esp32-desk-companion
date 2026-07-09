#pragma once

#include "Drivers/RelayDriver.hpp"

class SmartHomeController
{
public:
    void begin();

    void toggleLamp();

    void toggleFan();

private:
    RelayDriver relay;
};