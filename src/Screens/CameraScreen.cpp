#include "Screens/CameraScreen.hpp"

#include "Theme.hpp"
#include "Layout.hpp"

void CameraScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    drawHeader(lcd);

    drawPreview(lcd);

    drawStatus(lcd);

    drawInfo(lcd);

    needRedraw = false;
}

void CameraScreen::update(LGFX &lcd)
{
    if (!needRedraw)
        return;

    drawPreview(lcd);

    drawStatus(lcd);

    drawInfo(lcd);

    needRedraw = false;
}

void CameraScreen::end()
{
}

void CameraScreen::drawHeader(LGFX &lcd)
{
    lcd.setFont(&fonts::Font4);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawCentreString(
        "CAMERA",
        240,
        Layout::CameraTitleY);
}

void CameraScreen::drawPreview(LGFX &lcd)
{
    lcd.fillRoundRect(
        Layout::CameraCard.x,
        Layout::CameraCard.y,
        Layout::CameraCard.w,
        Layout::CameraCard.h,
        12,
        TFT_BLACK);

    lcd.drawRoundRect(
        Layout::CameraCard.x,
        Layout::CameraCard.y,
        Layout::CameraCard.w,
        Layout::CameraCard.h,
        12,
        Theme::Primary);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        TFT_DARKGREY,
        TFT_BLACK);

    lcd.drawCentreString(
        "CAMERA OFFLINE",
        240,
        135);
}

void CameraScreen::drawStatus(LGFX &lcd)
{
    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::Error,
        Theme::Background);

    lcd.drawCentreString(
        "● OFFLINE",
        240,
        Layout::CameraStatusY);
}

void CameraScreen::drawInfo(LGFX &lcd)
{
    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawCentreString(
        "Waiting for ESP32-S3 CAM",
        240,
        Layout::CameraInfoY);
}