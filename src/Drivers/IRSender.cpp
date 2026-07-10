#include <Arduino.h>
#include "Drivers/IRSender.hpp"
#include "IRCodes/MiyakoKAW1689.hpp"
#include "Pins.hpp"

IRSender::IRSender()
    : irsend(Pins::IRLed)
{
}

void IRSender::begin()
{
    irsend.begin();

    pinMode(Pins::IRLed, OUTPUT);

    digitalWrite(Pins::IRLed, HIGH);
    delay(1000);
    digitalWrite(Pins::IRLed, LOW);

    Serial.println("IR Sender Ready");
}

void IRSender::sendPower()
{
    Serial.println("SEND RAW");

    irsend.sendRaw(
        MiyakoIR::Power,
        MiyakoIR::PowerLength,
        38);

    Serial.println("DONE");
}

void IRSender::sendSwing()
{
    irsend.sendSymphony(0xD90, 12);
}

void IRSender::sendTimer()
{
    irsend.sendSymphony(0xD88, 12);
}

void IRSender::sendMagicWind()
{
    irsend.sendSymphony(0xD84, 12);
}

void IRSender::sendLow()
{
    // TODO raw code
}

void IRSender::sendMedium()
{
    // TODO raw code
}

void IRSender::sendHigh()
{
    // TODO raw code
}