#include "Drivers/RelayDriver.hpp"
#include "Pins.hpp"

void RelayDriver::begin()
{
    pinMode(Pins::RelayLamp, OUTPUT);
    pinMode(Pins::RelayFan, OUTPUT);

    digitalWrite(Pins::RelayLamp, HIGH);
    digitalWrite(Pins::RelayFan, HIGH);
}

void RelayDriver::setLamp(bool on)
{
    digitalWrite(Pins::RelayLamp, on ? LOW : HIGH);
}

void RelayDriver::setFan(bool on)
{
    digitalWrite(Pins::RelayFan, on ? LOW : HIGH);
}