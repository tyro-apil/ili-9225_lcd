#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include "crc.hpp"

#define TFT_RST A4
#define TFT_RS A3
#define TFT_CS A5  // SS
#define TFT_SDI A2 // MOSI
#define TFT_CLK A1 // SCK
#define TFT_LED 0  // 0 if wired to +5V directly

enum orientation{
  portrait=0, right_landscape, reverse_portrait, left_landscape
};

// Communication
#define SIZE 10
#define DELIMITER 0x41

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);

uint8_t BUFFER[SIZE];
float f1, f2;
int poly = 8;
CRC_Hash uart_lcd_crc(poly);

int receive_data(char *);
void parse_data(float&, float &);
int crc_check(uint8_t*, uint16_t);
void print_data(float&, float&);

void setup()
{
  // Initialise Serial
  Serial1.begin(9600);
  Serial.begin(9600);

  tft.begin();
  tft.fillRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_WHITE);
  tft.setBackgroundColor(COLOR_WHITE);
  tft.setOrientation(right_landscape);
}

void loop()
{
  if (receive_data(BUFFER)){
    Serial.println("Delimiter mismatched!");
  }
  else{
    if (crc_check(BUFFER, SIZE)){
      Serial.println("Checksum error");
    }
    else{
      parse_data(f1, f2, BUFFER);
      print_data(f1, f2);
    }
  }
  print_data(&f1, &f2);
}

// user-defined functions
int receive_data(uint8_t *buff)
{
  int i = 0;
  if (Serial1.available())
  {
    *buff = Serial1.read();
    ++i;
  }
  if (*buff != DELIMITER)
  {
    return 1;
  }
  while (Serial1.available() > 0 && i <= 9)
  {
    *(buff + i) = Serial1.read();
    ++i;
  }
  return 0;
}

void parse_data(float &f1, float &f2, uint8_t *buff)
{
  f1 = *(float *)(buff + 1);
  f2 = *(float *)(buff + 1 + sizeof(float));
}

void print_data(float& float1, float& float2)
{
  tft.setFont(Terminal11x16);
  tft.drawText(0, 0, String(*float1), COLOR_ORANGE);

  tft.setFont(Terminal11x16);
  tft.drawText(0, 40, String(*float2), COLOR_ORANGE);
}

int crc_check(uint8_t* buff, uint16_t len)
{
  if (uart_lcd_crc.get_Hash(buff, len) != buff[len - 1])
  {
    return 1;
  }
  return 0;
}
