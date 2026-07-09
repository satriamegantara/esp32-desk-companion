#pragma once

namespace Pins
{
    // Boot button
    constexpr int BootButton = 0;

    // Encoder
    constexpr int EncoderCLK = 4;
    constexpr int EncoderDT = 5;
    constexpr int EncoderSW = 6;

    // IR
    constexpr int IRLed = 7;
    constexpr int IRReceiver = 15;

    // I2C
    constexpr int SDA = 17;
    constexpr int SCL = 18;

    // Relay
    constexpr int RelayLamp = 16;
    constexpr int RelayFan = 38;
}