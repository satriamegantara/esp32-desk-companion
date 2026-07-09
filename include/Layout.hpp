#pragma once

#include "Rect.hpp"

namespace Layout
{
    extern Rect Header;
    extern Rect ClockCard;
    extern Rect SmartCard;
    extern Rect Footer;

    constexpr int SmartArrowX = 185;
    constexpr int SmartTextX = 205;
    constexpr int SmartStateX = 430;

    constexpr int LampY = 115;
    constexpr int FanY = 155;

    constexpr int SpeedY = 195;
    constexpr int SwingY = 235;
    constexpr int MagicWindY = 275;
    constexpr int TimerY = 315;
}