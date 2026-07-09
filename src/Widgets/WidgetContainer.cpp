#include "Widgets/WidgetContainer.hpp"

void WidgetContainer::add(Widget *widget)
{
    if (count < MAX_WIDGETS)
    {
        widgets[count++] = widget;
    }
}

void WidgetContainer::draw(LGFX &lcd)
{
    for (uint8_t i = 0; i < count; i++)
    {
        if (widgets[i]->isVisible())
            widgets[i]->draw(lcd);
    }
}

void WidgetContainer::update(LGFX &lcd)
{
    for (uint8_t i = 0; i < count; i++)
    {
        if (widgets[i]->isVisible())
            widgets[i]->update(lcd);
    }
}