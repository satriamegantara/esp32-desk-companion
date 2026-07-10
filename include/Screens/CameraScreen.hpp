#pragma once

#include "Screen.hpp"

class CameraScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;

    void update(LGFX &lcd) override;

    void end() override;

private:
    bool needRedraw = false;

    void drawHeader(LGFX &lcd);

    void drawPreview(LGFX &lcd);

    void drawStatus(LGFX &lcd);

    void drawInfo(LGFX &lcd);
};