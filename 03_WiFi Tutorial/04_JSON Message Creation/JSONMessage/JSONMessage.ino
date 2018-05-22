#include <ArduinoJson.h>

void setup() 
{
  Serial.begin(115200);
  Serial.println();
}

void loop() 
{
  Serial.println("—————");
  StaticJsonBuffer<300> JSONbuffer;
  JsonObject& JSONencoder = JSONbuffer.createObject();
  JSONencoder["sensorType"] = "Temperature";
  JsonArray& values = JSONencoder.createNestedArray("values");
  values.add(20);
  values.add(21);
  values.add(23);
  int lenghtSimple = JSONencoder.measureLength();
  Serial.print("Less overhead JSON message size: ");
  Serial.println(lenghtSimple);
  int lenghtPretty = JSONencoder.measurePrettyLength();
  Serial.print("Pretty JSON message size: ");
  Serial.println(lenghtPretty);
  Serial.println();
  Serial.println("Less overhead JSON message: ");
  JSONencoder.printTo(Serial);
  Serial.println();
  Serial.println("\nPretty JSON message: ");
  JSONencoder.prettyPrintTo(Serial);
  Serial.println();
  Serial.println("\nPretty JSON message from buffer: ");
  char JSONmessageBuffer[300];
  JSONencoder.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  Serial.println(JSONmessageBuffer);
  Serial.println();
  delay(10000);
}
