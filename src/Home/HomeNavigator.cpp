#include "Home/HomeNavigator.hpp"

HomePage HomeNavigator::currentPage() const
{
    return page;
}

void HomeNavigator::nextPage()
{
    if (page == HomePage::Dashboard)
        page = HomePage::Weather;
    else
        page = HomePage::Dashboard;
}

void HomeNavigator::previousPage()
{
    nextPage();
}