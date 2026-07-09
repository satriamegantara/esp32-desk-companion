#pragma once

class TimeManager
{
public:
    void begin();
    void update();

private:
    bool initialized = false;
};

extern TimeManager timeManager;