#include "UI/UIRenderer.hpp"

#include "Theme.hpp"
#include "Layout.hpp"

namespace UIRenderer
{

    void drawCard(
        LGFX &lcd,
        const Rect &rect,
        const char *title)
    {
        lcd.fillRoundRect(
            rect.x,
            rect.y,
            rect.w,
            rect.h,
            Layout::CardRadius,
            Theme::Background);

        lcd.drawRoundRect(
            rect.x,
            rect.y,
            rect.w,
            rect.h,
            Layout::CardRadius,
            Theme::Primary);

        lcd.setFont(&fonts::Font2);

        lcd.setTextColor(
            TFT_DARKGREY,
            Theme::Background);

        lcd.drawString(
            title,
            rect.x + 14,
            rect.y + 8);

        lcd.drawFastHLine(
            rect.x + 14,
            rect.y + 22,
            120,
            TFT_DARKGREY);
    }

}