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
    count = 0;
}

void WidgetManager::next()
{
    if (count == 0)
        return;

    widgets[selectedIndex]->setSelected(false);

    selectedIndex++;

    if (selectedIndex >= count)
        selectedIndex = 0;

    widgets[selectedIndex]->setSelected(true);
}

void WidgetManager::previous()
{
    if (count == 0)
        return;

    widgets[selectedIndex]->setSelected(false);

    if (selectedIndex == 0)
        selectedIndex = count - 1;
    else
        selectedIndex--;

    widgets[selectedIndex]->setSelected(true);
}

Widget *WidgetManager::currentWidget() const
{
    if (count == 0)
        return nullptr;

    return widgets[selectedIndex];
}