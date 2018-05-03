/*
  Serial for UART0

  This example code is in the public domain.

  http://
*/


char inByte = 0;         // incoming serial byte
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
  // print out the value if Serial available.
  if (Serial.available() > 0) 
  {
    // get incoming byte:
    inByte = Serial.read();
    // send back values:
    Serial.write(inByte);
  }
}
