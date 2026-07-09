#pragma once

#include "Drivers/RelayDriver.hpp"
#include "Drivers/IRSender.hpp"
#include "Pins.hpp"
#include "AppState.hpp"

class SmartHomeController
{
public:
    void begin();

    void turnLampOn();
    void turnLampOff();
    void toggleLamp();
    bool isLampOn() const;

    void turnFanOn();
    void turnFanOff();
    void toggleFan();
    bool isFanOn() const;

    void setFanSpeed(FanSpeed speed);
    void setSwing(bool enable);
    void setMagicWind(bool enable);
    void setTimer(uint8_t hour);

private:
    RelayDriver lampRelay{Pins::RelayLamp};
    RelayDriver fanRelay{Pins::RelayFan};

    IRSender irSender;

    void syncLamp();

    void syncFan();

    void sendPower();

    void sendSpeed(FanSpeed);

    void sendSwing();

    void sendMagicWind();

    void sendTimer(uint8_t);
};