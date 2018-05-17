#include "DHTesp.h"
DHTesp dht;
void setup()
{
  Serial.begin(115200);
  dht.setup(27);
}
void loop()
{
  float humidity = dht.getHumidity(); 
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(10000);
}
