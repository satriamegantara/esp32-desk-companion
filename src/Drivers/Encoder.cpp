#include "Drivers/Encoder.hpp"
#include "Pins.hpp"

void Encoder::begin()
{
    pinMode(Pins::EncoderCLK, INPUT_PULLUP);
    pinMode(Pins::EncoderDT, INPUT_PULLUP);
    pinMode(Pins::EncoderSW, INPUT_PULLUP);

    lastCLK = digitalRead(Pins::EncoderCLK);
}

void Encoder::update()
{
    static uint32_t lastPrint = 0;

    leftFlag = false;
    rightFlag = false;
    pressFlag = false;

    int clk = digitalRead(Pins::EncoderCLK);

    if (clk != lastCLK && clk == LOW)
    {
        if (digitalRead(Pins::EncoderDT) != clk)
            rightFlag = true;
        else
            leftFlag = true;
    }

    lastCLK = clk;

    if (digitalRead(Pins::EncoderSW) == LOW)
    {
        static uint32_t lastPress = 0;

        if (millis() - lastPress > 200)
        {
            pressFlag = true;
            lastPress = millis();
        }
    }
}

bool Encoder::left()
{
    return leftFlag;
}

bool Encoder::right()
{
    return rightFlag;
}

bool Encoder::pressed()
{
    return pressFlag;
}