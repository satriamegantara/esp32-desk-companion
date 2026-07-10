#include "Screens/SystemScreen.hpp"
#include "Theme.hpp"
#include "Layout.hpp"
#include "AppState.hpp"

void SystemScreen::begin(LGFX &lcd)
{
    lcd.fillScreen(Theme::Background);

    //=========================
    // Title
    //=========================
    lcd.setFont(&fonts::Font4);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawCentreString(
        "System",
        240,
        Layout::SYS_TitleY);

    lcd.drawFastHLine(
        20,
        48, // atas ke bawah 237
        440,
        TFT_DARKGREY);

    //=========================
    // Section Title
    //=========================
    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        TFT_DARKGREY,
        Theme::Background);

    lcd.drawString(
        "Hardware",
        Layout::SYS_LabelX,
        Layout::SYS_HardwareY);

    lcd.drawString(
        "Network",
        Layout::SYS_LabelX,
        Layout::SYS_NetworkY);

    lcd.drawString(
        "Runtime",
        Layout::SYS_LabelX,
        Layout::SYS_RuntimeY);

    //=========================
    // Label
    //=========================
    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawString(
        "CPU",
        Layout::SYS_LabelX,
        Layout::SYS_CPUY);

    lcd.drawString(
        "Heap",
        Layout::SYS_LabelX,
        Layout::SYS_HeapY);

    lcd.drawString(
        "PSRAM",
        Layout::SYS_LabelX,
        Layout::SYS_PSRAMY);

    lcd.drawString(
        "Flash",
        Layout::SYS_LabelX,
        Layout::SYS_FlashY);

    lcd.drawString(
        "WiFi",
        Layout::SYS_LabelX,
        Layout::SYS_WiFiY);

    lcd.drawString(
        "IP",
        Layout::SYS_LabelX,
        Layout::SYS_IPY);

    lcd.drawString(
        "Uptime",
        Layout::SYS_LabelX,
        Layout::SYS_UptimeY);

    drawBack(lcd);
}

void SystemScreen::update(LGFX &lcd)
{
    static uint32_t lastUpdate = 0;

    if (millis() - lastUpdate < 1000)
        return;

    lastUpdate = millis();

    lcd.setFont(&fonts::Font2);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    constexpr int VALUE_X = Layout::SYS_ValueRightX;
    constexpr int VALUE_WIDTH = 120;
    constexpr int VALUE_HEIGHT = 18;

    // =========================
    // CPU
    // =========================
    lcd.fillRect(
        VALUE_X - VALUE_WIDTH,
        Layout::SYS_CPUY,
        VALUE_WIDTH,
        VALUE_HEIGHT,
        Theme::Background);

    lcd.drawRightString(
        String(getCpuFrequencyMhz()) + " MHz",
        VALUE_X,
        Layout::SYS_CPUY);

    // =========================
    // Heap
    // =========================
    lcd.fillRect(
        VALUE_X - VALUE_WIDTH,
        Layout::SYS_HeapY,
        VALUE_WIDTH,
        VALUE_HEIGHT,
        Theme::Background);

    lcd.drawRightString(
        String(appState.freeHeap) + " KB",
        VALUE_X,
        Layout::SYS_HeapY);

    // =========================
    // PSRAM
    // =========================
    lcd.fillRect(
        VALUE_X - VALUE_WIDTH,
        Layout::SYS_PSRAMY,
        VALUE_WIDTH,
        VALUE_HEIGHT,
        Theme::Background);

    lcd.drawRightString(
        String(appState.psramSize) + " MB",
        VALUE_X,
        Layout::SYS_PSRAMY);

    // =========================
    // Flash
    // =========================
    lcd.fillRect(
        VALUE_X - VALUE_WIDTH,
        Layout::SYS_FlashY,
        VALUE_WIDTH,
        VALUE_HEIGHT,
        Theme::Background);

    lcd.drawRightString(
        String(appState.flashSize) + " MB",
        VALUE_X,
        Layout::SYS_FlashY);

    // =========================
    // WiFi
    // =========================
    lcd.fillRect(
        VALUE_X - VALUE_WIDTH,
        Layout::SYS_WiFiY,
        VALUE_WIDTH,
        VALUE_HEIGHT,
        Theme::Background);

    lcd.drawRightString(
        appState.wifiConnected
            ? "Connected"
            : "Disconnected",
        VALUE_X,
        Layout::SYS_WiFiY);

    // =========================
    // IP
    // =========================
    lcd.fillRect(
        VALUE_X - VALUE_WIDTH,
        Layout::SYS_IPY,
        VALUE_WIDTH,
        VALUE_HEIGHT,
        Theme::Background);

    lcd.drawRightString(
        appState.ipAddress,
        VALUE_X,
        Layout::SYS_IPY);

    // =========================
    // Uptime
    // =========================
    lcd.fillRect(
        VALUE_X - VALUE_WIDTH,
        Layout::SYS_UptimeY,
        VALUE_WIDTH,
        VALUE_HEIGHT,
        Theme::Background);

    uint32_t sec = millis() / 1000;

    uint32_t hour = sec / 3600;
    uint32_t minute = (sec % 3600) / 60;
    uint32_t second = sec % 60;

    char uptime[16];

    snprintf(
        uptime,
        sizeof(uptime),
        "%02lu:%02lu:%02lu",
        hour,
        minute,
        second);

    lcd.drawRightString(
        uptime,
        VALUE_X,
        Layout::SYS_UptimeY);
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

void SystemScreen::drawBack(LGFX &lcd)
{
    lcd.drawFastHLine(
        20,
        Layout::SYS_LineY,
        440,
        TFT_DARKGREY);

    lcd.setTextColor(
        Theme::White,
        Theme::Background);

    lcd.drawString(
        "< Dashboard",
        Layout::SYS_BackX,
        Layout::SYS_BackY);
}