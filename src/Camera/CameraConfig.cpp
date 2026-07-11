#include "Camera/CameraConfig.hpp"

camera_config_t cameraConfig;

static bool initialized = []()
{
    cameraConfig.ledc_channel = LEDC_CHANNEL_0;
    cameraConfig.ledc_timer = LEDC_TIMER_0;

    cameraConfig.pin_d0 = 10;
    cameraConfig.pin_d1 = 12;
    cameraConfig.pin_d2 = 46;
    cameraConfig.pin_d3 = 3;
    cameraConfig.pin_d4 = 8;
    cameraConfig.pin_d5 = 18;
    cameraConfig.pin_d6 = 17;
    cameraConfig.pin_d7 = 16;

    cameraConfig.pin_xclk = 15;

    cameraConfig.pin_pclk = 13;
    cameraConfig.pin_vsync = 6;
    cameraConfig.pin_href = 7;

    cameraConfig.pin_sscb_sda = 4;
    cameraConfig.pin_sscb_scl = 5;

    cameraConfig.pin_pwdn = -1;
    cameraConfig.pin_reset = -1;

    cameraConfig.xclk_freq_hz = 20000000;

    cameraConfig.pixel_format = PIXFORMAT_JPEG;

    cameraConfig.frame_size = FRAMESIZE_QVGA;

    cameraConfig.jpeg_quality = 12;

    cameraConfig.fb_count = 2;

    cameraConfig.grab_mode = CAMERA_GRAB_LATEST;

    cameraConfig.fb_location = CAMERA_FB_IN_PSRAM;

    return true;
}();