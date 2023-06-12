# ili-9225_lcd
- Size : 176 * 220 pixels

## Pin Connections
1. SCK - SPI CLK
2. SDA - SPI MOSI
3. CS  - SPI SS
4. RS  - Any GPIO Output
5. RST - Any GPIO Output

## Reference
- TFT_22_ILI9225.h header file 
- [GitHub Library] (https://github.com/Nkawu/TFT_22_ILI9225)

## Workflow
1. ```#include "TFT_22_ILI9225.h"```
2. ```tft.begin()```
3. To set background color :
   >fillRectangle(x_start, y_start, x_end, y_end, Color)
   Eg:
   ```tft.fillRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_BLACK)```
4. To set text background color :
   ```tft.setBackgroundColor(COLOR_BLACK) //same as whole BG for visibility```
5. To set font :
   ```tft.setFont(${FONT_NAME})```
   - Terminal6*8   : Smallest (Not recommended)
   - Terminal11*16 : Medium
   - Terminal12*16 : Largest
6. To write text :
   >drawText(x_point, y_point, String, ${COLOR_NAME})
   

   