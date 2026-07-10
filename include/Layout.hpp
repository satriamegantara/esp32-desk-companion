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

    // Footer
    constexpr int FooterCol1 = 60;
    constexpr int FooterCol2 = 180;
    constexpr int FooterCol3 = 300;
    constexpr int FooterCol4 = 420;

    constexpr int FooterTextY = 296;

    constexpr int Margin = 20;
    constexpr int CardGap = 20;
    constexpr int CardRadius = 12;
    constexpr int CardTitleY = 14;
    constexpr int CardBottomHeight = 55;
    constexpr int TitlePadding = 15;
    constexpr int RowHeight = 35;

    // Smart Home Screen
    constexpr int SH_TitleY = 20;
    constexpr int SH_StartY = 70;
    constexpr int SH_RowHeight = 45;
    constexpr int SH_TextX = 60;
    constexpr int SH_StateX = 420;
    constexpr int SH_SeparatorY = 255;
    constexpr int SH_BackY = 425;
    constexpr int SH_BackX = 40;
    constexpr int SH_HintY = 268;

    extern Rect CameraCard;

    extern const int CameraTitleY;

    extern const int CameraStatusY;

    extern const int CameraFPSY;

    extern const int CameraSizeY;

    extern const int CameraInfoY;

    extern Rect SystemCard;

    // System Screen
    // Title
    constexpr int SYS_TitleY = 20;

    // Section
    constexpr int SYS_HardwareY = 55; // gap 48 ke 55
    constexpr int SYS_NetworkY = 167; // 44 //gap 27
    constexpr int SYS_RuntimeY = 238; // 98

    // Row
    constexpr int SYS_CPUY = 77;
    constexpr int SYS_HeapY = 96;
    constexpr int SYS_PSRAMY = 118;
    constexpr int SYS_FlashY = 140;

    constexpr int SYS_WiFiY = 189;
    constexpr int SYS_IPY = 211;

    constexpr int SYS_UptimeY = 260;

    // Column
    constexpr int SYS_LabelX = 35;
    constexpr int SYS_ValueRightX = 440;

    // Footer
    constexpr int SYS_LineY = 285;

    constexpr int SYS_BackY = 293;

    constexpr int SYS_BackX = 35;
}