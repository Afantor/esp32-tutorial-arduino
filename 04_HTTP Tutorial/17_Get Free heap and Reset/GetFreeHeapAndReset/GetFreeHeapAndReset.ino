#include "WiFi.h"
#include "FS.h"
#include "AsyncTCP.h"
#include "ESPAsyncWebServer.h"
const char* ssid = "yourNetworkName";
const char* password = "yourNetworkPassword";
AsyncWebServer server(80);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
   }
  Serial.println(WiFi.localIP());
  server.on("/heap", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(ESP.getFreeHeap()) );
  });
  server.on("/reset", HTTP_POST, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain","ok");
    delay(2000);
    ESP.restart();
  });
  server.begin();
}
 
void loop(){}
