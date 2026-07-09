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
    void update();
    void render(LGFX &lcd);

private:
    void handleNavigation();
    void handleSelection();
    void handleBootButton();

    void focusNext();
    void activateFocusedItem();

    ScreenManager screenManager;

    Encoder &encoder;
    SmartHomeController &smartHome;
};