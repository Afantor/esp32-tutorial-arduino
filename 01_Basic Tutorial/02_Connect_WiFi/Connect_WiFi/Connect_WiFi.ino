#include <WiFi.h>

const char* ssid = "FAST_HAHA";
const char* password = "15671677156ting";

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid,password);
    while(WiFi.status() != WL_CONNECTED){
        // statement
        delay(500);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to the WiFi network");

}

void loop()
{
    
}