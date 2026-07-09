#pragma once

class CameraController
{
public:
    void begin();

    void update();

    bool connected() const;

private:
    bool cameraConnected = false;
};