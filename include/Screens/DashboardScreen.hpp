#pragma once

#include "Screen.hpp"

#include "Widgets/StatusBar.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"

class DashboardScreen : public Screen
{
public:
    void begin(LGFX &lcd) override;
    void update(LGFX &lcd) override;
    void end() override;

private:
    int selectedWidget = 0;

    StatusBar statusBar;

    ClockWidget clockWidget;

    SmartHomeWidget smartHomeWidget;

    FooterWidget footerWidget;
};