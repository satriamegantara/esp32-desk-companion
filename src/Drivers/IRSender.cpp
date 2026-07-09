#include <Arduino.h>
#include "Drivers/IRSender.hpp"
#include "Pins.hpp"
#include <pgmspace.h>

const uint16_t powerOnRaw[] = {
    1260, 426, 1264, 420, 442, 1300, 1236, 428,
    1266, 422, 440, 1300, 422, 1296, 420, 1294,
    422, 1296, 424, 1292, 1236, 426, 442, 8146,
    1258, 428, 1266, 422, 440, 1302, 1236, 428,
    1266, 422, 440, 1300, 420, 1298, 420, 1296,
    420, 1298, 418, 1300, 1238, 426, 440, 8146,
    1260, 428, 1264, 422, 440, 1302, 1236, 428,
    1264, 424, 438, 1302, 420, 1296, 420, 1298,
    444, 1272, 422, 1298, 1236, 428, 438, 8144,
    1260, 428, 1266, 422, 440, 1302, 1236, 428,
    1266, 422, 440, 1302, 446, 1272, 444, 1274,
    422, 1296, 420, 1296, 1236, 428, 440};

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

void IRSender::sendPowerOn()
{
    Serial.println("SEND RAW");

    irsend.sendRaw(
        powerOnRaw,
        sizeof(powerOnRaw) / sizeof(uint16_t),
        38);

    Serial.println("DONE");
}

void IRSender::sendPowerOff()
{
    irsend.sendSymphony(0xD81, 12);
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