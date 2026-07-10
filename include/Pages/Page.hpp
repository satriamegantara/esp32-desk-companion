#pragma once

#include "LGFX_Config.hpp"

class Page
{
public:
    virtual ~Page() = default;

    virtual void draw(LGFX &lcd) = 0;

    virtual void update(LGFX &lcd) = 0;
};