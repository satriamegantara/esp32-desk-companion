#pragma once

#include "LGFX_Config.hpp"
#include "Rect.hpp"

namespace UIRenderer
{

    void drawCard(
        LGFX &lcd,
        const Rect &rect,
        const char *title);

}