#pragma once

struct DirtyFlags
{
    bool header = true;

    bool clock = true;

    bool smartHome = true;

    bool footer = true;
};

extern DirtyFlags dirty;