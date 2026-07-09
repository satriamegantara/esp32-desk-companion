#pragma once

#include "Drivers/MJPEGClient.hpp"

class CameraController
{
public:
    void begin();

    void update();

    bool connected() const;

private:
    bool cameraConnected = false;
    MJPEGClient client;
};