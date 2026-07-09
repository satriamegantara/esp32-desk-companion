#pragma once

#include "Rect.hpp"

namespace Layout
{

    constexpr int SmartArrowX = 185;

    //=========================
    // Header
    //=========================
    extern Rect Header;

    //=========================
    // Dashboard Cards
    //=========================
    extern Rect ClockCard;
    extern Rect SmartCard;
    extern Rect Footer;

    //=========================
    // Global Padding
    //=========================
    constexpr int CardPadding = 16;

    //=========================
    // Smart Home
    //=========================

    constexpr int SmartTextX = 200;
    constexpr int SmartStateX = 425;

    constexpr int LampY = 90;
    constexpr int FanY = 125;
    constexpr int SpeedY = 160;
    constexpr int SwingY = 195;

    // Jangan dipakai di Dashboard lagi
    constexpr int MagicWindY = 235;
    constexpr int TimerY = 270;

    //=========================
    // Camera
    //=========================

    constexpr Rect CameraCard =
        {
            20,
            40,
            440,
            240};

    constexpr int CameraTitleY = 15;

    constexpr int CameraStatusY = 255;

    constexpr int CameraFPSY = 280;

    constexpr int CameraSizeY = 305;

    // Footer
    constexpr int FooterCol1 = 60;
    constexpr int FooterCol2 = 180;
    constexpr int FooterCol3 = 300;
    constexpr int FooterCol4 = 420;

    constexpr int FooterTextY = 296;

    constexpr int Margin = 20;
    constexpr int CardGap = 20;
    constexpr int CardRadius = 10;
    constexpr int TitlePadding = 15;
    constexpr int RowHeight = 35;

    // Smart Home Screen
    constexpr int SH_TitleY = 20;
    constexpr int SH_StartY = 70;
    constexpr int SH_RowHeight = 45;
    constexpr int SH_TextX = 60;
    constexpr int SH_StateX = 420;
}