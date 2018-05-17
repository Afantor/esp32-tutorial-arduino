

void setup() 
{
  Serial.begin(115200);
}
void loop() 
{
    int measurement = 0;
    measurement = hallRead();
    Serial.print("Hall sensor measurement: ");
    Serial.println(measurement); 
    delay(1000);
}
