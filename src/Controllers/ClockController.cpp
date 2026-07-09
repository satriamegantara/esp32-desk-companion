#include "Controllers/ClockController.hpp"

void ClockController::begin()
{
    timeManager.begin();
}

void ClockController::update()
{
    timeManager.update();
}