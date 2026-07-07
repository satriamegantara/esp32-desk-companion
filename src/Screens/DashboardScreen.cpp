#include "Screens/DashboardScreen.hpp"
#include "DirtyFlags.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/HeaderWidget.hpp"
#include "Widgets/StatusBar.hpp"
#include "Theme.hpp"

#include "Dashboard.hpp"

void DashboardScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    statusBar.draw(lcd);
    clockWidget.draw(lcd);
    smartHomeWidget.draw(lcd);
    footerWidget.draw(lcd);

    dirty.header = false;
    dirty.clock = false;
    dirty.smartHome = false;
    dirty.footer = false;
}

void DashboardScreen::update(LGFX &lcd)
{
    if (dirty.header)
    {
        statusBar.draw(lcd);
        dirty.header = false;
    }

    if (dirty.clock)
    {
        clockWidget.draw(lcd);
        dirty.clock = false;
    }

    if (dirty.smartHome)
    {
        smartHomeWidget.draw(lcd);
        dirty.smartHome = false;
    }

    if (dirty.footer)
    {
        footerWidget.draw(lcd);
        dirty.footer = false;
    }
}

void DashboardScreen::end()
{
}