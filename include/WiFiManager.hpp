#pragma once

#include <WiFi.h>

class WiFiManager
{
public:
    void begin();

    void update();

    bool connected() const;

    String ip() const;

private:
    bool wasConnected = false;
};

extern WiFiManager wifiManager;