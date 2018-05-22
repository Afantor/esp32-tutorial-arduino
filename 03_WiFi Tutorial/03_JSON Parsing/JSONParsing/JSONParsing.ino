#include <ArduinoJson.h>

void setup() 
{
  Serial.begin(115200);
  Serial.println();
}

void loop() 
{
  Serial.println("Parsing start: ");
  char JSONMessage[] = " {\"SensorType\": \"Temperature\", \"Value\": 10}"; //Original message
  StaticJsonBuffer<300> JSONBuffer;     //Memory pool
  JsonObject& parsed = JSONBuffer.parseObject(JSONMessage); //Parse message

  if (!parsed.success()) {   //Check for errors in parsing
    Serial.println("Parsing failed");
    delay(5000);
    return;
  }
  
  const char * sensorType = parsed["SensorType"]; //Get sensor type value
  int value = parsed["Value"];  //Get value of sensor measurement
  Serial.print("Sensor type: ");
  Serial.println(sensorType);
  Serial.print("Sensor value: ");
  Serial.println(value);
  Serial.println();
  delay(5000);
}
