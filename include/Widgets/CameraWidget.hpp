#pragma once

#include "Widget.hpp"

class CameraWidget : public Widget
{
public:
    void draw(LGFX &lcd) override;

    void update(LGFX &lcd) override;
};