#include <WiFi.h>
#include <FS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
const char* ssid = "YourNetworkName";
const char* password = "YourNetworkPassword";
AsyncWebServer server(80);
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP());
  server.on("/post", HTTP_POST, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Post route");
  });
  server.on("/put", HTTP_PUT, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Put route");
  });
  server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Get route");
  });
  server.on("/any", HTTP_ANY, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Any route");
  });
  server.begin();
}
void loop(){
}
