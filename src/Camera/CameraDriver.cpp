#include "Camera/CameraDriver.hpp"

#include "Camera/CameraConfig.hpp"

#include <Arduino.h>
#include <esp_camera.h>

bool CameraDriver::begin()
{
    Serial.println();

    Serial.println("===== CAMERA =====");

    Serial.printf("PSRAM : %s\n",
                  psramFound() ? "FOUND" : "NOT FOUND");

    esp_err_t err =
        esp_camera_init(&cameraConfig);

    if (err != ESP_OK)
    {
        Serial.printf(
            "Camera Init Failed : 0x%x\n",
            err);

        return false;
    }

    Serial.println("Camera Ready");

    return true;
}

bool CameraDriver::capture()
{
    fb = esp_camera_fb_get();

    if (!fb)
    {
        Serial.println("Capture Failed");

        return false;
    }

    Serial.println("===== FRAME =====");

    Serial.printf(
        "Width  : %d\n",
        fb->width);

    Serial.printf(
        "Height : %d\n",
        fb->height);

    Serial.printf(
        "Length : %d bytes\n",
        fb->len);

    esp_camera_fb_return(fb);

    fb = nullptr;

    return true;
}