#include "Screens/SystemScreen.hpp"

void SystemScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(TFT_NAVY);

    lcd.setTextColor(TFT_WHITE);

    lcd.setFont(&fonts::Font4);

    lcd.drawCentreString("SYSTEM", 240, 20);

    lcd.setFont(&fonts::Font2);

    lcd.drawString("CPU :", 30, 70);

    lcd.drawString("Heap :", 30, 100);

    lcd.drawString("PSRAM :", 30, 130);

    lcd.drawString("Flash :", 30, 160);

    lcd.drawString("Uptime :", 30, 190);
}

void SystemScreen::update(LGFX &lcd)
{
    static uint32_t last = 0;

    if (millis() - last < 1000)
        return;

    last = millis();

    lcd.fillRect(150, 70, 200, 150, TFT_NAVY);

    lcd.drawString(String(getCpuFrequencyMhz()) + " MHz", 150, 70);

    lcd.drawString(String(ESP.getFreeHeap() / 1024) + " KB", 150, 100);

    lcd.drawString(String(ESP.getPsramSize() / 1024 / 1024) + " MB", 150, 130);

    lcd.drawString(String(ESP.getFlashChipSize() / 1024 / 1024) + " MB", 150, 160);

    lcd.drawString(String(millis() / 1000) + " sec", 150, 190);
}

void SystemScreen::end()
{
}

void SystemScreen::nextWidget()
{
}

void SystemScreen::previousWidget()
{
}