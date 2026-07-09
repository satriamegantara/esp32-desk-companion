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

    widgetManager.clear();

    widgetManager.add(&statusBar);
    widgetManager.add(&clockWidget);
    widgetManager.add(&smartHomeWidget);
    widgetManager.add(&footerWidget);

    if (widgetManager.currentWidget())
        widgetManager.currentWidget()->setSelected(true);

    widgetManager.draw(lcd);

    dirty.header = false;
    dirty.clock = false;
    dirty.smartHome = false;
    dirty.footer = false;
}

void DashboardScreen::update(LGFX &lcd)
{
    widgetManager.update(lcd);
}

void DashboardScreen::end()
{
}

void DashboardScreen::nextWidget()
{
    widgetManager.next();

    dirty.smartHome = true;

    dirty.clock = true;
}

void DashboardScreen::previousWidget()
{
    widgetManager.previous();

    dirty.smartHome = true;

    dirty.clock = true;
}