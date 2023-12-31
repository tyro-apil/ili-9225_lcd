# ili-9225_lcd
- Size : 176 * 220 pixels

## Pin Connections
1. SCK - SPI CLK
2. SDA - SPI MOSI
3. CS  - SPI SS (if multiple slaves) //Else any GPIO Output
4. RS  - Any GPIO Output
5. RST - Any GPIO Output

>For UNO, Mega direct connection: 5V to A5 pins


## Reference
- [ILI9225 Library](https://github.com/Nkawu/TFT_22_ILI9225)

## Workflow
>Install ***TFT_22_ILI9225*** by Nkawu <br>
>Copy ***crc.hpp and crc.cpp*** from robotlib repo & paste to ***Arduino/Libraries*** directory


1. ```#include "TFT_22_ILI9225.h"```
   ```#include "SPI.h```
2. ```tft.begin()```
3. To set background color : <br>
   **fillRectangle(x_start, y_start, x_end, y_end, Color)**<br>
   Eg:<br>
   ```tft.fillRectangle(0, 0, tft.maxX() - 1, tft.maxY() - 1, COLOR_BLACK)```
4. To set text background color :<br>
   ```tft.setBackgroundColor(COLOR_BLACK) //same as whole BG for visibility```
5. To set font :<br>
   ```tft.setFont(${FONT_NAME})```
   - Terminal6x8   : Smallest (Not recommended)
   - Terminal11x16 : Medium
   - Terminal12x16 : Largest
6. To write text :<br>
   ```tft.drawText(x_point, y_point, String, ${COLOR_NAME})```
   
## Useful Tips
1. To convert int and float to string : <br>
   ```String(${NUM}) //precision upto 2 decimal points```
   