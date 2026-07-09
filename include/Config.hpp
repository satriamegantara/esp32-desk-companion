#pragma once

#include <cstdint>

namespace Config
{
    constexpr int SCREEN_WIDTH = 480;
    constexpr int SCREEN_HEIGHT = 320;

    constexpr int HEADER_HEIGHT = 40;

    constexpr int FOOTER_HEIGHT = 35;

    constexpr int FPS = 60;

    constexpr const char *CameraHost = "deskmatecam.local";
    constexpr uint16_t CameraPort = 81;
    constexpr const char *CameraPath = "/stream";
}