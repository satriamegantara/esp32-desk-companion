#pragma once

#include "Screen.hpp"

class SystemScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;

    void update(LGFX &lcd) override;

    void end() override;

    void nextWidget() override;
    void previousWidget() override;

private:
    bool backSelected = true;

    void drawBack(LGFX &lcd);
};