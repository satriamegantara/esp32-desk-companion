#pragma once

#include <IRremoteESP8266.h>
#include <IRsend.h>

class IRSender
{
public:
    IRSender();

    void begin();

    void sendPowerOn();

    void sendPowerOff();

    void sendSwing();

    void sendTimer();

    void sendMagicWind();

private:
    IRsend irsend;
};