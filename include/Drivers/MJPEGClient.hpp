#pragma once

class MJPEGClient
{
public:
    bool connect(const char *url);

    void disconnect();

    bool connected() const;

    bool readFrame();

private:
    bool isConnected = false;
};