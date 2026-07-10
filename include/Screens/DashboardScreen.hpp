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

private:
    HomePage currentPage =
        HomePage::Dashboard;

    void nextPage();

    void previousPage();

    HomePage page() const;

    StatusBar statusBar;
    ClockWidget clockWidget;
    SmartHomeWidget smartHomeWidget;
    FooterWidget footerWidget;
    CameraWidget cameraWidget;
    SystemWidget systemWidget;

    WidgetManager widgetManager;
};