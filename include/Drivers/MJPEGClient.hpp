#pragma once

#include <WiFiClient.h>

class MJPEGClient
{
public:
    bool connect(const char *host, uint16_t port);

    void disconnect();

    bool connected() const;

    bool readFrame();

private:
    bool sendRequest();
    bool isConnected = false;
    WiFiClient client;
};