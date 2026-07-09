#pragma once

#include "Screen.hpp"
#include "Widgets/CameraWidget.hpp"

class CameraScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override;

    void nextWidget() override;
    void previousWidget() override;

private:
    CameraWidget cameraWidget;
};