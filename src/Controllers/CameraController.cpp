#include "Controllers/CameraController.hpp"
#include "AppState.hpp"

void CameraController::begin()
{
    appState.cameraState = CameraState::Mock;
}

void CameraController::update()
{
}

CameraState CameraController::state() const
{
    return cameraState;
}