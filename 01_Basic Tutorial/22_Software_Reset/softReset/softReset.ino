

void setup() 
{
  Serial.begin(115200);
  Serial.println("Restarting in 10 seconds");
  delay(10000);
  ESP.restart();
}


void loop() 
{


}
