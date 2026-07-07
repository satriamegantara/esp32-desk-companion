#include "Dashboard.hpp"
#include "Theme.hpp"

#include "Widgets/HeaderWidget.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"

void drawDashboard(LGFX& lcd)
{
    ClockWidget clock;

    lcd.fillScreen(Theme::Background);

    drawHeader(lcd);
    
    clock.draw(lcd);

    drawSmartHomeWidget(lcd);

    drawFooter(lcd);
}