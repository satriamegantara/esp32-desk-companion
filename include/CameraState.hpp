#pragma once

enum class CameraState
{
    Disconnected,

    Connecting,

    Connected,

    Streaming,

    Error,

    Mock
};