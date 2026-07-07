#pragma once

#include "LGFX_Config.hpp"

class Widget
{
public:
    virtual void begin(LGFX &) {}
    virtual void draw(LGFX &) = 0;
    virtual void update(LGFX &) {}
    virtual ~Widget() = default;
};