#include "Drivers/MJPEGClient.hpp"
#include "Config.hpp"

bool MJPEGClient::connect(
    const char *host,
    uint16_t port)
{
    if (!client.connect(host, port))
    {
        isConnected = false;

        return false;
    }

    isConnected = true;

    sendRequest();

    return true;
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

bool MJPEGClient::sendRequest()
{
    client.print(
        String("GET ") + Config::CameraPath + " HTTP/1.1\r\n");

    client.print(
        "Host: " + String(Config::CameraHost) + "\r\n");

    client.print(
        "Connection: keep-alive\r\n");

    client.print("\r\n");

    return true;
}