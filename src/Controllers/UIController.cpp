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

void UIController::update(LGFX &lcd)
{
  handleNavigation();
  handleSelection(lcd);
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

void UIController::handleSelection(LGFX &lcd)
{
  if (!encoder.pressed())
    return;

  if (screenManager.currentScreen() != ScreenID::Dashboard)
    return;

  switch (screenManager.getDashboard().selectedWidget())
  {
  case 0:
    Serial.println("Clock selected");
    break;

  case 1:
    Serial.println("Open SmartHome");
    screenManager.open(ScreenID::SmartHome, lcd);
    break;
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