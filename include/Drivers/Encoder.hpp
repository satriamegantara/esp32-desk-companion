#pragma once

#include <Arduino.h>

class Encoder
{
public:
    void begin();
    void update();

    bool left();
    bool right();
    bool pressed();

private:
    int lastCLK = HIGH;

    bool leftFlag = false;
    bool rightFlag = false;
    bool pressFlag = false;
};