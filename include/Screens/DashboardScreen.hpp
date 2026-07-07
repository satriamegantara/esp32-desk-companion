#pragma once

#include "Screen.hpp"

class DashboardScreen : public Screen
{
public:

    void begin(LGFX& lcd) override;

    void update(LGFX& lcd) override;

    void end() override;
};