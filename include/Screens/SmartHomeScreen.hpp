#pragma once

#include "Screen.hpp"

class SmartHomeScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
};