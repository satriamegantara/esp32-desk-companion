#pragma once

#include <esp_camera.h>

class CameraDriver
{
public:
    bool begin();

    bool capture();

private:
    camera_fb_t *fb = nullptr;
};