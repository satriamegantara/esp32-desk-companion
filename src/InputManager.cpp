#include "InputManager.hpp"
#include "Pins.hpp"
#include <Arduino.h>

void InputManager::begin()
{
    pinMode(Pins::BootButton, INPUT_PULLUP);
}

void InputManager::update()
{
    bool now = digitalRead(Pins::BootButton);

    bootPressed = (lastBoot == HIGH && now == LOW);

    lastBoot = now;
}

bool InputManager::press()
{
    return bootPressed;
}

bool InputManager::up()
{
    return false;
}

bool InputManager::down()
{
    return false;
}