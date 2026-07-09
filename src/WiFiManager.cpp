#include "WiFiManager.hpp"

WiFiManager wifiManager;

const char *SSID = "SATRIA";
const char *PASSWORD = "BahariGhulam03";

void WiFiManager::begin()
{
    WiFi.mode(WIFI_STA);

    WiFi.begin(SSID, PASSWORD);
}

void WiFiManager::update()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        if (!wasConnected)
        {
            wasConnected = true;
        }
    }
    else
    {
        wasConnected = false;
    }
}

bool WiFiManager::connected() const
{
    return WiFi.status() == WL_CONNECTED;
}

String WiFiManager::ip() const
{
    return WiFi.localIP().toString();
}