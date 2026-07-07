#pragma once

#include "LGFX_Config.hpp"
#include "Screens/ScreenManager.hpp"
#include "UpdateManager.hpp"

class Application
{
public:
    void begin(LGFX &lcd);
    void update(LGFX &lcd);

private:
    ScreenManager screenManager;
    UpdateManager updateManager;
};