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
        dashboardPage.draw(lcd);
    else
        weatherPage.draw(lcd);

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
            dashboardPage.draw(lcd);
        else
            weatherPage.draw(lcd);

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
        updateWeather(lcd);
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
        pageChanged = true;

        while (!widgetManager.isFirst())
            widgetManager.previous();

        updateSelection();
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
        pageChanged = true;

        while (!widgetManager.isLast())
            widgetManager.next();

        updateSelection();
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

void DashboardScreen::updateWeather(LGFX &lcd)
{
    static float lastTemp = -100;
    static float lastHum = -100;
    static String lastDesc = "";

    if (lastTemp != appState.weather.temperature)
    {
        lastTemp = appState.weather.temperature;

        lcd.fillRect(
            110,
            60,
            260,
            60,
            Theme::Background);

        lcd.setFont(&fonts::Font8);

        lcd.drawCentreString(
            String((int)lastTemp) + "°C",
            240,
            70);
    }

    if (lastDesc != appState.weather.description)
    {
        lastDesc = appState.weather.description;

        lcd.fillRect(
            60,
            140,
            360,
            25,
            Theme::Background);

        lcd.setFont(&fonts::Font4);

        lcd.drawCentreString(
            lastDesc,
            240,
            145);
    }

    if (lastHum != appState.weather.humidity)
    {
        lastHum = appState.weather.humidity;

        lcd.fillRect(
            310,
            220,
            130,
            20,
            Theme::Background);

        lcd.setFont(&fonts::Font2);

        lcd.drawRightString(
            String((int)lastHum) + "%",
            440,
            225);
    }
}