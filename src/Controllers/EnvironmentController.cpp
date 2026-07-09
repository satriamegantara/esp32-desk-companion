#include "Controllers/EnvironmentController.hpp"

void EnvironmentController::begin()
{
    sensor.begin();
}

void EnvironmentController::update()
{
    sensor.update();
}