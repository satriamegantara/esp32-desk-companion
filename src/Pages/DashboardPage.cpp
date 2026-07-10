#include "Pages/DashboardPage.hpp"

#include "Theme.hpp"

DashboardPage::DashboardPage(
    StatusBar &status,
    FooterWidget &footer,
    WidgetManager &manager)
    : statusBar(status),
      footerWidget(footer),
      widgetManager(manager)
{
}

void DashboardPage::draw(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    statusBar.draw(lcd);

    footerWidget.draw(lcd);

    widgetManager.draw(lcd);
}

void DashboardPage::update(LGFX &lcd)
{
    statusBar.update(lcd);

    widgetManager.update(lcd);

    footerWidget.update(lcd);
}