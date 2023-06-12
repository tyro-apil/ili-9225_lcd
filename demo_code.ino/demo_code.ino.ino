#include "SPI.h"
#include "TFT_22_ILI9225.h"

#define TFT_RST A4
#define TFT_RS  A3
#define TFT_CS  A5  // SS
#define TFT_SDI A2  // MOSI
#define TFT_CLK A1  // SCK
#define TFT_LED 0   // 0 if wired to +5V directly

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);

float num = 123.456786;

void setup()
{
  tft.begin();
  tft.fillRectangle(0, 0, tft.maxX()-1, tft.maxY()-1, COLOR_WHITE);
  tft.setBackgroundColor(COLOR_WHITE);
  tft.setOrientation(3);
}

void loop()
{
  tft.setFont(Terminal6x8);
  tft.drawText(0, 20, "LVL1 = " + String(num), COLOR_BLACK);

  tft.setFont(Terminal11x16);
  tft.drawText(20, 50, "LVL2 = " + String(num), COLOR_ORANGE);

  tft.setFont(Terminal12x16);
  tft.drawText(40, 150, "LVL3 = " + String(num), COLOR_ORANGE);
}

