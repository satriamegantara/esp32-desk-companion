#pragma once

#include <IRremoteESP8266.h>
#include <IRsend.h>

class IRSender
{
public:
    IRSender();

    void begin();

    void sendPower();

    void sendSwing();

    void sendTimer();

    void sendMagicWind();

    void sendLow();
    void sendMedium();
    void sendHigh();

private:
    IRsend irsend;
};