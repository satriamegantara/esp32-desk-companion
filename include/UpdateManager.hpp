#pragma once

#include <Arduino.h>

class UpdateManager
{
public:
    void update();

private:
    uint32_t last100ms = 0;
    uint32_t last500ms = 0;
    uint32_t last1s = 0;
};