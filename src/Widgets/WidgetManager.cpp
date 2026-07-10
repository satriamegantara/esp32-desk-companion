#include "Widgets/WidgetManager.hpp"

void WidgetManager::add(Widget *widget)
{
    if (count < MAX_WIDGETS)
    {
        widgets[count++] = widget;
    }
}

void WidgetManager::draw(LGFX &lcd)
{
    for (uint8_t i = 0; i < count; i++)
    {
        if (widgets[i]->isVisible())
            widgets[i]->draw(lcd);
    }
}

void WidgetManager::update(LGFX &lcd)
{
    for (uint8_t i = 0; i < count; i++)
    {
        if (widgets[i]->isVisible())
            widgets[i]->update(lcd);
    }
}

void WidgetManager::clear()
{
    for (uint8_t i = 0; i < count; i++)
    {
        widgets[i]->onDeselected();
    }

    count = 0;
    currentIndex = 0;
}

void WidgetManager::next()
{
    if (count == 0)
        return;

    widgets[currentIndex]->onDeselected();

    currentIndex++;

    if (currentIndex >= count)
        currentIndex = 0;

    widgets[currentIndex]->onSelected();
}

void WidgetManager::previous()
{
    if (count == 0)
        return;

    widgets[currentIndex]->onDeselected();

    if (currentIndex == 0)
        currentIndex = count - 1;
    else
        currentIndex--;

    widgets[currentIndex]->onSelected();
}

Widget *WidgetManager::currentWidget() const
{
    if (count == 0)
        return nullptr;

    return widgets[currentIndex];
}

uint8_t WidgetManager::selectedIndex() const
{
    return currentIndex;
}

ScreenID WidgetManager::currentTarget() const
{
    Widget *current = currentWidget();

    if (!current)
        return ScreenID::Dashboard;

    return current->targetScreen();
}