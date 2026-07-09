#include "Drivers/RelayDriver.hpp"
#include "Pins.hpp"

void RelayDriver::begin()
{
    pinMode(Pins::RelayLamp, OUTPUT);
    pinMode(Pins::RelayFan, OUTPUT);

    digitalWrite(Pins::RelayLamp, HIGH);
    digitalWrite(Pins::RelayFan, HIGH);
}

RelayDriver::RelayDriver(uint8_t pin, bool activeLow)
    : pin(pin),
      activeLow(activeLow)
{
}

void RelayDriver::on()
{
    state = true;

    digitalWrite(
        pin,
        activeLow ? LOW : HIGH);
}

void RelayDriver::off()
{
    state = false;

    digitalWrite(
        pin,
        activeLow ? HIGH : LOW);
}

void RelayDriver::toggle()
{
    if (state)
        off();
    else
        on();
}

bool RelayDriver::isOn() const
{
    return state;
}