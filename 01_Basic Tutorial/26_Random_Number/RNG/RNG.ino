void setup() 
{
  Serial.begin(115200);
}
void loop() 
{
  Serial.println("-----------");
  Serial.println(esp_random());
  Serial.println(random(10));
  Serial.println(random(10,20));
  delay(1000);
}
