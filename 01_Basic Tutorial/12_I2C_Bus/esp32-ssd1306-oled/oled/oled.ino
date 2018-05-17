#include <Wire.h>
#include "SSD1306.h"


SSD1306  display(0x3c, 21, 22);


void setup()
{
    display.init();
    display.drawString(0, 0, "Hello World");
    display.display();
}

void loop()
{
    display.clear();
    display.drawString(0,0, "Counter: " + String(counter));
    display.display();
    counter ++;
    delay(1000);

}
