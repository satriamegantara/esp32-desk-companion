#include "Screens/DashboardScreen.hpp"
#include "DirtyFlags.hpp"
#include "Widgets/ClockWidget.hpp"
#include "Widgets/SmartHomeWidget.hpp"
#include "Widgets/FooterWidget.hpp"
#include "Widgets/HeaderWidget.hpp"
#include "Widgets/StatusBar.hpp"
#include "Theme.hpp"

#include "Dashboard.hpp"

void DashboardScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    clock.setSelected(selectedWidget == 0);

    smartHome.setSelected(selectedWidget == 1);

    container.add(&statusBar);
    container.add(&clock);
    container.add(&smartHome);
    container.add(&footer);

    dirty.header = false;
    dirty.clock = false;
    dirty.smartHome = false;
    dirty.footer = false;

    container.draw(lcd);
}

void DashboardScreen::update(LGFX &lcd)
{
    container.update(lcd);
}

void DashboardScreen::end()
{
}

// void DashboardScreen::nextWidget()
// {
//     selectedWidget++;

//     if (selectedWidget > 1)
//         selectedWidget = 0;

//     clock.setSelected(selectedWidget == 0);

//     smartHome.setSelected(selectedWidget == 1);

//     dirty.smartHome = true;
//     dirty.clock = true;
// }

// void DashboardScreen::previousWidget()
// {
//     selectedWidget--;

//     if (selectedWidget < 0)
//         selectedWidget = 1;

//     clock.setSelected(selectedWidget == 0);

//     smartHome.setSelected(selectedWidget == 1);

//     dirty.smartHome = true;
//     dirty.clock = true;
// }

// UIAction DashboardScreen::activateWidget()
// {
//     switch (selectedWidget)
//     {
//     case 0:
//         return UIAction::None;

//     case 1:
//         return UIAction::ToggleLamp;
//     }

//     return UIAction::None;
// }