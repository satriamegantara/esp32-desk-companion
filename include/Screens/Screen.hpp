#pragma once

#include "LGFX_Config.hpp"

class Screen
{
public:
    virtual ~Screen() = default;

    virtual void begin(LGFX &lcd) = 0;
    virtual void update(LGFX &lcd) = 0;
    virtual void end() {}

    // WAJIB ADA
    virtual void activate() {}

    virtual void nextWidget() {}
    virtual void previousWidget() {}
};