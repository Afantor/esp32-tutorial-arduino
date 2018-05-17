#include <SPI.h>
#include <MFRC522.h>
const int resetPin = 22; // Reset pin
const int ssPin = 21;    // Slave select pin
MFRC522 mfrc522 = MFRC522(ssPin, resetPin); // Create instance
void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
}
void loop() {

}
