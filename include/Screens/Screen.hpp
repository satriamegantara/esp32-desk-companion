#pragma once

#include "LGFX_Config.hpp"

class Screen
{
public:
    virtual ~Screen() = default;

    virtual void begin(LGFX &lcd) = 0;
    virtual void update(LGFX &lcd) = 0;
    virtual void end() {}

    virtual void nextWidget() = 0;

    virtual void previousWidget() = 0;
};