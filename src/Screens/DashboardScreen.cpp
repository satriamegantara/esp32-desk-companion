#include "Screens/DashboardScreen.hpp"
#include "DirtyFlags.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/HeaderWidget.hpp"

#include "Dashboard.hpp"

void DashboardScreen::begin(LGFX& lcd)
{
    drawDashboard(lcd);
}

void DashboardScreen::update(LGFX& lcd)
{
    // nanti isi dirty flag
}

void DashboardScreen::end()
{
}