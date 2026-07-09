#pragma once

#include "Screen.hpp"

#include "Widgets/StatusBar.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/WidgetManager.hpp"

class DashboardScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override;

    void nextWidget() override;
    void previousWidget() override;
    void updateSelection();

    uint8_t selectedWidget() const;

private:
    StatusBar statusBar;
    ClockWidget clockWidget;
    SmartHomeWidget smartHomeWidget;
    FooterWidget footerWidget;

    WidgetManager widgetManager;
};