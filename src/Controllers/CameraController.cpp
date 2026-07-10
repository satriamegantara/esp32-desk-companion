#include "Controllers/CameraController.hpp"

void CameraController::begin()
{
    online = false;
}

void CameraController::update()
{
}

bool CameraController::connected() const
{
    return online;
}