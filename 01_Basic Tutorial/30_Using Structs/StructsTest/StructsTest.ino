

struct sensor {
  int deviceId;
  int measurementType;
  float value;
};
 
void setup() 
{
  Serial.begin(115200);
  struct sensor mySensor;
  mySensor.deviceId = 944;
  mySensor.measurementType = 1;
  mySensor.value = 20.4;
  Serial.println(mySensor.deviceId);
  Serial.println(mySensor.measurementType);
  Serial.println(mySensor.value);
}
 
void loop() {
  
}
