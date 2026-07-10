#pragma once

#include "Page.hpp"

#include "Widgets/StatusBar.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/WidgetManager.hpp"

class DashboardPage : public Page
{
public:
    DashboardPage(
        StatusBar &status,
        FooterWidget &footer,
        WidgetManager &manager);

    void draw(LGFX &lcd) override;

    void update(LGFX &lcd) override;

private:
    StatusBar &statusBar;
    FooterWidget &footerWidget;
    WidgetManager &widgetManager;
};