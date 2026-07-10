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

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    statusBar.draw(lcd);

    footerWidget.draw(lcd);

    widgetManager.clear();

    widgetManager.add(&clockWidget);
    widgetManager.add(&smartHomeWidget);
    widgetManager.add(&cameraWidget);
    widgetManager.add(&systemWidget);

    clockWidget.onDeselected();
    smartHomeWidget.onDeselected();
    cameraWidget.onDeselected();
    systemWidget.onDeselected();

    updateSelection();

    widgetManager.draw(lcd);

    dirty.header = false;
    dirty.clock = false;
    dirty.smartHome = false;
    dirty.footer = false;
    dirty.camera = false;
    dirty.system = false;
}

void DashboardScreen::update(LGFX &lcd)
{
    statusBar.update(lcd);
    widgetManager.update(lcd);
    footerWidget.update(lcd);
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
    Widget *current =
        widgetManager.currentWidget();

    if (current)
        current->onSelected();

    dirty.clock = true;
    dirty.smartHome = true;
    dirty.footer = true;
    dirty.camera = true;
    dirty.system = true;
}

uint8_t DashboardScreen::selectedWidget() const
{

    return widgetManager.selectedIndex();
}

ScreenID DashboardScreen::selectedScreen() const
{
    return widgetManager.currentTarget();
}