#include "DHTesp.h"

DHTesp dht;
void setup()
{
  Serial.begin(115200);
  dht.setup(27);
}
void loop()
{
  float temperature = dht.getTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  delay(10000);
}
 
