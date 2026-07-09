#include "Controllers/UIController.hpp"
#include "AppState.hpp"
#include "DirtyFlags.hpp"
#include "Pins.hpp"

UIController::UIController(
    Encoder &encoder,
    SmartHomeController &smartHome)
    : encoder(encoder),
      smartHome(smartHome)
{
}

void UIController::begin(LGFX &lcd)
{
  screenManager.begin(lcd);
}

void UIController::update()
{
  handleNavigation();
  handleSelection();
  handleBootButton();
}

void UIController::render(LGFX &lcd)
{
  screenManager.update(lcd);
}

void UIController::handleNavigation()
{
  if (encoder.right())
  {
    screenManager.nextWidget();
  }
}

void UIController::handleSelection()
{
  if (encoder.pressed())
  {
    activateFocusedItem();
  }
}
void UIController::handleBootButton()
{
  static bool last = HIGH;

  bool now = digitalRead(Pins::BootButton);

  if (last == HIGH && now == LOW)
  {
    if (appState.focus == FocusItem::Lamp)
    {
      appState.lamp = !appState.lamp;
    }
    else
    {
      appState.fan = !appState.fan;
    }

    dirty.smartHome = true;
  }

  last = now;
}

void UIController::focusNext()
{
  if (appState.focus == FocusItem::Lamp)
    appState.focus = FocusItem::Fan;
  else
    appState.focus = FocusItem::Lamp;

  dirty.smartHome = true;
}

void UIController::activateFocusedItem()
{
  if (appState.focus == FocusItem::Lamp)
    smartHome.toggleLamp();
  else
    smartHome.toggleFan();
}