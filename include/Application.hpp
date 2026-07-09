#pragma once

#include "LGFX_Config.hpp"
#include "Screens/ScreenManager.hpp"
#include "UpdateManager.hpp"
#include "InputManager.hpp"
#include "Drivers/Encoder.hpp"
#include "Drivers/RelayDriver.hpp"
#include "Drivers/IRReceiver.hpp"
#include "Drivers/IRSender.hpp"
#include "Controllers/SmartHomeController.hpp"
#include "Controllers/EnvironmentController.hpp"
#include "Controllers/ClockController.hpp"
#include "Controllers/UIController.hpp"

class Application
{
public:
    Application();
    void begin(LGFX &lcd);
    void update(LGFX &lcd);

private:
    Encoder encoder;
    SmartHomeController smartHome;

    UIController uiController;

    UpdateManager updateManager;
    InputManager inputManager;
    IRReceiver irReceiver;
    IRSender irSender;

    EnvironmentController environment;
    ClockController clock;
};