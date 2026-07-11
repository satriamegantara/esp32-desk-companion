#include "Screens/DashboardScreen.hpp"
#include "DirtyFlags.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/HeaderWidget.hpp"
#include "Widgets/StatusBar.hpp"
#include "Theme.hpp"
#include "ScreenID.hpp"
#include "AppState.hpp"

#include "Dashboard.hpp"

DashboardScreen::DashboardScreen()
    : dashboardPage(
          statusBar,
          footerWidget,
          widgetManager)
{
}

void DashboardScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    widgetManager.clear();

    widgetManager.add(&clockWidget);
    widgetManager.add(&smartHomeWidget);
    widgetManager.add(&cameraWidget);
    widgetManager.add(&systemWidget);

    updateSelection();

    if (currentPage == HomePage::Dashboard)
    {
        dashboardPage.draw(lcd);
    }
    else
    {
        weatherPage.draw(lcd);
    }

    dirty.header = false;
    dirty.clock = false;
    dirty.smartHome = false;
    dirty.footer = false;
    dirty.camera = false;
    dirty.system = false;
}

void DashboardScreen::update(LGFX &lcd)
{
    if (pageChanged)
    {
        pageChanged = false;

        if (currentPage == HomePage::Dashboard)
        {
            dashboardPage.draw(lcd);
        }
        else
        {
            weatherPage.draw(lcd);
        }

        return;
    }

    if (currentPage == HomePage::Dashboard)
    {
        statusBar.update(lcd);

        widgetManager.update(lcd);

        footerWidget.update(lcd);
    }
    else
    {
        weatherPage.update(lcd);
    }
}

void DashboardScreen::end()
{
}

void DashboardScreen::nextWidget()
{
    if (currentPage == HomePage::Weather)
    {
        currentPage = HomePage::Dashboard;

        while (!widgetManager.isFirst())
            widgetManager.previous();

        updateSelection();

        pageChanged = true;

        return;
    }

    if (widgetManager.isLast())
    {
        currentPage = HomePage::Weather;
        pageChanged = true;
        return;
    }

    widgetManager.next();
    updateSelection();
}

void DashboardScreen::previousWidget()
{
    if (currentPage == HomePage::Weather)
    {
        currentPage = HomePage::Dashboard;

        while (!widgetManager.isLast())
            widgetManager.next();

        updateSelection();

        pageChanged = true;

        return;
    }

    // Clock -> Weather
    if (widgetManager.isFirst())
    {
        currentPage = HomePage::Weather;
        pageChanged = true;
        return;
    }

    widgetManager.previous();

    updateSelection();
}

void DashboardScreen::updateSelection()
{
    clockWidget.onDeselected();

    smartHomeWidget.onDeselected();

    cameraWidget.onDeselected();

    systemWidget.onDeselected();

    Widget *current =
        widgetManager.currentWidget();

    if (current)
        current->onSelected();

    dirty.clock = true;
    dirty.smartHome = true;
    dirty.camera = true;
    dirty.system = true;
    dirty.footer = true;
}

uint8_t DashboardScreen::selectedWidget() const
{
    if (currentPage == HomePage::Weather)
        return 4;

    return widgetManager.selectedIndex();
}

ScreenID DashboardScreen::selectedScreen() const
{
    return widgetManager.currentTarget();
}

void DashboardScreen::nextPage()
{
    if (currentPage == HomePage::Dashboard)
        currentPage = HomePage::Weather;
    else
        currentPage = HomePage::Dashboard;
}

void DashboardScreen::previousPage()
{
    nextPage();
}

HomePage DashboardScreen::page() const
{
    return currentPage;
}

bool DashboardScreen::isDashboardPage() const
{
    return currentPage == HomePage::Dashboard;
}

bool DashboardScreen::isWeatherPage() const
{
    return currentPage == HomePage::Weather;
}