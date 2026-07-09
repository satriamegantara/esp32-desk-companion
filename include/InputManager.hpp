#pragma once

class InputManager
{
public:
    void begin();

    void update();

    bool up();

    bool down();

    bool press();

    bool back();

private:
    bool bootPressed = false;

    bool lastBoot = true;
};