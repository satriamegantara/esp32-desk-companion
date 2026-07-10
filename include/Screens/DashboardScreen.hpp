#pragma once

#include "Screen.hpp"
#include "Screens/HomePage.hpp"

#include "Widgets/StatusBar.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/WidgetManager.hpp"
#include "Widgets/CameraWidget.hpp"
#include "Widgets/SystemWidget.hpp"
#include "Pages/DashboardPage.hpp"
#include "Pages/WeatherPage.hpp"
#include "Home/HomeNavigator.hpp"

class DashboardScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override;

    void nextWidget() override;
    void previousWidget() override;
    void updateSelection();

    ScreenID selectedScreen() const;

    uint8_t selectedWidget() const;

    DashboardScreen();

private:
    HomePage currentPage =
        HomePage::Dashboard;
    bool pageChanged = false;

    void nextPage();
    void previousPage();
    HomePage page() const;
    bool isDashboardPage() const;
    bool isWeatherPage() const;

    void updateWeather(LGFX &lcd);

    StatusBar statusBar;
    ClockWidget clockWidget;
    SmartHomeWidget smartHomeWidget;
    FooterWidget footerWidget;
    CameraWidget cameraWidget;
    SystemWidget systemWidget;

    WidgetManager widgetManager;

    DashboardPage dashboardPage;
    WeatherPage weatherPage;
};