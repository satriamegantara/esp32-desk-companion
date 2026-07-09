#pragma once

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "Pins.hpp"

class IRReceiver
{
public:
    bool begin();

    void update();

private:
    IRrecv receiver{Pins::IRReceiver};

    decode_results results;
};