#include "Widgets/CameraWidget.hpp"
#include "Theme.hpp"
#include "Layout.hpp"
#include "AppState.hpp"

void CameraWidget::draw(LGFX &lcd)
{
    lcd.fillRoundRect(
        Layout::CameraCard.x,
        Layout::CameraCard.y,
        Layout::CameraCard.w,
        Layout::CameraCard.h,
        10,
        Theme::Background);

    lcd.drawRoundRect(
        Layout::CameraCard.x,
        Layout::CameraCard.y,
        Layout::CameraCard.w,
        Layout::CameraCard.h,
        10,
        Theme::Primary);

    lcd.drawCentreString(
        "CAMERA",
        Layout::CameraCard.x + Layout::CameraCard.w / 2,
        Layout::CameraCard.y + Layout::CameraTitleY);

    lcd.setFont(&fonts::Font4);

    lcd.drawCentreString(
        "NO SIGNAL",
        Layout::CameraCard.x + Layout::CameraCard.w / 2,
        Layout::CameraCard.y + 110);

    String status;

    switch (appState.cameraState)
    {
    case CameraState::Mock:
        status = "MOCK";
        break;

    case CameraState::Connecting:
        status = "CONNECTING";
        break;

    case CameraState::Connected:
        status = "CONNECTED";
        break;

    case CameraState::Streaming:
        status = "STREAMING";
        break;

    case CameraState::Error:
        status = "ERROR";
        break;

    default:
        status = "UNKNOWN";
        break;
    }

    lcd.drawString(
        "Status : " + status,
        Layout::CameraCard.x + 20,
        Layout::CameraStatusY);

    lcd.drawString(
        "FPS : --",
        Layout::CameraCard.x + 20,
        Layout::CameraFPSY);

    lcd.drawString(
        "Resolution : --",
        Layout::CameraCard.x + 20,
        Layout::CameraSizeY);
}

void CameraWidget::update(LGFX &)
{
}