#include "Screens/DashboardScreen.hpp"
#include "DirtyFlags.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/HeaderWidget.hpp"
#include "Widgets/StatusBar.hpp"
#include "Theme.hpp"
#include "ScreenID.hpp"

#include "Dashboard.hpp"

void DashboardScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    statusBar.draw(lcd);

    footerWidget.draw(lcd);

    widgetManager.clear();

    widgetManager.add(&clockWidget);
    widgetManager.add(&smartHomeWidget);

    updateSelection();

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

    updateSelection();
}

void DashboardScreen::previousWidget()
{
    widgetManager.previous();

    updateSelection();
}

void DashboardScreen::updateSelection()
{
    statusBar.setSelected(false);
    clockWidget.setSelected(false);
    smartHomeWidget.setSelected(false);
    footerWidget.setSelected(false);

    Widget *current = widgetManager.currentWidget();

    if (current)
    {
        current->setSelected(true);
    }

    dirty.header = true;
    dirty.clock = true;
    dirty.smartHome = true;
    dirty.footer = true;
}

uint8_t DashboardScreen::selectedWidget() const
{

    return widgetManager.selectedIndex();
}