/*
  Serial for UART1

  This example code is in the public domain.

  http://www.afantor.cc
*/

HardwareSerial Serial1(1);

int8_t U1rxPin = 16;
int8_t U1txPin = 4;

char inByte = 0;         // incoming serial byte
// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 115200 bits per second:
  Serial1.begin(115200,SERIAL_8N1,U1rxPin,U1txPin);
  while (!Serial1) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // serial print hello world.
  Serial1.println("Hello world!");
}

// the loop routine runs over and over again forever:
void loop() 
{
  // print out the value if Serial available.
  if (Serial1.available() > 0) 
  {
    // get incoming byte:
    inByte = Serial1.read();
    // send back values:
    Serial1.write(inByte);
  }
}
