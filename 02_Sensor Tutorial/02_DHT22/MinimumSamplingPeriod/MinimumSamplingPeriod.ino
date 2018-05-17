#include "DHTesp.h"
DHTesp dht;
void setup()
{
  Serial.begin(115200);
  dht.setup(27);
  Serial.print("Minimum Sampling Period: ");
  Serial.println(dht.getMinimumSamplingPeriod());
}
void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  float temperature = dht.getTemperature(); 
  Serial.println("------------------");
  Serial.print("Temperature: ");
  Serial.println(temperature);
}
