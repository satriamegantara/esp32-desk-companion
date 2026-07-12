#include "CameraConfig.hpp"

camera_config_t cameraConfig =
    {
        .pin_pwdn = -1,
        .pin_reset = -1,

        .pin_xclk = 15,

        .pin_sccb_sda = 4,
        .pin_sccb_scl = 5,

        .pin_d7 = 16,
        .pin_d6 = 17,
        .pin_d5 = 18,
        .pin_d4 = 8,
        .pin_d3 = 3,
        .pin_d2 = 46,
        .pin_d1 = 12,
        .pin_d0 = 10,

        .pin_vsync = 6,
        .pin_href = 7,
        .pin_pclk = 13,

        .xclk_freq_hz = 16000000,

        .ledc_timer = LEDC_TIMER_0,
        .ledc_channel = LEDC_CHANNEL_0,

        .pixel_format = PIXFORMAT_JPEG,

        .frame_size = FRAMESIZE_VGA,

        .jpeg_quality = 12,

        .fb_count = 1,

        .fb_location = CAMERA_FB_IN_PSRAM,

        .grab_mode = CAMERA_GRAB_WHEN_EMPTY,

#if CONFIG_CAMERA_CONVERTER_ENABLED
        .conv_mode = CONV_DISABLE,
#endif

        .sccb_i2c_port = 0};