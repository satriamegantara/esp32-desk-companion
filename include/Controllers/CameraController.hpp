#pragma once

#include "CameraState.hpp"

class CameraController
{
public:
    void begin();

    void update();

    CameraState state() const;

private:
    CameraState cameraState =
        CameraState::Mock;
};