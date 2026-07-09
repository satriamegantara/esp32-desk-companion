#include "Widgets/ClockWidget.hpp"
#include "Theme.hpp"
#include "AppState.hpp"
#include "DirtyFlags.hpp"
#include "LayoutClock.hpp"

#include "Layout.hpp"

void ClockWidget::draw(LGFX &lcd)
{
    lcd.fillRoundRect(
        Layout::ClockCard.x,
        Layout::ClockCard.y,
        Layout::ClockCard.w,
        Layout::ClockCard.h,
        10,
        Theme::Background);

    lcd.drawRoundRect(
        Layout::ClockCard.x,
        Layout::ClockCard.y,
        Layout::ClockCard.w,
        Layout::ClockCard.h,
        10,
        Theme::Primary);

    lcd.drawCentreString(
        "CLOCK",
        Layout::ClockCard.x + Layout::ClockCard.w / 2,
        Layout::ClockCard.y + ClockLayout::TitleYOffset);

    lcd.setTextColor(Theme::White, Theme::Background);

    lcd.setFont(&fonts::Font2);

    String hm = appState.time.substring(0, 5);
    String sec = appState.time.substring(6, 8);

    int x = Layout::ClockCard.x;
    int y = Layout::ClockCard.y;

    lcd.setFont(&fonts::Font6);

    int hmWidth = lcd.textWidth(hm);

    int startX =
        Layout::ClockCard.x +
        (Layout::ClockCard.w - hmWidth - 15) / 2;

    lcd.drawString(
        hm,
        startX,
        y + ClockLayout::TimeYOffset);

    lcd.setFont(&fonts::Font2);

    lcd.drawString(
        sec,
        startX + hmWidth + ClockLayout::SecondGap,
        y + ClockLayout::TimeYOffset + ClockLayout::SecondYOffset);

    lcd.setFont(&fonts::Font2);
    lcd.drawCentreString(
        appState.day.c_str(),
        Layout::ClockCard.x + Layout::ClockCard.w / 2,
        Layout::ClockCard.y + 140);
}

void ClockWidget::update(LGFX &lcd)
{
    uint16_t border =
        selected ? Theme::Accent
                 : Theme::Primary;

    lcd.drawRoundRect(
        Layout::ClockCard.x,
        Layout::ClockCard.y,
        Layout::ClockCard.w,
        Layout::ClockCard.h,
        10,
        border);

    if (!dirty.clock)
        return;

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.setFont(&fonts::Font6);

    if (lastTime == appState.time &&
        lastDay == appState.day)
        return;

    lcd.fillRect(
        Layout::ClockCard.x +
            ClockLayout::RefreshMarginX,

        Layout::ClockCard.y +
            ClockLayout::RefreshY,

        Layout::ClockCard.w -
            ClockLayout::RefreshMarginX * 2,

        ClockLayout::RefreshHeight,

        Theme::Background);

    lcd.fillRect(
        Layout::ClockCard.x + 10,
        Layout::ClockCard.y + 130,
        Layout::ClockCard.w - 20,
        25,
        Theme::Background);

    lcd.setFont(&fonts::Font6);

    String sec = appState.time.substring(6, 8);

    String hm = appState.time.substring(0, 5);

    lcd.setFont(&fonts::Font6);

    int hmWidth = lcd.textWidth(hm);

    int startX =
        Layout::ClockCard.x +
        (Layout::ClockCard.w - hmWidth - 15) / 2;

    lcd.drawString(
        hm,
        startX,
        Layout::ClockCard.y + ClockLayout::TimeYOffset);

    lcd.setFont(&fonts::Font2);

    lcd.drawString(
        sec,
        startX + hmWidth + ClockLayout::SecondGap,
        Layout::ClockCard.y +
            ClockLayout::TimeYOffset +
            ClockLayout::SecondYOffset);

    lcd.setFont(&fonts::Font2);

    lcd.drawCentreString(
        appState.day.c_str(),
        Layout::ClockCard.x + Layout::ClockCard.w / 2,
        Layout::ClockCard.y +
            ClockLayout::DayYOffset);

    lastTime = appState.time;
    lastDay = appState.day;

    dirty.clock = false;
}