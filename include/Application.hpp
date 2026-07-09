#pragma once

#include "LGFX_Config.hpp"
#include "Screens/ScreenManager.hpp"
#include "UpdateManager.hpp"
#include "InputManager.hpp"
#include "Drivers/Encoder.hpp"
#include "Drivers/AHT10Sensor.hpp"
#include "Drivers/RelayDriver.hpp"
#include "Drivers/IRReceiver.hpp"
#include "Drivers/IRSender.hpp"
#include "Controllers/SmartHomeController.hpp"
#include "Controllers/EnvironmentController.hpp"
#include "Controllers/ClockController.hpp"

class Application
{
public:
    void begin(LGFX &lcd);
    void update(LGFX &lcd);

private:
    ScreenManager screenManager;
    UpdateManager updateManager;
    InputManager inputManager;
    Encoder encoder;
    AHT10Sensor aht10;
    IRReceiver irReceiver;
    IRSender irSender;
    SmartHomeController smartHome;
    EnvironmentController environment;
    ClockController clock;
};