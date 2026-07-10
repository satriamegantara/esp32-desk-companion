#pragma once

struct DirtyFlags
{
    bool header = true;

    bool clock = true;

    bool smartHome = true;

    bool footer = true;

    bool camera = true;

    bool system = true;
};

extern DirtyFlags dirty;