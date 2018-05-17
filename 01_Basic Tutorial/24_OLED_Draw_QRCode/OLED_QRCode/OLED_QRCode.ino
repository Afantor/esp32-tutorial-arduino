#include <Wire.h>
#include "SSD1306.h"
#include <qrcode.h>


SSD1306 display(0x3c, 21, 22);

QRcode qrcode (&display);

void setup()
{
  display.init();
  display.display();
  qrcode.init();
  qrcode.create("Hello from esp32");
}

void loop() 
{
    
}
