#include <base64.h>


void setup()
{
  Serial.begin(115200);
  String toEncode = "Test encoding";
  String encoded = base64::encode(toEncode);
  Serial.println(encoded);
}

void loop() 
{

}
