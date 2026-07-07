#include "InputManager.hpp"

#include <Arduino.h>

void InputManager::begin()
{
    pinMode(0, INPUT_PULLUP);
}

void InputManager::update()
{
    bool now = digitalRead(0);

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