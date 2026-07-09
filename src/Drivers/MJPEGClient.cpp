#include "Drivers/MJPEGClient.hpp"

bool MJPEGClient::connect(const char *url)
{
    (void)url;

    isConnected = false;

    return isConnected;
}

void MJPEGClient::disconnect()
{
    isConnected = false;
}

bool MJPEGClient::connected() const
{
    return isConnected;
}

bool MJPEGClient::readFrame()
{
    return false;
}