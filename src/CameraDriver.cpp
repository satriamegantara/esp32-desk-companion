#include <Arduino.h>

#include "CameraDriver.hpp"
#include "CameraConfig.hpp"

#include <esp_camera.h>

void CameraDriver::printConfig()
{
    Serial.println();

    Serial.println("===== CAMERA CONFIG =====");

    Serial.printf("XCLK  : %d\n", cameraConfig.pin_xclk);
    Serial.printf("SDA   : %d\n", cameraConfig.pin_sccb_sda);
    Serial.printf("SCL   : %d\n", cameraConfig.pin_sccb_scl);

    Serial.printf("D0    : %d\n", cameraConfig.pin_d0);
    Serial.printf("D1    : %d\n", cameraConfig.pin_d1);
    Serial.printf("D2    : %d\n", cameraConfig.pin_d2);
    Serial.printf("D3    : %d\n", cameraConfig.pin_d3);
    Serial.printf("D4    : %d\n", cameraConfig.pin_d4);
    Serial.printf("D5    : %d\n", cameraConfig.pin_d5);
    Serial.printf("D6    : %d\n", cameraConfig.pin_d6);
    Serial.printf("D7    : %d\n", cameraConfig.pin_d7);

    Serial.printf("VSYNC : %d\n", cameraConfig.pin_vsync);
    Serial.printf("HREF  : %d\n", cameraConfig.pin_href);
    Serial.printf("PCLK  : %d\n", cameraConfig.pin_pclk);
}

bool CameraDriver::begin()
{
    Serial.println();
    Serial.println("===== CAMERA DRIVER =====");

    Serial.printf("PSRAM : %s\n",
                  psramFound() ? "FOUND" : "NOT FOUND");

    printConfig();

    Serial.println();
    Serial.println("Initializing camera...");

    esp_err_t err =
        esp_camera_init(&cameraConfig);

    sensor_t *sensor = esp_camera_sensor_get();

    sensor->set_framesize(sensor, FRAMESIZE_VGA);
    sensor->set_quality(sensor, 12);

    delay(100);

    Serial.println();

    Serial.println("===== SENSOR =====");

    Serial.printf(
        "PID : 0x%02X\n",
        sensor->id.PID);

    Serial.printf(
        "VER : 0x%02X\n",
        sensor->id.VER);

    Serial.println();

    Serial.println("Camera Ready");

    return true;
}

bool CameraDriver::capture()
{
    Serial.println();
    Serial.println("Capturing frame...");

    camera_fb_t *fb = esp_camera_fb_get();

    if (fb == nullptr)
    {
        Serial.println("Capture Failed");

        Serial.printf("Heap  : %u\n", ESP.getFreeHeap());
        Serial.printf("PSRAM : %u\n", ESP.getFreePsram());

        return false;
    }

    Serial.println("Capture Success");

    Serial.printf("Width  : %d\n", fb->width);
    Serial.printf("Height : %d\n", fb->height);
    Serial.printf("Length : %u\n", fb->len);

    esp_camera_fb_return(fb);

    return true;
}