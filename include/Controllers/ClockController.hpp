#pragma once

#include "TimeManager.hpp"

class ClockController
{
public:
    void begin();

    void update();

private:
    TimeManager timeManager;
};