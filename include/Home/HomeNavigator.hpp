#pragma once

#include "Screens/HomePage.hpp"

class HomeNavigator
{
public:
    HomePage currentPage() const;

    void nextPage();

    void previousPage();

private:
    HomePage page =
        HomePage::Dashboard;
};