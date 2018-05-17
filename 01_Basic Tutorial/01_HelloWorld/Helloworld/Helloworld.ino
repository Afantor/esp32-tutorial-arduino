/*
  Helloworld

  This example code is in the public domain.

  http://
*/


// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // serial print hello world.
  Serial.println("Hello world!");
}

// the loop routine runs over and over again forever:
void loop() 
{
  Serial.println("Hello world!");
  delay(2000);
}
