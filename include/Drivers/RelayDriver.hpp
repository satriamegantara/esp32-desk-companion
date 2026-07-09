#pragma once

#include <Arduino.h>

class RelayDriver
{
public:
    explicit RelayDriver(uint8_t pin, bool activeLow = true);

    void begin();

    void on();

    void off();

    void toggle();

    bool isOn() const;

private:
    uint8_t pin;

    bool activeLow;

    bool state = false;
};