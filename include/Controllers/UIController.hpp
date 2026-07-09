#pragma once

#include "LGFX_Config.hpp"
#include "Screens/ScreenManager.hpp"
#include "Drivers/Encoder.hpp"
#include "Controllers/SmartHomeController.hpp"

class UIController
{
public:
    UIController(Encoder &encoder,
                 SmartHomeController &smartHome);

    void begin(LGFX &lcd);
    void update(LGFX &lcd);
    void render(LGFX &lcd);

private:
    void handleNavigation();
    void handleSelection(LGFX &lcd);
    void handleBootButton();

    void focusNext();
    void activateFocusedItem();

    ScreenManager screenManager;

    Encoder &encoder;
    SmartHomeController &smartHome;
};