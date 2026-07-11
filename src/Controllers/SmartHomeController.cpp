#include "Controllers/SmartHomeController.hpp"

#include "AppState.hpp"
#include "DirtyFlags.hpp"

extern AppState appState;
extern DirtyFlags dirty;

void SmartHomeController::begin()
{
    lampRelay.begin();
    auxRelay.begin();
    irSender.begin();
}

void SmartHomeController::syncLamp()
{
    appState.lamp = lampRelay.isOn();
    dirty.smartHome = true;
}

void SmartHomeController::syncFan()
{
    appState.fan = auxRelay.isOn();
    dirty.smartHome = true;
}

void SmartHomeController::turnLampOn()
{
    lampRelay.on();
    syncLamp();
}

void SmartHomeController::turnLampOff()
{
    lampRelay.off();
    syncLamp();
}

void SmartHomeController::toggleLamp()
{
    lampRelay.toggle();
    syncLamp();
}

bool SmartHomeController::isLampOn() const
{
    return appState.lamp;
}

void SmartHomeController::turnFanOn()
{
    auxRelay.on();

    irSender.sendPower();

    syncFan();
}

void SmartHomeController::turnFanOff()
{
    auxRelay.off();

    irSender.sendPower();

    syncFan();
}

void SmartHomeController::toggleFan()
{
    if (appState.fan)
        turnFanOff();
    else
        turnFanOn();
}

bool SmartHomeController::isFanOn() const
{
    return appState.fan;
}

void SmartHomeController::setFanSpeed(FanSpeed speed)
{
    if (!appState.fan)
        return;

    switch (speed)
    {
    case FanSpeed::Low:
        irSender.sendLow();
        break;

    case FanSpeed::Medium:
        irSender.sendMedium();
        break;

    case FanSpeed::High:
        irSender.sendHigh();
        break;
    }

    appState.fanSpeed = speed;

    dirty.smartHome = true;
}

void SmartHomeController::setSwing(bool enable)
{
    if (enable)
    {
        irSender.sendSwing();
    }

    // TODO:
    // Miyako remote uses toggle command.
    // Need state synchronization.
}

void SmartHomeController::setMagicWind(bool enable)
{
    if (enable)
    {
        irSender.sendMagicWind();
    }

    // TODO:
}

void SmartHomeController::setTimer(uint8_t hour)
{
    // TODO:
    // Repeat sendTimer() depending on protocol.
}

void SmartHomeController::sendPower()
{
    // TODO:
}

void SmartHomeController::sendSpeed(FanSpeed)
{
    // TODO:
}

void SmartHomeController::sendSwing()
{
    // TODO:
}

void SmartHomeController::sendMagicWind()
{
    // TODO:
}

void SmartHomeController::sendTimer(uint8_t)
{
    // TODO:
}