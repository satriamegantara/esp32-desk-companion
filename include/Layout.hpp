#pragma once

struct Rect
{
    int x;
    int y;
    int w;
    int h;
};

namespace Layout
{
    constexpr Rect Header     = {  0,   0, 480,  40 };

    constexpr Rect ClockCard  = { 10,  55, 150, 190 };

    constexpr Rect SmartCard  = {170,  55, 300, 190 };

    constexpr Rect Footer     = {  0, 285, 480,  35 };
}